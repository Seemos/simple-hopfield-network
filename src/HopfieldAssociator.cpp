#include <vector>
#include <random>
#include "HopfieldAssociator.hpp"

HopfieldAssociator::HopfieldAssociator(const std::vector<std::vector<int>> &patterns){
    // general setup
    storageSize = patterns.size();
    patternSize = patterns[0].size();
    weights.resize(patternSize);
    for(unsigned i = 0; i < patternSize; i++){
        weights[i].resize(patternSize);
    }

    // weightcalculation
    for(unsigned i = 0; i < patternSize; i++){
        for(unsigned j = i+1; j < patternSize; j++){
            int w = 0;
            for(unsigned k = 0; k < storageSize; k++){
                w += patterns[k][i]*patterns[k][j];
            }
            weights[i][j] = w;
            weights[j][i] = w;
        }
    }
}

std::vector<int> HopfieldAssociator::associate(std::vector<int> &pattern, unsigned iterations){
    std::random_device                  device;
    std::mt19937                        generator(device());
    std::uniform_int_distribution<int>  distribution(0, patternSize-1);
    if(isSeeded) generator.seed(seed);
    for(unsigned iter = 0; iter < iterations; iter++){
        int x = 0;
        int i = distribution(generator);
        for(unsigned j = 0; j < patternSize; j++){
            x += weights[i][j]*pattern[j];
        }
        pattern[i] = x < 0 ? -1 : 1;
    }
    return pattern;
}

unsigned HopfieldAssociator::getPatternSize() const{
    return patternSize;
}

unsigned HopfieldAssociator::getStorageSize() const{
    return storageSize;
}

int HopfieldAssociator::getSeed() const{
    return seed;
}

bool HopfieldAssociator::usesSeed() const{
    return isSeeded;
}

void HopfieldAssociator::setSeed(int seed){
    this->seed = seed;
    isSeeded = true;
}
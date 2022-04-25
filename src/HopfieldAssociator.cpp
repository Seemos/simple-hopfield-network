#include <vector>
#include <random>
#include "HopfieldAssociator.hpp"

HopfieldAssociator::HopfieldAssociator(std::vector<std::vector<int>> patterns){
    // general setup
    storageSize = patterns.size();
    patternSize = patterns[0].size();
    weights.resize(patternSize);
    for(unsigned i = 0; i < patternSize; i++){
        weights[i].resize(patternSize);
    }

    // weightcalculation
    for(int i = 0; i < patternSize; i++){
        for(int j = i+1; j < patternSize; j++){
            int w = 0;
            for(int k = 0; k < storageSize; k++){
                w += patterns[k][i]*patterns[k][j];
            }
            weights[i][j] = w;
            weights[j][i] = w;
        }
    }
}

std::vector<int> HopfieldAssociator::associate(std::vector<int> pattern, unsigned iterations){
    std::random_device                  device;
    std::mt19937                        generator(device());
    std::uniform_int_distribution<int>  distribution(0, patternSize-1);
    for(unsigned iter = 0; iter < iterations; iter++){
        int x = 0;
        int i = distribution(generator);
        for(int j = 0; j < patternSize; j++){
            //printf("%i\n", i);
            x += weights[i][j]*pattern[j];
        }
        pattern[i] = x < 0 ? -1 : 1;
    }
    return pattern;
}

unsigned HopfieldAssociator::getPatternSize(){
    return patternSize;
}

unsigned HopfieldAssociator::getStorageSize(){
    return storageSize;
}
#include <vector>
#include <random>
#include <bits/stdc++.h>
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
    bool wasUpdated;
    int indices[patternSize];
    for(int i = 0; i < patternSize; i++){
        indices[i] = i;
    }

    if(isSeeded) generator.seed(seed);
    do{
        wasUpdated = false;
        std::shuffle(indices, indices+patternSize, generator);
        for(int k = 0; k < patternSize; k++){
            int x = 0;
            int i = indices[k];
            for(unsigned j = 0; j < patternSize; j++){
                x += weights[i][j]*pattern[j];
            }
            x = x < 0 ? -1 : 1;
            if(pattern[i] != x){
                pattern[i] = x;
                wasUpdated = true;
            }
        }
    }while (wasUpdated);
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
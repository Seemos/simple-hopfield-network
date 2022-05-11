#include <iostream>
#include <vector>
#include "HopfieldAssociator.hpp"


void printPattern(const std::vector<int> &pattern, unsigned rows, unsigned cols){
    for(unsigned i = 0; i < rows; i++){
        for(unsigned j = 0; j < cols; j++){
            printf(pattern[i*rows+j] == 1 ? "#" : "_");
        }
        printf("\n");
    }
}

int main()
{
    std::vector<std::vector<int>> patterns = {
        {
            // T-Pattern
             1, 1, 1, 1, 1,
            -1,-1, 1,-1,-1,
            -1,-1, 1,-1,-1,
            -1,-1, 1,-1,-1,
            -1,-1, 1,-1,-1
        },
        {
            // S-Pattern
             1, 1, 1, 1,-1,
             1,-1,-1,-1,-1,
             1, 1, 1, 1, 1,
            -1,-1,-1,-1, 1,
            -1, 1, 1, 1, 1
        },
        {
            // X-Pattern
             1,-1,-1,-1, 1,
            -1, 1,-1, 1,-1,
            -1,-1, 1,-1,-1,
            -1, 1,-1, 1,-1,
             1,-1,-1,-1, 1
        }
    };

    std::vector<std::vector<int>> noised ={
        {
            // T-Pattern with noise
             1,-1, 1,-1, 1,
            -1,-1, 1, 1,-1,
            -1,-1, 1,-1,-1,
            -1, 1,-1,-1,-1,
            -1,-1, 1,-1,-1
        },
        {
            // S-Pattern with noise
             1, 1, 1,-1, 1,
             1,-1,-1,-1,-1,
             1, 1, 1, 1,-1,
            -1, 1,-1, 1, 1,
            -1, 1, 1, 1, 1
        },
        {
            // X-Pattern with noise
             1,-1,-1,-1,-1,
            -1, 1,-1, 1, 1,
            -1, 1, 1,-1,-1,
            -1, 1,-1, 1,-1,
            -1,-1,-1,-1, 1
        }
    };

    HopfieldAssociator ha(patterns);
    ha.setSeed(42);

    printf("-------------------\n");
    printf("Storage size: %i\n",ha.getStorageSize());
    printf("Pattern size: %i\n", ha.getPatternSize());
    printf("Threshold: %lf\n", ha.getThreshold());
    printf("Uses Seed: %s\n", ha.usesSeed() ? "true" : "false");
    printf("Seed: %i\n", ha.getSeed());
    printf("-------------------\n");

    for(auto &pattern : noised){
        printf("From:\n");
        printPattern(pattern,5,5);
        const auto associated = ha.associate(pattern);
        printf("\nTo:\n");
        printPattern(associated,5,5);
        printf("\n\n\n");
    }
    return 0;
}
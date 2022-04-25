#include <iostream>
#include <vector>
#include "HopfieldAssociator.hpp"

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
    printf("Storage size: %i\n",ha.getStorageSize());
    printf("Pattern size: %i\n", ha.getPatternSize());
    for(auto pattern : noised){
        pattern = ha.associate(pattern, 100);
        for(auto var : pattern){
            printf("%i,", var);
        }
        printf("\n");
    }
    return 0;
}
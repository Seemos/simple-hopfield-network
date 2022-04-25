#include <iostream>
#include <vector>
#include "HopfieldAssociator.hpp"


void printPattern(std::vector<int> pattern, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
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
    printf("----------------\n");
    printf("Storage size: %i\n",ha.getStorageSize());
    printf("Pattern size: %i\n", ha.getPatternSize());
    printf("----------------\n");
    for(auto pattern : noised){
        printf("From:\n");
        printPattern(pattern,5,5);
        pattern = ha.associate(pattern, 50);
        printf("\nTo:\n");
        printPattern(pattern,5,5);
        printf("\n\n\n");
    }
    return 0;
}
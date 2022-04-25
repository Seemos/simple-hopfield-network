#include <vector>

#ifndef HOPFIELD_ASSOCIATOR_HPP
#define HOPFIELD_ASSOCIATOR_HPP

class HopfieldAssociator{
    private:
        unsigned patternSize;
        unsigned storageSize;
        std::vector<std::vector<int>> weights;

    public:
        HopfieldAssociator(std::vector<std::vector<int>> patterns);
        std::vector<int> associate(std::vector<int> pattern, unsigned iterations);

        unsigned getPatternSize();
        unsigned getStorageSize();
};

#endif
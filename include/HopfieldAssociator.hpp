#include <vector>

#ifndef HOPFIELD_ASSOCIATOR_HPP
#define HOPFIELD_ASSOCIATOR_HPP

class HopfieldAssociator{
    private:
        bool isSeeded;
        int seed;
        unsigned patternSize;
        unsigned storageSize;
        std::vector<std::vector<int>> weights;

    public:
        HopfieldAssociator(std::vector<std::vector<int>> patterns);
        std::vector<int> associate(std::vector<int> pattern, unsigned iterations);

        unsigned getPatternSize();
        unsigned getStorageSize();
        int getSeed();
        bool usesSeed();
        void setSeed(int seed);
};

#endif
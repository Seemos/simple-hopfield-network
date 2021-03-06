#include <vector>

#ifndef HOPFIELD_ASSOCIATOR_HPP
#define HOPFIELD_ASSOCIATOR_HPP

class HopfieldAssociator{
    private:
        bool isSeeded;
        int seed;
        unsigned patternSize;
        unsigned storageSize;
        double threshold;
        std::vector<std::vector<int>> weights;

    public:
        HopfieldAssociator(const std::vector<std::vector<int>> &patterns, double threshold = 0);
        std::vector<int> associate(std::vector<int> &pattern);

        unsigned getPatternSize() const;
        unsigned getStorageSize() const;
        double getThreshold() const;
        int getSeed() const;
        bool usesSeed() const;
        void setSeed(int seed);
};

#endif
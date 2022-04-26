# simple-hopfield-network
An implementation of a discrete Hopfield network for bipolar pattern association.
The example is built to  memorize three Patterns: X,T and S.
The created network created from the three input patterns is capable of matching noised patterns to the patterns stored in its memory.

## Capabilities and Problems
The example network is capable of correctly associating noised/modified versions of memorized patterns to the corresponding patterns.
Problems arise when a noised pattern is similar to more than one memorized patterns and might be associated with either of them,
depending on the seed used for the random number generator.

# Quick Sort Comparison
1. randomize quick-sort (Prog-1.cpp)
2. median-of-3 partition quick-sort (Prog-2.cpp)
3. Bentley and Mcllroy quick-sort (Prog-3.cpp)

## The run time output are removed from the codes

## run time of sorted test case with 10000 inputs (sorted.txt)
1. randomize quick-sort (Prog-1.cpp): 6
2. median-of-3 partition quick-sort (Prog-2.cpp): 0
3. Bentley and Mcllroy quick-sort (Prog-3.cpp): 1

## run time of random test case with 10000 inputs (random.txt)
1. randomize quick-sort (Prog-1.cpp): 2
2. median-of-3 partition quick-sort (Prog-2.cpp): 1
3. Bentley and Mcllroy quick-sort (Prog-3.cpp): 5

* The sorted test case shows that Prog-1 is much slower, because the run time is n^2.
* When i tried 100000 inputs of sorted test case with Prog-1, the program could'n be finished.
* The Bentley and Mcllroy took longer to run the random test case because the time finding the pivot takes some time when the input size is large.

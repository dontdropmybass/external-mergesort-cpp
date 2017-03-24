//
//  main.cpp
//  data-structures-external-mergesort
//
//  Created by Alexander Cochrane on 2017-03-20.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "sort.hpp"
#define TESTFILE "/Users/alex/repos/data-structures-external-mergesort/temp/text.txt"

int main(int argc, const char * argv[]) {
    
    ExternalMergeSort ems = ExternalMergeSort();
    // randomly generate an array of integers
    ems.randomize(UNSORTED_FILENAME, ARRAY_SIZE);
    
    // alert the user that the mergesort is beginning.
    std::cout << "Beginning external mergesort..." << std::endl;
    clock_t startTime = clock();
    
    ems.start(UNSORTED_FILENAME);
    
    clock_t endTime = clock();
    clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double)CLOCKS_PER_SEC;
    std::cout << "External mergesort complete." << std::endl;
    std::cout << "Time elapsed: " << timeInSeconds << " seconds." << std::endl;
    return 0;
}

//
//  sort.hpp
//  data-structures-external-mergesort
//
//  Created by Alexander Cochrane on 2017-03-20.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
//

#ifndef sort_hpp
#define sort_hpp

#define ARRAY_SIZE 20
#define UNSORTED_FILENAME   "/Users/alex/repos/data-structures-external-mergesort/temp/unsorted.txt"
#define TEMP_DIRECTORY      "/Users/alex/repos/data-structures-external-mergesort/temp/"
#define SORTED_FILENAME     "/Users/alex/repos/data-structures-external-mergesort/temp/sorted.txt"

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

class ExternalMergeSort {
public:
    void start(const char* filename);
    void randomize(const char* filename, int size);
private:
    void merge(const char* inFile1, const char* inFile2, const char* outFile1, const char* outfile2, int runSize);
    void finalMerge(const char* file1, const char* file2);
    bool dankMemes = false;
};
#endif /* sort_hpp */

//
//  sort.cpp
//  data-structures-external-mergesort
//
//  Created by Alexander Cochrane on 2017-03-20.
//  Copyright © 2017 Alexander Cochrane. All rights reserved.
//

#include "sort.hpp"

void ExternalMergeSort::randomize(const char* filename, int size) {
    std::ofstream ofs(filename, std::fstream::out | std::fstream::trunc);
    if (ofs.fail()) {
        throw std::invalid_argument("Invalid file name");
    }
    
    while (size-->0) {
        int n = rand() % 10000 + 1;
        ofs << n << " ";
        std::cout << n << " ";
    }
    std::cout << std::endl << std::endl << std::endl;
    
    ofs.close();
}

void ExternalMergeSort::start(const char* filename) {
    std::ifstream input(filename, std::fstream::in);
    std::ofstream temp1("/Users/alex/repos/data-structures-external-mergesort/temp/temp1.txt",
                        std::fstream::out | std::fstream::trunc);
    std::ofstream temp2("/Users/alex/repos/data-structures-external-mergesort/temp/temp2.txt",
                        std::fstream::out | std::fstream::trunc);
    
    int a;
    bool current = true;
    while (!input.eof()) {
        input >> a;
        
        if (current) {
            temp1 << std::to_string(a) << " ";
        }
        else {
            temp2 << std::to_string(a) << " ";
        }
        
        current = !current;
    }
    
    merge("/Users/alex/repos/data-structures-external-mergesort/temp/temp1.txt",
          "/Users/alex/repos/data-structures-external-mergesort/temp/temp2.txt",
          "/Users/alex/repos/data-structures-external-mergesort/temp/incr1.txt",
          "/Users/alex/repos/data-structures-external-mergesort/temp/incr2.txt",
          2);
    
    if (dankMemes) {
        finalMerge("/Users/alex/repos/data-structures-external-mergesort/temp/temp1.txt",
                   "/Users/alex/repos/data-structures-external-mergesort/temp/temp2.txt");
    }
    else {
        finalMerge("/Users/alex/repos/data-structures-external-mergesort/temp/incr1.txt",
                   "/Users/alex/repos/data-structures-external-mergesort/temp/incr2.txt");

    }
}

void ExternalMergeSort::merge(const char *inFile1, const char *inFile2,
                              const char *outFile1, const char *outFile2, int runSize) {
    if (runSize > ARRAY_SIZE / 2) return; // should be sorted by then
    
    // declare streams
    std::ifstream temp1(inFile1, std::fstream::in);
    std::ifstream temp2(inFile2, std::fstream::in);
    std::ofstream incr1(outFile1, std::fstream::out | std::fstream::trunc);
    std::ofstream incr2(outFile2, std::fstream::out | std::fstream::trunc);
    
    int a,b,i,j;
    bool current = true;
    i = 0;
    j = 0;
    temp1 >> a;
    temp2 >> b;
    
    while (i<runSize/2||j<runSize/2) {
        
        if (i<runSize/2&&j<runSize/2) {
            if (a > b) {
                i++;
                if (current) {
                    incr1 << std::to_string(b) << " ";
                }
                else {
                    incr2 << std::to_string(b) << " ";
                }
                if (!temp2.eof()) {
                    temp2 >> b;
                }
                else {
                    j = runSize;
                }
            }
            else {
                j++;
                if (current) {
                    incr1 << std::to_string(a) << " ";
                }
                else {
                    incr2 << std::to_string(a) << " ";
                }
                if (!temp1.eof()) {
                    temp1 >> a;
                }
                else {
                    i = runSize;
                }
            }
        }
        else if (i<runSize/2) {
            i++;
            if (current) {
                incr1 << std::to_string(a) << " ";
            }
            else {
                incr2 << std::to_string(a) << " ";
            }
            if (!temp1.eof()) {
                temp1 >> a;
            }
            else {
                i = runSize;
            }
        }
        else if (j<runSize/2) {
            j++;
            temp2 >> b;
            if (current) {
                incr1 << std::to_string(b) << " ";
            }
            else {
                incr2 << std::to_string(b) << " ";
            }
            if (!temp2.eof()) {
                temp2 >> b;
            }
            else {
                j = runSize;
            }
        }
        current = !current;
    }
    
    temp1.close();
    temp2.close();
    incr1.close();
    incr2.close();
    
    dankMemes = !dankMemes;
    merge(outFile1, outFile2, inFile1, inFile2, runSize*2);
}

void ExternalMergeSort::finalMerge(const char *file1, const char *file2) {
    std::ifstream in1(file1, std::fstream::in);
    std::ifstream in2(file2, std::fstream::in);
    std::ofstream out(SORTED_FILENAME, std::fstream::out | std::fstream::trunc);
    
    int a,b,i,j;
    i = 0;
    j = 0;
    in1 >> a;
    in2 >> b;
    
    while (i+j<ARRAY_SIZE) {
        
        if (i<ARRAY_SIZE/2&&j<ARRAY_SIZE/2) {
            if (a > b) {
                i++;
                out << std::to_string(b) << " ";
                if (!in2.eof()) {
                    in2 >> b;
                }
                else {
                    j = ARRAY_SIZE/2;
                }
            }
            else {
                j++;
                out << std::to_string(a) << " ";
                if (!in1.eof()) {
                    in1 >> a;
                }
                else {
                    i = ARRAY_SIZE/2;
                }
            }
        }
        else if (i<ARRAY_SIZE/2) {
            i++;
            out << std::to_string(a) << " ";
            if (!in1.eof()) {
                in1 >> a;
            }
            else {
                i = ARRAY_SIZE/2;
            }
        }
        else if (j<ARRAY_SIZE/2) {
            j++;
            in2 >> b;
            out << std::to_string(b) << " ";
            if (!in2.eof()) {
                in2 >> b;
            }
            else {
                j = ARRAY_SIZE/2;
            }
        }
    }
    
    in1.close();
    in2.close();
    out.close();
}

/**
 Lab 6 - Huffman Coding
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file BitWriter.hpp
 @author Russell Taylor
 @date 9/20/20
*/

#ifndef BitWriter_hpp
#define BitWriter_hpp

#include <fstream>
#include "BitData.hpp"
using namespace std;

class BitWriter {
public:
    BitWriter(ofstream& fout);

    void write(const int bit);
    
    void write(const BitData& bitData);
    
private:
    ofstream& fout;
};

#endif /* BitWriter_hpp */

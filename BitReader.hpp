/**
 Lab 6 - Huffman Coding
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file BitReader.hpp
 @author Russell Taylor
 @date 9/20/20
*/

#ifndef BitReader_hpp
#define BitReader_hpp

#include <fstream>
using namespace std;

class BitReader {
public:
    BitReader(ifstream& fin);
    
    int readBit();

private:
    ifstream& fin;
};

#endif /* BitReader_hpp */

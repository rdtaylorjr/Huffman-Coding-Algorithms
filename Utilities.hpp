/**
 Lab 6 - Huffman Coding
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file Utilities.hpp
 @author Russell Taylor
 @date 9/20/20
*/

#ifndef Utilities_hpp
#define Utilities_hpp

#include <fstream>

class Utilities {
public:
    std::ofstream debugStream;
    
    /**
     Formats bytes for output to file
     @param byte the byte to be formatted
     @return the formatted byte
     */
    std::string formatByte(const unsigned char byte);
};

#endif /* Utilities_hpp */

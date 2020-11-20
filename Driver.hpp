/**
 Lab 6 - Huffman Coding
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file Driver.hpp
 @author Russell Taylor
 @date 9/20/20
*/

#ifndef Driver_hpp
#define Driver_hpp

#include <iostream>
#include "HuffmanCodec.hpp"

class Driver {
public:
    /**
     Constructs a Driver object
     @param utilities miscellaneous utilities for output to the debug file stream and formatting bytes
     */
    Driver(Utilities* utilities);
    
    /**
     Tests files
     @param file the file number
     */
    void testFile(int file);

private:
    Utilities* utilities;
    
    /**
     Tests encoding
     @param huffmanCodec the HuffmanCodec object
     @param inputFile the input file name
     @param encodedFile the encoded file name
     */
    void testEncoding(HuffmanCodec& huffmanCodec, const string& inputFile, const string& encodedFile);

    /**
     Tests decoding
     @param huffmanCodec the HuffmanCodec object
     @param encodedFile the encoded file name
     @param decodedFile the decoded file name
     */
    void testDecoding(HuffmanCodec& huffmanCodec, const string& encodedFile, const string& decodedFile);

    /**
     Compares files to determine whether they are the same
     @param firstFile the name of the first file to be compared
     @param secondFile the name of the second file to be compared
     */
    void compareFiles(const string& firstFile, const string& secondFile);
};

#endif /* Driver_hpp */

/**
 Lab 6 - Huffman Coding
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file HuffmanCodec.hpp
 @author Russell Taylor
 @date 9/20/20
*/

#ifndef HuffmanCodec_hpp
#define HuffmanCodec_hpp

#include <fstream>
#include "HuffmanAlgorithm.hpp"

class HuffmanCodec {
public:
    /**
     Constructs a HuffmanCodec object
     @param utilities miscellaneous utilities for output to the debug file stream and formatting bytes
     */
    HuffmanCodec(Utilities* utilities);
    
    /**
     Imports and counts file data one byte at a time
     @param fin the input file stream
     */
    void countData(ifstream& fin);
    
    /**
     Imports and encodes file data one byte at a time
     @param fin the input file stream
     @param fout the output file stream
     */
    void encodeData(ifstream& fin, ofstream& fout);
    
    /**
     Imports and decodes file data one byte at a time
     @param fin the input file stream
     @param fout the output file stream
     */
    void decodeData(ifstream& fin, ofstream& fout);
    
    /**
     Calls methods to sort the data by frequency, create a Huffman tree, and create an encoding table based on the Huffman tree
     */
    void createHuffmanTree();
    
private:
    Utilities* utilities;
    HuffmanAlgorithm huffmanAlgorithm;
};

#endif /* HuffmanCodec_hpp */











///**
// Encodes data from an input file, outputs the encoded data to an output file
// @param fin the input file stream
// @param fout the output file stream
// */
//void encodeStream(ifstream& fin, ofstream& fout);
//
///**
// Decodes data from an input file, outputs the decoded data to an output file
// @param fin the input file stream
// @param fout the output file stream
// */
//void decodeStream(ifstream& fin, ofstream& fout);
//
///**
// Imports data from file
// @param fin the input file stream
// */
//void importData(ifstream& fin);
//
///**
// Imports data from file
// @param fin the input file stream
// */
//void importData(ifstream& fin, ofstream& fout);



///**
// Imports data from file
// @param fin the input file stream
// */
//void importData(ifstream& fin);

//    vector<unsigned char> fileData;

/**
 Lab 6 - Huffman Coding
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file HuffmanCodec.cpp
 @author Russell Taylor
 @date 9/20/20
*/

#include "HuffmanCodec.hpp"

/**
 Constructs a HuffmanCodec object
 @param utilities miscellaneous utilities for output to the debug file stream and formatting bytes
 */
HuffmanCodec::HuffmanCodec(Utilities* utilities) : utilities(utilities), huffmanAlgorithm(utilities) {
}

/**
 Imports and counts file data one byte at a time
 @param fin the input file stream
 */
void HuffmanCodec::countData(ifstream& fin) {
    while (true) {
        unsigned char byte;

        fin.read((char*) &byte, 1);
        
        if (fin.eof())
            break;
        
        huffmanAlgorithm.countByte(byte);
    }
    fin.clear();
    fin.seekg(0);
}

/**
 Imports and encodes file data one byte at a time
 @param fin the input file stream
 @param fout the output file stream
 */
void HuffmanCodec::encodeData(ifstream& fin, ofstream& fout) {
    while (true) {
        unsigned char byte;

        fin.read((char*) &byte, 1);
        
        if (fin.eof())
            break;

        fout << huffmanAlgorithm.encodeByte(byte);
    }
}

/**
 Imports and decodes file data one byte at a time
 @param fin the input file stream
 @param fout the output file stream
 */
void HuffmanCodec::decodeData(ifstream& fin, ofstream& fout) {
    const HuffmanTree<int>* current;
    bool complete = true;
    
    while (true) {
        unsigned char bit, byte;

        fin.read((char*) &bit, 1);
        
        if (fin.eof())
            break;
        
        huffmanAlgorithm.decodeByte(bit, byte, complete, current);
        if (complete)
            fout << byte;
    }
}

/**
 Calls methods to sort the data by frequency, create a Huffman tree, and create an encoding table based on the Huffman tree
 */
void HuffmanCodec::createHuffmanTree() {
    huffmanAlgorithm.createPriorityQueue();
    huffmanAlgorithm.createHuffmanTree();
    huffmanAlgorithm.createEncodingTable();
}

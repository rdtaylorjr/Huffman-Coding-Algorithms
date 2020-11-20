/**
 Lab 6 - Huffman Coding
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file BitReader.cpp
 @author Russell Taylor
 @date 9/20/20
*/

#include "BitReader.hpp"

BitReader::BitReader(ifstream& fin) : fin(fin) {
}

int BitReader::readBit() {
    char bit;
    fin >> bit;

    if (fin)
        return (bit == '0' ? 0 : 1);
    else
        return - 1;
}

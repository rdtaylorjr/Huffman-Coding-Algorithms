/**
 Lab 6 - Huffman Coding
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file BitWriter.cpp
 @author Russell Taylor
 @date 9/20/20
*/

#include "BitWriter.hpp"

BitWriter::BitWriter(ofstream& fout) : fout(fout) {
}

void BitWriter::write(const int bit) {
    fout << (bit ? '1' : '0');
}

void BitWriter::write(const BitData& bitData) {
    if (bitData.size() == 0)
        throw runtime_error("BitData size is 0");

    for (int i = 0; i < bitData.size(); ++i)
        write(bitData.at(i));
}

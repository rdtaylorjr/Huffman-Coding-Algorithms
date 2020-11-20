/**
 Lab 6 - Huffman Coding
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file main.cpp
 @author Russell Taylor
 @date 9/20/20
 
 Based on provided pseudocode
 Encodes and decodes text from input files using Huffman coding. Reads mutiple input files a byte at a time, counts the number occurrences of each byte, sorts the bytes by frequency, builds a Huffman tree, generates an encoding for each byte, reads and encodes the file data, outputes the encoded file data, reads and decodes the encoded file data, outputs the decoded file data, then compares the decoded file with the original input file.
 
 @pre Multiple input files containing text or other bytes of data
 @post A text file containing the data after it has been encoded, a text file containing the data after it has been decoded, and text file containing debug information
*/

#include "Driver.hpp"

/**
 Controls operation of the program
 */
int main(int argc, const char * argv[]) {
    Utilities utilities;
    Driver driver(&utilities);
    try {
        for (int i = 1; i <= 11; ++i)
            driver.testFile(i);
    }
    catch (const exception& ex) {
        if (utilities.debugStream)
            utilities.debugStream << "Exception:" << ex.what() << "\n";
        cout << "Exception:" << ex.what() << "\n";
    }
    return 0;
}

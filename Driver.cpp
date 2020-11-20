/**
 Lab 6 - Huffman Coding
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file Driver.cpp
 @author Russell Taylor
 @date 9/20/20
*/

#include "Driver.hpp"

/**
 Constructs a Driver object
 @param utilities miscellaneous utilities for output to the debug file stream and formatting bytes
 */
Driver::Driver(Utilities* utilities) : utilities(utilities) {
}

/**
 Tests files
 @param file the file number
 */
void Driver::testFile(int file) {
    const string& number = to_string(file);
    const string& debugFile = number + "_debug.txt";
    const string& inputFile = number + "_in.txt";
    const string& encodedFile = number + "_encoded.txt";
    const string& decodedFile = number + "_decoded.txt";
   
    utilities->debugStream.open(debugFile);

    cout << "*** Testing file " << inputFile << ", debug output file " << debugFile << " ***\n" << flush;
    
    HuffmanCodec huffmanCodec(utilities);

    testEncoding(huffmanCodec, inputFile, encodedFile);
    testDecoding(huffmanCodec, encodedFile, decodedFile);
    compareFiles(inputFile, decodedFile);

    utilities->debugStream << "\n!!! Files " << inputFile << " and " << decodedFile << " are equal.\n";
    utilities->debugStream.close();

    cout << "\nOK\n\n" << flush;
}

/**
 Tests encoding
 @param huffmanCodec the HuffmanCodec object
 @param inputFile the input file name
 @param encodedFile the encoded file name
 */
void Driver::testEncoding(HuffmanCodec& huffmanCodec, const string& inputFile, const string& encodedFile) {
    ifstream fin(inputFile, ios::binary);
    if (!fin)
        throw runtime_error("Cannot open file " + inputFile + " for reading");
    ofstream fout(encodedFile);
    if (!fout)
        throw runtime_error("Cannot open file " + encodedFile + " for writing");

    utilities->debugStream << "Encoding " << inputFile << " -> " << encodedFile << "\n\n" << flush;

    huffmanCodec.countData(fin);
    huffmanCodec.createHuffmanTree();
    huffmanCodec.encodeData(fin, fout);

    fin.close();
    fout.close();
}

/**
 Tests decoding
 @param huffmanCodec the HuffmanCodec object
 @param encodedFile the encoded file name
 @param decodedFile the decoded file name
 */
void Driver::testDecoding(HuffmanCodec& huffmanCodec, const string& encodedFile, const string& decodedFile) {
    ifstream fin(encodedFile);
    if (!fin)
        throw runtime_error("Cannot open file " + encodedFile + " for reading");

    ofstream fout(decodedFile, ios::binary);
    if (!fout)
        throw runtime_error("Cannot open file " + decodedFile + " for writing");

    utilities->debugStream << "Decoding " << encodedFile << " -> " << decodedFile << "\n" << flush;

    huffmanCodec.decodeData(fin, fout);

    fin.close();
    fout.close();
}

/**
 Compares files to determine whether they are the same
 @param firstFile the name of the first file to be compared
 @param secondFile the name of the second file to be compared
 */
void Driver::compareFiles(const string& firstFile, const string& secondFile) {
    ifstream fin1(firstFile, ios::binary);
    ifstream fin2(secondFile, ios::binary);

    if (!fin1)
        throw runtime_error("Cannot open file " + firstFile + " for reading");
    if (!fin2)
        throw runtime_error("Cannot open file " + secondFile + " for reading");

    int blockCount = 0;
    const int BLOCKSIZE = 1024;
    char buffer1[BLOCKSIZE];
    char buffer2[BLOCKSIZE];

    while(true) {
        const int length1 = int(fin1.read(buffer1, BLOCKSIZE).gcount());
        const int length2 = int(fin2.read(buffer2, BLOCKSIZE).gcount());
        
        if (length1 != length2)
            throw runtime_error(string("Sizes of the files are different") + ", file " + firstFile  + " has size " + to_string(length1 + BLOCKSIZE * blockCount) + ", file " + secondFile + " has size " + to_string(length2 + BLOCKSIZE * blockCount));

        for (int i = 0; i < length1; ++i)
            if (buffer1[i] != buffer2[i])
                throw runtime_error("Files are different at position " + to_string(i + BLOCKSIZE * blockCount) + ", file " + firstFile  + " has character " + utilities->formatByte(buffer1[i]) + ", file " + secondFile + " has character " + utilities->formatByte(buffer2[i]));

        if (length1 == 0)
            break;

        ++blockCount;
    }

    fin1.close();
    fin2.close();
}

/**
 Lab 6 - Huffman Coding
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file HuffmanAlgorithm.hpp
 @author Russell Taylor
 @date 9/20/20
*/

#ifndef HuffmanAlgorithm_hpp
#define HuffmanAlgorithm_hpp

#include <vector>
#include <queue>
#include "HuffmanTree.hpp"
#include "BitData.hpp"
#include "Utilities.hpp"
using namespace std;

auto compare = [] (const HuffmanTree<int>* left, const HuffmanTree<int>* right) { return left->getFrequency() > right->getFrequency() || (left->getFrequency() == right->getFrequency() && left->getByte() > right->getByte()); };

class HuffmanAlgorithm {
public:
    /**
     Constructs a HuffmanAlgorithm object
     @param utilities miscellaneous utilities for output to the debug file stream and formatting bytes
     */
    HuffmanAlgorithm(Utilities* utilities);
    
    /**
     Destructs a HuffmanAlgorithm object
     */
    ~HuffmanAlgorithm();
    
    /**
     Counts each byte by incrementing the corresponding entry in the frequency table
     @param byte the byte to be counted
     */
    void countByte(unsigned char byte);
    
    /**
     Encodes each byte by looking up the corresponding entry in the encoding table
     @param byte the byte to be encoded
     @return the byte's encoding
     */
    string encodeByte(unsigned char byte);

    /**
     Decodes each byte by traversing the Huffman tree
     @param bit a bit which is part of an encoded character
     */
    void decodeByte(unsigned char bit, unsigned char& decoded, bool& complete, const HuffmanTree<int>*& current);
    
    /**
     Sorts the characters by frequency using a priority queue
     */
    void createPriorityQueue();
    
    /**
     Creates a Huffman tree
     */
    void createHuffmanTree();
    
    /**
     Creates an encoding table based on the Huffman tree
     */
    void createEncodingTable();
    
private:
    Utilities* utilities;
    vector<int> frequencyTable;
    priority_queue<const HuffmanTree<int>*, vector<const HuffmanTree<int>*>, decltype(compare)> huffmanQueue;
    const HuffmanTree<int>* huffmanTree;
    vector<string> encodingTable;
    
    /**
     Prints the frequency table
     */
    void printFrequencyTable();
    
    /**
     Print the priority queue
     */
    void printPriorityQueue();
   
    /**
     Prints the encoding table
     */
    void printEncodingTable();
    
    /**
     Traverses the Huffman tree recursively and creates an encoding table
     @param current the current node in the Huffman tree
     @param bitData the encoded path for each leaf node in the Huffman tree
     */
    void traverseTree(const HuffmanTree<int>* current, BitData& bitData);
};

#endif /* HuffmanAlgorithm_hpp */











//    /**
//     Counts the number of times each character occurs in an input file and creates a frequency table
//     @param fileData the input file data
//     */
//    void createFrequencyTable(const vector<unsigned char>& fileData);

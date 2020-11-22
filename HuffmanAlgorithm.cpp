/**
 Lab 6 - Huffman Coding
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file HuffmanAlgorithm.cpp
 @author Russell Taylor
 @date 9/20/20
*/

#include "HuffmanAlgorithm.hpp"

/**
 Constructs a HuffmanAlgorithm object
 @param utilities miscellaneous utilities for output to the debug file stream and formatting bytes
 */
HuffmanAlgorithm::HuffmanAlgorithm(Utilities* utilities) : utilities(utilities), huffmanQueue(compare) {
    huffmanTree = nullptr;
    frequencyTable.resize(256);
    encodingTable.resize(256);
}

/**
 Destructs a HuffmanAlgorithm object
 */
HuffmanAlgorithm::~HuffmanAlgorithm() {
    delete huffmanTree;
}

/**
 Counts each byte by incrementing the corresponding entry in the frequency table
 @param byte the byte to be counted
 */
void HuffmanAlgorithm::countByte(unsigned char byte) {
    ++frequencyTable[byte];
}

/**
 Encodes each byte by looking up the corresponding entry in the encoding table
 @param byte the byte to be encoded
 @return the byte's encoding
 */
string HuffmanAlgorithm::encodeByte(unsigned char byte) {
    return encodingTable[byte];
}

/**
 Decodes each byte by traversing the Huffman tree
 @param bit a bit which is part of an encoded character
 */
void HuffmanAlgorithm::decodeByte(unsigned char bit, unsigned char& decoded, bool& complete, const HuffmanTree<int>*& current) {
    if (complete)
        current = huffmanTree;
    if (!current->isTerminal()) {
        if (bit == '0')
            current = current->getLeft();
        if (bit == '1')
            current = current->getRight();
        complete = false;
    }
    if (current->isTerminal()) {
        decoded = current->getByte();
        complete = true;
    }
}

/**
 Sorts the characters by frequency using a priority queue
 */
void HuffmanAlgorithm::createPriorityQueue() {
    printFrequencyTable();
    
    for (int i = 0; i < frequencyTable.size(); ++i) {
        if (frequencyTable[i] > 0) {
            const HuffmanTree<int>* node = new HuffmanTree<int>(i, frequencyTable[i]);
            huffmanQueue.push(node);
        }
    }
    printPriorityQueue();
}

/**
 Creates a Huffman tree
 */
void HuffmanAlgorithm::createHuffmanTree() {
    while (huffmanQueue.size() > 1) {
        const HuffmanTree<int>* first = huffmanQueue.top();
        huffmanQueue.pop();
        const HuffmanTree<int>* second = huffmanQueue.top();
        huffmanQueue.pop();
        
        const HuffmanTree<int>* node = new HuffmanTree<int>(first, second);
        huffmanQueue.push(node);
    }
    if (!huffmanQueue.empty())
        huffmanTree = huffmanQueue.top();
}

/**
 Creates an encoding table based on the Huffman tree
 */
void HuffmanAlgorithm::createEncodingTable() {
    BitData bitData;
    traverseTree(huffmanTree, bitData);
    printEncodingTable();
}

/**
 Prints the frequency table
 */
void HuffmanAlgorithm::printFrequencyTable() {
    utilities->debugStream << "printFrequencyTable:\n\n";

    for (int i = 0; i < frequencyTable.size(); ++i)
        if (frequencyTable[i] != 0)
            utilities->debugStream << setw(3) << i << " " << utilities->formatByte(i) << " {" << to_string(frequencyTable[i]) << "}\n";
    
    utilities->debugStream << "\n" << flush;
}

/**
 Print the priority queue
 */
void HuffmanAlgorithm::printPriorityQueue() {
    utilities->debugStream << "printQueue:\n\n";
    
    for (priority_queue<const HuffmanTree<int>*, vector<const HuffmanTree<int>*>, decltype(compare)> q = huffmanQueue; !q.empty(); q.pop())
        utilities->debugStream << setw(3) << q.top()->getByte() << " " << utilities->formatByte(q.top()->getByte()) << " {" << to_string(q.top()->getFrequency()) << "}\n";
    
    utilities->debugStream << "\n" << flush;
}

/**
 Prints the encoding table
 */
void HuffmanAlgorithm::printEncodingTable() {
    utilities->debugStream << "printEncodingTable:\n\n";
    
    for (int i = 0; i < encodingTable.size(); ++i)
        if (encodingTable[i].size() != 0)
            utilities->debugStream << setw(3) << i << " " << utilities->formatByte(i) << " {" << encodingTable[i] << "}\n";
    
    utilities->debugStream << "\n" << flush;
}

/**
 Traverses the Huffman tree recursively and creates an encoding table
 @param current the current node in the Huffman tree
 @param bitData the encoded path for each leaf node in the Huffman tree
 */
void HuffmanAlgorithm::traverseTree(const HuffmanTree<int>* current, BitData& bitData) {
    if (current != nullptr) {
        if (current->isTerminal()) {
            for (int i = 0; i < bitData.size(); ++i)
                encodingTable[current->getByte()] += to_string(bitData.at(i));
            if (bitData.empty())
                encodingTable[current->getByte()] = "0";
        }
        bitData.push_back(0);
        traverseTree(current->getLeft(), bitData);
        bitData.pop_back();
        bitData.push_back(1);
        traverseTree(current->getRight(), bitData);
        bitData.pop_back();
    }
}

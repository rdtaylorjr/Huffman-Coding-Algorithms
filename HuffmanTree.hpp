/**
 Lab 6 - Huffman Coding
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file HuffmanTree.hpp
 @author Russell Taylor
 @date 9/20/20
*/

#ifndef HuffmanTree_hpp
#define HuffmanTree_hpp

template <typename Byte>
class HuffmanTree {
public:
    /**
     Constructor
     @param byte the character to encode
     @param frequency the frequency of the character
     */
    HuffmanTree(const Byte byte, const int frequency);

    /**
     Constructor
     @param first a pointer to the first child node
     @param second a pointer to the second child node
     */
    HuffmanTree(const HuffmanTree* first, const HuffmanTree* second);
    
    /**
     Destructor
     */
    ~HuffmanTree();

    /**
     Gets the frequency of the character
     @return the frequency of the character
     */
    int getFrequency() const;
    
    /**
     Gets the character
     @return the character
     */
    Byte getByte() const;
    
    /**
     Gets the left child node
     @return the left child node
     */
    const HuffmanTree<Byte>* getLeft() const;
    
    /**
     Gets the right child node
     @return the right child node
     */
    const HuffmanTree<Byte>* getRight() const;
    
    /**
     Identifies whether the node is a leaf node
     @return a boolean value indicating whether the node is a leaf node
     */
    bool isTerminal() const;

private:
    const Byte byte_;
    const int frequency_;
    const HuffmanTree<Byte>* left_;       // 0
    const HuffmanTree<Byte>* right_;      // 1
};

#include "HuffmanTree-impl.hpp"

#endif /* HuffmanTree_hpp */

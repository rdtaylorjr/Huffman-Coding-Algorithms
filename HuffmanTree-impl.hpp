/**
 Lab 6 - Huffman Coding
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file HuffmanTree-impl.hpp
 @author Russell Taylor
 @date 9/20/20
*/

#include "HuffmanTree.hpp"

/**
 Constructs the HuffmanTree class
 @param byte the character to encode
 @param frequency the frequency of the character
 */
template <typename Byte>
HuffmanTree<Byte>::HuffmanTree(const Byte byte, const int frequency) : byte_(byte), frequency_(frequency) {
    left_ = nullptr;
    right_ = nullptr;
}

/**
 Constructs the HuffmanTree class
 @param first a pointer to the first child node
 @param second a pointer to the second child node
 */
template <typename Byte>
HuffmanTree<Byte>::HuffmanTree(const HuffmanTree<Byte>* first, const HuffmanTree<Byte>* second) : byte_('\0'), frequency_(first->frequency_ + second->frequency_) {
    left_ = first->frequency_ <= second->frequency_ ? first : second;
    right_ = first->frequency_ <= second->frequency_ ? second : first;
}

/**
 Destructs the HuffmanTree class
 */
template <typename Byte>
HuffmanTree<Byte>::~HuffmanTree() {
    delete left_;
    delete right_;
}

/**
 Gets the frequency of the character
 @return the frequency of the character
 */
template <typename Byte>
int HuffmanTree<Byte>::getFrequency() const {
    return frequency_;
}

/**
 Gets the character
 @return the character
 */
template <typename Byte>
Byte HuffmanTree<Byte>::getByte() const {
    return byte_;
}

/**
 Gets the left child node
 @return the left child node
 */
template <typename Byte>
const HuffmanTree<Byte>* HuffmanTree<Byte>::getLeft() const {
    return left_;
}

/**
 Gets the right child node
 @return the right child node
 */
template <typename Byte>
const HuffmanTree<Byte>* HuffmanTree<Byte>::getRight() const {
    return right_;
}

/**
 Identifies whether the node is a leaf node
 @return a boolean value indicating whether the node is a leaf node
 */
template <typename Byte>
bool HuffmanTree<Byte>::isTerminal() const {
    return left_ == nullptr && right_ == nullptr;
}

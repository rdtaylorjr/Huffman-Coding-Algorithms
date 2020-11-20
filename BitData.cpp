/**
 Lab 6 - Huffman Coding
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file BitData.cpp
 @author Russell Taylor
 @date 9/20/20
*/

#include "BitData.hpp"

/**
 Constructor
 */
BitData::BitData() {
}

/**
 Constructor
 @param bit a bit
 */
BitData::BitData(const int bit) {
    v[0] = (bit == 1);
}

/**
 Adds a bit to the vector
 @param bit the bit to add
 */
void BitData::push_back(const int bit) {
    v.push_back(bit);
}

/**
 Removes a bit from the vector
 */
void BitData::pop_back() {
    v.pop_back();
}

/**
 Accesses a bit in the vector
 @param index the index of the bit to access
 */
int BitData::at(const int index) const {
    return v[index] ? 1 : 0;
}

/**
 Returns the size of the vector
 @return the size of the vector
 */
int BitData::size() const {
    return int(v.size());
}

/**
 Identifies whether the vector is empty
 @return a boolean value indicating whether the vector is empty
 */
bool BitData::empty() const {
    return v.empty();
}

/**
 Prints debugging information
*/
void BitData::print(ofstream& fout) const {
    for (const auto c : v)
        fout << (c ? "0" : "1");
}

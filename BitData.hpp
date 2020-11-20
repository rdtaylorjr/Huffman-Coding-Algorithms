/**
 Lab 6 - Huffman Coding
 CSC 255 Objects and Algorithms (Fall 2020)
 Oakton Community College
 Professor: Kamilla Murashkina

 @file BitData.hpp
 @author Russell Taylor
 @date 9/20/20
*/

#ifndef BitData_hpp
#define BitData_hpp

#include <fstream>
#include <vector>
using namespace std;

class BitData {
public:
    /**
     Constructor
     */
    BitData();

    /**
     Constructor
     @param bit a bit
     */
    BitData(const int bit);

    /**
     Adds a bit to the vector
     @param bit the bit to add
     */
    void push_back(const int bit);

    /**
     Removes a bit from the vector
     */
    void pop_back();
    
    /**
     Accesses a bit in the vector
     @param index the index of the bit to access
     */
    int at(const int index) const;
    
    /**
     Returns the size of the vector
     @return the size of the vector
     */
    int size() const;
    
    /**
     Identifies whether the vector is empty
     @return a boolean value indicating whether the vector is empty
     */
    bool empty() const;

    /**
     Prints debugging information
    */
    void print(ofstream& fout) const;

private:
    vector<bool> v;
};

#endif /* BitData_hpp */

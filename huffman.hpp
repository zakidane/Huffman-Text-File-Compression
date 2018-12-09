#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <vector>
#include <iostream>
#include <iterator>
#include <string>


using namespace std;

//the following are the two structs needed for this program.
//one is a MinHeapNode struct and the other a character structs
//they are essentially the same thing (that is, structs of characters that have
//have a char data element and a frequency element). However, the MinHeap node
//has an additional binaryCode member)
struct MinHeapNode {

    // One of the input characters
    char data;

    // Frequency of the character
    int freq;

    string binaryCode;

    // Left and right child
    MinHeapNode *left, *right;
MinHeapNode(char data, int freq)

    {

        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }

    MinHeapNode()

    {

        left = right = NULL;
    }
};

struct character{
    char letter;
    int frequency;
    character(){
        frequency = 0;
    }
};



//declares the returnHashTable helper function returnHashValue
int returnHashValue(MinHeapNode* minHeapPointer);

void returnCodes(MinHeapNode* root, string str, vector<MinHeapNode*>& v, int index);

vector<MinHeapNode*>  HuffmanCodes(char data[], int freq[], int size, MinHeapNode* &root);

vector<character> putIntoArray(string line);

int returnHashValue(char Character);

vector<MinHeapNode*> returnHashTable(vector<MinHeapNode*> v);

string decompression(string rawString, MinHeapNode* root);

#endif

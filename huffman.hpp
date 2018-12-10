#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <vector>
#include <iostream>
#include <iterator>
#include <string>


using namespace std;

//the following struct is the MinHeapNode struct which will be used to store
//a character, it's frequency of occurence in each line and its binaryCode
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


//declares the returnHashTable helper function returnHashValue
int returnHashValue(MinHeapNode* minHeapPointer);

void returnCodes(MinHeapNode* root, string str, vector<MinHeapNode*>& v, int index);

vector<MinHeapNode*>  HuffmanCodes(char data[], int freq[], int size, MinHeapNode* &root);

void putIntoArray(string line, vector<MinHeapNode> &v);

int returnHashValue(char Character);

vector<MinHeapNode*> returnHashTable(vector<MinHeapNode*> v);

string decompression(string rawString, MinHeapNode* root);

#endif

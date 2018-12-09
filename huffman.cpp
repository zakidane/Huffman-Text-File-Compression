#include <iostream>
#include <string.h>
#include <typeinfo>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
#include "huffman.hpp"

using namespace std;






int main() {

    string line, file;
    cout << "INpUt fILe NamE: " << endl;
    getline(cin, file);
    ifstream infile(file);
    getline(infile, line,'\n');
    cout << "original LIne: " << endl;
    cout << line << endl;
    vector<character>CharArray = putIntoArray(line);
    int sizeLine = CharArray.size();
    cout << "size of charArray is " << sizeLine << endl;
    char heapData[sizeLine];
    int heapFrequencies[sizeLine];
    for(int i = 0; i < sizeLine; i++){
        heapData[i] = CharArray[i].letter;
        heapFrequencies[i] = CharArray[i].frequency;
    }

      //declare a Minheap node to store the pointer to the minheap top
      //this variable will be an input when decoding the compressed binary fILe
      MinHeapNode* root;

      //this line will assign binary codes to each struct of the vector
      std::vector<MinHeapNode* > v = HuffmanCodes(heapData, heapFrequencies, sizeLine, root);

  // This pushes the vector of struct pointers into a returnHashTable
      //that assigns them to indexes according to the character's ascii code
    std::vector<MinHeapNode*> hashTable = returnHashTable(v);
    vector<MinHeapNode*>::iterator i;
    int n = 0;


    //define a temporary character and integer index hashValue
    //then loop through the line to get a character, get the hashvalue
    //associated with the character, retrive the corresponding Minheap pointer
    //associated with the character and print out the binaryCode of the character
    //We do this for all the characters in the line in their order of appearance
    int index;
    string rawString;
    cout << "Huffman Compressed Line" << endl;
    cout << "----------" << endl;
    for(unsigned int i = 0; i < line.length();i++){
        index = returnHashValue(line[i]);
        rawString += hashTable[index]->binaryCode;
        cout << hashTable[index]->binaryCode;

    }
    //rawString+="-";
    cout << "-" << endl;
    cout << "Huffman Decompressed Line" << endl;
    string decompressedLine = decompression(rawString, root);
    cout << decompressedLine << endl;


	return 0;
}

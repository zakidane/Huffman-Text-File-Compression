#include <iostream>
#include <string.h>
#include <typeinfo>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
#include "huffman.hpp"

using namespace std;






int main() {

    string line, file, compressedString, decompressedLine;
    int sizeArray, index;
    vector<MinHeapNode>CharArray;
    cout << "INpUt fILe NamE: " << endl;
    getline(cin, file);
    ifstream infile(file);
    ofstream compressedfile("compressed.txt");
    ofstream decompressedfile("decompressed.txt");
    while(getline(infile, line,'\n')){
      putIntoArray(line, CharArray);

    }
    sizeArray = CharArray.size();
    cout << "size of charArray is " << sizeArray << endl;
    char heapData[sizeArray];
    int heapFrequencies[sizeArray];
    for(int i = 0; i < sizeArray; i++){
        heapData[i] = CharArray[i].data;
        heapFrequencies[i] = CharArray[i].freq;
    }

      //declare a Minheap node to store the pointer to the minheap top
      //this variable will be an input when decoding the compressed binary fILe
      MinHeapNode* root;

      //this line will assign binary codes to each struct of the vector
      std::vector<MinHeapNode* > v = HuffmanCodes(heapData, heapFrequencies, sizeArray, root);

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


    //the following three lines reset the infile stream to start reading from
    //the beginning of the file again.
    infile.clear();
    infile.seekg (0, ios::beg);
    line = "";
    int x = 1;
    while(getline(infile, line)){
      cout << line << endl;
      for(unsigned int i = 0; i < line.size();i++){
          index = returnHashValue(line[i]);
          compressedString += hashTable[index]->binaryCode;
      }
      compressedString+= "-";
      cout << "line " << x << " " << compressedString << endl;
      cout << " for " << line << endl;
      x++;
      //append a dummy string and add line to the output file

      compressedfile << compressedString << endl;
      compressedString = "";
      line = "";
    }
    //close both the input file and the output file that has all the binaryCode
    infile.close();
    compressedfile.close();

    //open the compressed.txt file to translate it back to its oriignal text
    ifstream compressedInput("compressed.txt");

    while(getline(compressedInput, compressedString)){
      decompressedLine = decompression(compressedString, root);
      cout << "decompressed Line: " << endl;
      cout << decompressedLine << endl;
      decompressedfile << decompressedLine << endl;
  }



    decompressedfile.close();

    return 0;
}

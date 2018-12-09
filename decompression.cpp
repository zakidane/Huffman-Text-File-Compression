#include <iostream>
#include <string>
#include <vector>
#include "huffman.hpp"

using namespace std;


string decompression(string rawString, MinHeapNode* root){
  string decodedString;
  MinHeapNode* copyroot = root;
  for(unsigned int i = 0; i < rawString.length(); i++){
    if(rawString[i] == '0')
      copyroot = copyroot->left;
    else
      copyroot = copyroot->right;

    if(copyroot->left == NULL && copyroot->right == NULL){
      decodedString = decodedString + copyroot->data;
      copyroot = root;
    }

  }
  return decodedString;

}

#include <iostream>
#include <string.h>
#include <typeinfo>
#include <queue>
#include <vector>
#include "huffman.hpp"

using namespace std;

void returnCodes(MinHeapNode* root, string str, vector<MinHeapNode*>& v, int index){
    if(root == NULL)
        return;
    if(root->data != '^'){
      root->binaryCode = str;

      v.push_back(root);
      index++;
    }
    returnCodes(root->left, str + "0", v, index);
    returnCodes(root->right, str + "1", v, index);
}


struct compare {

    bool operator()(MinHeapNode* l, MinHeapNode* r)

    {
        return (l->freq > r->freq);
    }
};

vector<MinHeapNode*>  HuffmanCodes(char data[], int freq[], int size, MinHeapNode* &root)
{
    struct MinHeapNode *left, *right, *top;

    // Create a min heap & inserts all characters of data[]
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {

        // Extract the two minimum
        // freq items from min heap
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with
        // frequency equal to the sum of the
        // two nodes frequencies. Make the
        // two extracted node as left and right children
        // of this new node. Add this node
        // to the min heap '^' is a special value
        // for internal nodes, not used
        top = new MinHeapNode('^', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // Print and return  Huffman codes using
    // the Huffman tree built above
    root = minHeap.top();
    std::vector<MinHeapNode* > v;
    int index = 0;
    returnCodes(minHeap.top(), "", v, index);
    return v;
}




void putIntoArray(string line, vector <MinHeapNode>& charArray){

    for(int i = 0; i < line.size(); i++){
        vector <MinHeapNode>::iterator n;
        int k = 0;
        bool found = false;
        for(n = charArray.begin(); n != charArray.end(); n++){
            if(line[i] == charArray[k].data){
                charArray[k].freq++;
                found = true;
                break;
            }
            else{
                k++;
            }



        }
        if(found == false){
                MinHeapNode NewCharacter;
                NewCharacter.data = line[i];
                NewCharacter.freq = 1;
                charArray.push_back(NewCharacter);
        }
    }

}

int returnHashValue(char Character){
  int hashValue = (int)(Character);
  return hashValue;
}

vector<MinHeapNode*> returnHashTable(vector<MinHeapNode*> v){
  vector<MinHeapNode*> hashVector;
  //the below iteration fills up the hash-vecor named that will be returned
  //with NULL pointers so the vector can have the given size (128 for the 128
  //ASCII codes)
  for(int i = 0; i < 128; i++){
    hashVector.push_back(NULL);
  }
  //
  vector<MinHeapNode*>::iterator i;
  int n = 0;

  for(i = v.begin(); i != v.end(); i++){
      int hashValue = returnHashValue(v[n]->data);
      hashVector[hashValue] = v[n];
      n++;

  }
  return hashVector;
}

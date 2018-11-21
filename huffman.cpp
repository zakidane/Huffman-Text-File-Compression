#include <iostream>
#include <string.h>
#include <typeinfo>
#include <queue>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct MinHeapNode {

    // One of the input characters
    char data;

    // Frequency of the character
    int freq;

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

void printCodes(MinHeapNode* root, string str){
    if(root == NULL)
        return;
    if(root->data != '$')
        cout << root->data << ": " << str << endl;
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

struct compare {

    bool operator()(MinHeapNode* l, MinHeapNode* r)

    {
        return (l->freq > r->freq);
    }
};

void HuffmanCodes(char data[], int freq[], int size)
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
        // to the min heap '$' is a special value
        // for internal nodes, not used
        top = new MinHeapNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // Print Huffman codes using
    // the Huffman tree built above
    printCodes(minHeap.top(), "");
}

struct character{
    char letter;
    int frequency;
    character(){
        frequency = 0;
    }
};

vector<character> putIntoArray(string line){
    vector <character> charArray;
    for(int i = 0; i < line.size(); i++){
        vector <character>::iterator n;
        int k = 0;
        bool found = false;
        for(n = charArray.begin(); n!= charArray.end(); n++){
            if(line[i] == charArray[k].letter){
                charArray[k].frequency++;
                found = true;
                break;
            }
            else{
                k++;
            }



        }
        if(found == false){
                character NewCharacter;
                NewCharacter.letter = line[i];
                NewCharacter.frequency = 1;
                charArray.push_back(NewCharacter);
        }
    }
    return charArray;

}



int main() {

    string line;
    cout << "INpUt LInE: " << endl;
    getline(cin, line);
    vector<character>CharArray = putIntoArray(line);
    int sizeLine = CharArray.size();
    cout << "size of charArray is " << sizeLine << endl;
    char heapData[sizeLine];
    int heapFrequencies[sizeLine];
    for(int i = 0; i < sizeLine; i++){
        heapData[i] = CharArray[i].letter;
        heapFrequencies[i] = CharArray[i].frequency;
    }




    HuffmanCodes(heapData, heapFrequencies, sizeLine);

	return 0;
}

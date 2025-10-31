//
// Created by Manju Muralidharan on 10/19/25.
//
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include "heap.h"
using namespace std;

// Global arrays for node information
const int MAX_NODES = 64;
int weightArr[MAX_NODES];
int leftArr[MAX_NODES];
int rightArr[MAX_NODES];
char charArr[MAX_NODES];

// Function prototypes
void buildFrequencyTable(int freq[], const string& filename);
int createLeafNodes(int freq[]);
int buildEncodingTree(int nextFree);
void generateCodes(int root, string codes[]);
void encodeMessage(const string& filename, string codes[]);

int main() {
    int freq[26] = {0};

    // Step 1: Read file and count letter frequencies
    buildFrequencyTable(freq, "input.txt");

    // Step 2: Create leaf nodes for each character with nonzero frequency
    int nextFree = createLeafNodes(freq); //unique characters as leaf nodes

    // Step 3: Build encoding tree using your heap
    int root = buildEncodingTree(nextFree); //only returns root of all the leaves added up

    // Step 4: Generate binary codes using an STL stack
    string codes[26];
    generateCodes(root, codes);

    // Step 5: Encode the message and print output
    encodeMessage("input.txt", codes);

    return 0;
}

/*------------------------------------------------------
    Function Definitions (Students will complete logic)
  ------------------------------------------------------*/

// Step 1: Read file and count frequencies
void buildFrequencyTable(int freq[], const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: could not open " << filename << "\n";
        exit(1);
    }

    char ch;
    while (file.get(ch)) {
        // Convert uppercase to lowercase
        if (ch >= 'A' && ch <= 'Z')
            ch = ch - 'A' + 'a';

        // Count only lowercase letters
        if (ch >= 'a' && ch <= 'z')
            freq[ch - 'a']++;
    }
    file.close();

    cout << "Frequency table built successfully.\n";
}

// Step 2: Create leaf nodes for each character
int createLeafNodes(int freq[]) {
    int nextFree = 0;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > 0) { //if letter has a frequency
            charArr[nextFree] = 'a' + i; //each character
            weightArr[nextFree] = freq[i];
            leftArr[nextFree] = -1; //make sure left children non-existent
            rightArr[nextFree] = -1; //makes sure right children non-existent
            nextFree++;
        }
    }
    cout << "Created " << nextFree << " leaf nodes.\n"; //certain number of leaf nodes
    return nextFree;
}

// Step 3: Build the encoding tree using heap operations
int buildEncodingTree(int nextFree) {
    // TODO:
    // 1. Create a MinHeap object.
    // 2. Push all leaf node indices into the heap.
    // 3. While the heap size is greater than 1:
    //    - Pop two smallest nodes
    //    - Create a new parent node with combined weight
    //    - Set left/right pointers
    //    - Push new parent index back into the heap
    // 4. Return the index of the last remaining node (root)
    MinHeap heap;
    //assume frequency table built
    //leaf nodes are made for each frequency characters
    int c = 0;
    while (c < nextFree) { //assumes it follows methods where nextFree is at least 1
        heap.push(c,weightArr);
        c++;
    }

    int leaf1;
    int leaf2;
    int parVal;
    int parIdx;

    while (heap.size > 1) {
        //we are looping to make it so that we get to a final combined root
        //(so > 1 to keep loop going)
        leaf1 = heap.pop(weightArr); //size decreases after a pop, looping variant
        leaf2 = heap.pop(weightArr);

        //we set parIdx each loop. nextFree was our starting index as after all unique leaves
        parIdx = nextFree;

        parVal = weightArr[leaf1] + weightArr[leaf2];
        weightArr[parIdx] = parVal; //need to make sure weightArr is changed at the index
        //need to change FIRST and then push LATER onto heap

        leftArr[parIdx] = leaf1;
        rightArr[parIdx] = leaf2;

        heap.push(parIdx,weightArr);

        //incremented in order to have a space for assignments of weightArr
        nextFree++;
    }
    return heap.pop(weightArr);
}

// Step 4: Use an STL stack to generate codes
void generateCodes(int root, string codes[]) {
    // TODO:
    // Use stack<pair<int, string>> to simulate DFS traversal.
    // Left edge adds '0', right edge adds '1'.
    // Record code when a leaf node is reached.
}

// Step 5: Print table and encoded message
void encodeMessage(const string& filename, string codes[]) {
    cout << "\nCharacter : Code\n";
    for (int i = 0; i < 26; ++i) {
        if (!codes[i].empty())
            cout << char('a' + i) << " : " << codes[i] << "\n";
    }

    cout << "\nEncoded message:\n";

    ifstream file(filename);
    char ch;
    while (file.get(ch)) {
        if (ch >= 'A' && ch <= 'Z')
            ch = ch - 'A' + 'a';
        if (ch >= 'a' && ch <= 'z')
            cout << codes[ch - 'a'];
    }
    cout << "\n";
    file.close();
}
//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    //left child = 2i + 1
    //right child = 2i + 2
    //parent = floor(i-1 / 2)


    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()

        //insert template made
        if (size == 64) {
            cout << "Heap is full" << endl;
            return;
        }
        if (size == 0) {
            data[size] = idx;
            size++;
            return;
        }
        int currIdx = size-1;
        int temp = data[currIdx];
        int lChild = 2*currIdx + 1;
        int rChild = 2*currIdx + 2;
        int parent = floor((size - 1)/2);
        if (parent == 1) { //case where only one node exists
            if (!data[lChild]) {
                data[currIdx] = data[lChild];
                size++;
                return;
            }
            if (!data[rChild]) {
                data[currIdx] = data[rChild];
                size++;
                return;
            }
        }





        //upheap(idx, weightArr);




    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        int len2 = sizeof(data) / sizeof(data[0]);
        int c = len2-1;

        //data[pos]


    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
    }
};

#endif
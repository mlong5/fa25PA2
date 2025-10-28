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
        if (size >= 64) {
            cout << "Heap is full" << endl;
            return;
        }

        data[size-1] = idx;
        upheap(size-1, weightArr);
        size++;




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
        if (parent)





        //upheap(idx, weightArr);




    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) { //only one call
        // TODO: swap child upward while smaller than parent

        int i = pos;
        int parentI;

        while (i != 0) {
            parentI = floor((i-1)/2); //flooring in case, must update in loop

            if (weightArr[data[i]] < weightArr[data[parentI]]) {
                swap(data[i], data[parentI]);
                i = parentI; //as looping variant
            } else {
                return;
            }
        }


        //data[pos]


    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        int z = pos;
        int leftChildI = 2*z +1;
        int rightChildI = 2*z +2;
        int minI;

        while (leftChildI < size) {
            leftChildI = 2*z + 1;
            rightChildI = 2*z + 2;

            minI = leftChildI; //assume leftChild is minIndex to make easier on checks

            //rightChildI < size to check for existence
            if (rightChildI < size && weightArr[data[leftChildI]] > weightArr[data[rightChildI]]) {
                minI = rightChildI;
            }

            if (weightArr[data[z]] > weightArr[data[minI]]) {
                swap(data[z], data[minI]);
                z = minI; //looping variant
            } else {
                return;
            }
    }
};

#endif
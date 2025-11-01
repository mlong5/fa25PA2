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

        data[size] = idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        int temp;
        if (size != 0) {
            temp = data[0];
            data[0] = data[size-1]; //replacement of data[0] overwrites the smallest value
            size--; //size moving back makes it true deletion
            downheap(0, weightArr); //fixes min heap
            return temp;
        }
        return -1; // placeholder but will now also be for if empty
    }

    void upheap(int pos, int weightArr[]) { //only one call
        // TODO: swap child upward while smaller than parent

        int i = pos;
        int parentI;

        while (i > 0) {
            parentI = (int)floor((i-1)/2); //flooring in case, must update in loop

            if (weightArr[data[i]] < weightArr[data[parentI]]) {
                swap(data[i], data[parentI]);
                i = parentI; //as looping variant
            } else {
                return;
            }
        }


    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        int z = pos;
        int leftChildI;
        int rightChildI;
        int minI;

        while (2*z + 1 < size) { //need to make sure z is checked not the outside variable of leftChildI
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
    }
    };
#endif
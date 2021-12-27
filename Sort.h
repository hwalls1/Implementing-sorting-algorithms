/*
*  Sort.h
*  Sorting class; contains 6 sort algorithms - insertion,
*  selection, bubble, quick, merge, and shell sort
*
*  Created by Harrison Walls on 1/18/16.
*
*/

#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <time.h>

const int W_WIDTH = 350, W_HEIGHT = 350;  //dimension of drawing windows

const float lleft = 0.0;                 //dimension of viewports
const float rright = W_WIDTH;
const float bbottom = 0.0;
const float ttop = W_HEIGHT;

class Sort {
    
public :
    static const int SIZE = W_WIDTH;     //size of array
    
/*Class constructor
    * Pre : none
    * Post : Sort object constructed with randomly populated array
    * where values are in range [0, SIZE-1]
*/
    Sort();
    
/*Class destructor
     * Pre : none
     * Post : Sort object memory freed
*/
    ~Sort();
    
/* Standard insertion sort algorithm
     * Pre : none
     * Post : Sort object data placed in ascending order
*/
    void insertionSort();
    
/* Fast bubble sort algorithm
     * Pre : none
     * Post : Sort object data placed in ascending order
*/
    void bubbleSort();
    
/* Standard selection sort algorithm
     * Pre : none
     * Post : Sort object data placed in ascending order
*/
    void selectionSort();
    
/* Standard quick sort algorithm
     * Pre : none
     * Post : Sort object data placed in ascending order
*/
    void quickSort();

/* Standard merge sort algorithm
 * Pre : none
 * Post : Sort object data placed in ascending order
*/
    void mergeSort();

/* Standard shell sort algorithm
* Pre : none
* Post : Sort object data placed in ascending order
*/
    void shellSort(int n);

    
private :
    int *random;                //data to be sorted
    
    void mergehelper(int p, int r, int&swapCount);    //merge helper
    void quickHelper(int p, int r, int &swapCount);  //quick sort helper
    int partition(int p, int r, int &swapCount);     //standard partition
    void delay(int milliseconds);               //used to delay display
    void mergeArray(int p, int q, int r);  //used to merge the two halfs
    
};

#endif /* SORT_H */

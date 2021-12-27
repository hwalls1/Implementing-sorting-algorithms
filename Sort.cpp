/*
 *  Sort.cpp
 *  Sorting class; contains 6 sort algorithms - insertion,
 *  selection, bubble, quick, merge, and shell sorts,
 *
 *  Created by Harrison Walls
 *
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Sort.h"

#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/glut.h>
#endif

using namespace std;

/**
     * Build the random array
* *
*/
Sort::Sort()
    {
        int *random = new int[SIZE];
        srand((unsigned)time(NULL));
        for(int i = 0; i < SIZE; i++)
            random[i] = 1 + rand() % 10;
    }
    
/**
    * Deconstruct array
 **
 */
Sort::~Sort()
    {
        delete [] random;
    }

/**
     * Insertion Sort : standard algorithm
**
*/
void Sort::insertionSort()
    {
       int moveCount = 0;
        
       for(int j = 1; j < SIZE; j++)
       {
            int key = random[j];
            int i = j - 1;
           
           while ((i >= 0) && (key < random[i]))
            {
                moveCount++;
                random[i+1] = random[i];
                i = i - 1;
            }
            random[i + 1] = key;
           
           //draw data points in array
           glClear (GL_COLOR_BUFFER_BIT);
           glBegin(GL_QUADS);
           
           for (GLint k = 0; k < SIZE; k++) {
               
               int val = random[k];
               glVertex2f(k+lleft, val);
               glVertex2f((k+1)+lleft, val);
               glVertex2f((k+1)+lleft,(val+1));
               glVertex2f(k+lleft,(val+1));
           }
           glEnd();
           glutSwapBuffers();
           delay(10);
           
           moveCount++;
           
       }
    cout << "Number of data movements for insertion sort = " <<moveCount<< " .\n";
        
    }
    
/**
     * Bubble Sort : fastest BS algorithm
**
*/
void Sort::bubbleSort()
    {
        int moveCount = 0;

        for(int i = 0; i<SIZE; i++)
        {
            for(int j = 0; j<SIZE - 1; j++)
            {
                if(random[j] > random[j+1])
                {
                    moveCount++;
                    int temp;
                    temp = random[j];
                    random[j] = random[j+1];
                    random[j+1] = temp;
                }
            }
            //draw data points in array
            glClear (GL_COLOR_BUFFER_BIT);
            glBegin(GL_QUADS);
            
            for (GLint k = 0; k < SIZE; k++) {
                
                int val = random[k];
                glVertex2f(k+lleft, val);
                glVertex2f((k+1)+lleft, val);
                glVertex2f((k+1)+lleft,(val+1));
                glVertex2f(k+lleft,(val+1));
            }
            glEnd();
            glutSwapBuffers();
            delay(30);
            
            moveCount++;
        }
        cout << "Number of data movements for bubble sort = " <<moveCount<< " .\n";
    }
   
/**
     * Selection Sort : standard algorithm
**
*/
void Sort::selectionSort()
    {
    int moveCount = 0;

        int t;
        for(int i = 0; i<=SIZE-1; i++)
        {
            for(int j = i+1; j<=SIZE-1; j++)
            {
                if(random[i]> random[j])
                {
                    moveCount++;
                    t=random[i];
                    random[i]=random[j];
                    random[j]=t;
                }
            }
            //draw data points in array
            glClear (GL_COLOR_BUFFER_BIT);
            glBegin(GL_QUADS);
            
            for (GLint k = 0; k < SIZE; k++) {
                
                int val = random[k];
                glVertex2f(k+lleft, val);
                glVertex2f((k+1)+lleft, val);
                glVertex2f((k+1)+lleft,(val+1));
                glVertex2f(k+lleft,(val+1));
            }
            glEnd();
            glutSwapBuffers();
            delay(50);
            
            moveCount++;
        }
    cout << "Number of data movements for selection sort = " <<moveCount<< " .\n";

    }
   
/**
     * Quick Sort : standard algorithm using Lumotos Partition
**
*/
void Sort::quickSort()
   {
        int swapCount = 0;
        quickHelper(0, SIZE - 1, swapCount);
       
       //draw data points in array
       glClear (GL_COLOR_BUFFER_BIT);
       glBegin(GL_QUADS);
       
       for (GLint k = 0; k < SIZE; k++) {
           
           int val = random[k];
           glVertex2f(k+lleft, val);
           glVertex2f((k+1)+lleft, val);
           glVertex2f((k+1)+lleft,(val+1));
           glVertex2f(k+lleft,(val+1));
       }
       glEnd();
       glutSwapBuffers();
       delay(10);
       
       swapCount++;
       
        cout << "Number of swaps for quick sort =" << swapCount <<".\n";
       
   }
   
/**
     * Quick Sort helper : handles recursion
     * p   start of partition
     * r   end of partition
     * swapCount number of swaps performed
*/
void Sort::quickHelper(int p, int r, int &swapCount)
   {
       if(p < r)
       {
           int q = partition(p, r, swapCount);
           quickHelper(p, q-1, swapCount);
           quickHelper(q +1, r, swapCount);
       }
       
   }
   
/**
     * Partition : does partial ordering
     * p   start of partition
     * r   end of partition
     * swapCount number of swaps performed
     *
     * q   returns partition index
*/
int Sort::partition(int p, int r, int &swapCount)
   {
       int x = random[r];
       int i = p -1;
       for(int j = p; j <= r - 1; j++)
       {
           if(random[j] <= x)
           {
               swapCount++;
               i = i + 1;
               random[i] = random[j];
           }
       }
       swapCount++;
       random[i+1] = random[r];
       return i+1;

/**
 * mergeSort - standard algorithm
 */
void Sort::mergesort()
{
    int swapCount = 0;
    mergehelper(0, SIZE - 1, swapCount);
    
    //draw data points in array
    glClear (GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    
    for (GLint k = 0; k < SIZE; k++)
    {
        
        int val = random[k];
        glVertex2f(k+lleft, val);
        glVertex2f((k+1)+lleft, val);
        glVertex2f((k+1)+lleft,(val+1));
        glVertex2f(k+lleft,(val+1));
    }
    glEnd();
    glutSwapBuffers();
    delay(40);
    swapCount++;
    
    cout << "Number of data movements for merge sort = " <<moveCount<< " .\n";
}

void Sort::mergehelper(int p, int r, int &swapCount)
{
    if(p<r)
    {
        int q = ((p+r)/2);
        mergehelper(p, q, swapCount);
        mergehelper(q+1, r, swapCount);
        mergeArray(p, q, r);
    }
}
/**
 * Merge : does partial ordering
 *
 * p   start of array
 * r   end of array
 * mid middle of array
 */
void Sort::mergeArray(int p, int q, int r)
{
    int n1 = (q - p) + 1;
    int n2 = r - q;
    int L[n1 + 1];
    int R[n2 + 1];
    for(int i = 1; i <= n1; i++)
    {
        L[i] = random[(p + i) - 1];
    }
    for(int j = 1; j <= n2; j++)
    {
        R[j] = random[q + j];
    }
    L[n1 + 1];
    R[n2 + 1];
    i = 1;
    j = 1;
    for(int k =p k <= r; k++)
    {
        if(L[i] <= R[j])
        {
            random[k] = L[i];
            i = i + 1;
        }
        else(random[k] = R[j])
        {
            j = j + 1;
        }
    }
}

/**
 * shell : does partial ordering
 * random  array that needs sorting
 *
 */
void Sort::shellSort(int n)
{
    int i, j, k, temp;
    int moveCount = 0;
    
    for(i = n/2; i > 0; i = i/2)
    {
        for(j = i; j < n; j++)
        {
            for(k = j-i; k >= 0; k = k-i)
            {
                if(random[k+i] >= random[k])
                    break;
                else
                {
                    moveCount++;
                    temp = random[k];
                    random[k] = random[k+i];
                    random[k+i] = temp;
                }
            }
        }
    }
    //draw data points in array
    glClear (GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    
    for (GLint k = 0; k < SIZE; k++)
    {
        
        int val = random[k];
        glVertex2f(k+lleft, val);
        glVertex2f((k+1)+lleft, val);
        glVertex2f((k+1)+lleft,(val+1));
        glVertex2f(k+lleft,(val+1));
    }
    glEnd();
    glutSwapBuffers();
    delay(20);
    moveCount++;
    
    cout << "Number of data movements for bubble sort = " <<moveCount<< " .\n";
}

/**
    * Delay : for some milliseconds
** 
*/
void Sort:: delay(int milliseconds)
{
    long pause;
    clock_t now, then;
    
    pause = milliseconds * (CLOCKS_PER_SEC / 1000);
    now = then = clock();
    while( (now - then) < pause )
        now = clock();
}

d/**
* Visualization of 4 sorting algorithms in
* 4 separate windows, right mouse to start and quit sorts
* author (Harrison Walls)
* WHIMPY version (1.0)
*/

#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#  include <GLUT/glut.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#  include <GL/glut.h>
#endif

#include "Sort.h"
#include <iostream>

using namespace std;

Sort *insertion, *selection, *bubble, *quick, *merges, *shell; //Sort objects

int insertionWindow, selectionWindow, bubbleWindow, quickWindow, mergeWindow, shellWindow;                                //Display windows
const int spacer = 70;                          //Window spacing

//Initializes background color and drawing color
void init (void)
{
    glClearColor (0.0, 0.0, 0.0, 1.0);
    glColor3f (1.0, 1.0, 1.0);
    glShadeModel (GL_FLAT);
}


//Reshape callback: Allows the window to be resized, but sort
//will still work only on original array size
void reshape(int w, int h) {
    
    glViewport(0, 0, W_WIDTH, W_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(lleft, rright, bbottom, ttop);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutPostRedisplay();
}

/*
//Display Insertion Sort Callback
void displayInsertion()
{
    
}

//Display Selection Sort Callback
void displaySelection()
{
    
}

//Display Bubble Sort Callback
void displayBubble()
{
    
}

//Display Quick Sort Callback
void displayQuick()
{
    
}

//Display Quick Sort CallBack
void displayMerge()
{
    
}

//Display shell Sort CallBack
void displayShell()
{
    
}
*/

//Insertion Sort Menu Callback: Simple menu attached to right button
//Supports start sort and quit option

void insertion_menu(int id)
{
    //Reset the array and randomly populate
    if(id == 1) {
        if(insertion != NULL)
            insertion->~Sort();
        insertion = new Sort();
        insertion->insertionSort();
        glutPostRedisplay();
    }
    //Exit the program
    else if(id == 2) exit(0);
}

//Selection Sort Menu Callback: Simple menu attached to right button
//Supports start sort and quit option
void selection_menu(int id)
{
    //Reset the array and randomly populate
    if(id == 1) {
        if(selection != NULL)
            selection->~Sort();
        selection = new Sort();
        selection->selectionSort();
        glutPostRedisplay();
    }
    
    //Exit the program
    else if(id == 2) exit(0);
}

//Bubble Sort Menu Callback: Simple menu attached to right button
//Supports start sort and quit option
void bubble_menu(int id)
{
    //Reset the array and randomly populate
    if(id == 1) {
        if(bubble != NULL)
            bubble->~Sort();
        bubble = new Sort();
        bubble->bubbleSort();
        glutPostRedisplay();
    }
        //Exit the program
    else if(id == 2) exit(0);
}

//Quick Sort Menu Callback: Simple menu attached to right button
//Supports start sort and quit option
void quick_menu(int id)
{
    //Reset the array and randomly populate
    if(id == 1) {
        if(quick != NULL)
            quick->~Sort();
        quick = new Sort();
        quick->quickSort();
        glutPostRedisplay();
    }
    
    //Exit the program
    else if(id == 2) exit(0);
}

//Merge Sort Menu Callback: Simple menu attached to right button
//Supports start sort and quit option
void merge_menu(int id)
{
    //Reset the array and randomly populate
    if(id == 1) {
        if(merges != NULL)
            merges->~Sort();
        merges = new Sort();
        merges->mergeSort();
        glutPostRedisplay();
    }
    
    //Exit the program
    else if(id == 2) exit(0);
}

//shell Sort Menu Callback: Simple menu attached to right button
//Supports start sort and quit option
void shell_menu(int id)
{
    //Reset the array and randomly populate
    if(id == 1) {
        if(shell != NULL)
            shell->~Sort();
        shell = new Sort();
        shell->shellSort(int n);
        glutPostRedisplay();
    }
    
    //Exit the program
    else if(id == 2) exit(0);
}

//Creates windows and menus, enters event loop
int main(int argc, char **argv) {
{
    glutInit(&argc, argv);
    
    //Window initialization for insertion sort
    glutInitWindowSize(W_WIDTH, W_HEIGHT);
    glutInitWindowPosition(0, 0);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    insertionWindow = glutCreateWindow("Insertion Sort Visualization");
    init();
    
    //Menu initialization for insertion sort
    glutCreateMenu(insertion_menu);
    glutAddMenuEntry("Start",1);
    glutAddMenuEntry("Quit",2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    glutReshapeFunc(reshape);
    glutDisplayFunc(displayInsertion);
    
    //Window initialization for selection sort
    glutInitWindowSize(W_WIDTH, W_HEIGHT);
    glutInitWindowPosition(W_WIDTH + spacer, 0);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    selectionWindow = glutCreateWindow("Selection Sort Visualization");
    init();
    
    //Menu initialization for selection sort
    glutCreateMenu(selection_menu);
    glutAddMenuEntry("Start",1);
    glutAddMenuEntry("Quit",2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    glutReshapeFunc(reshape);
    glutDisplayFunc(displaySelection);
    
    //Window initialization for bubble sort
    glutInitWindowSize(W_WIDTH, W_HEIGHT);
    glutInitWindowPosition(0, W_HEIGHT + spacer);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    bubbleWindow = glutCreateWindow("Bubble Sort Visualization");
    init();
    
    //Menu initialization for bubble sort
    glutCreateMenu(bubble_menu);
    glutAddMenuEntry("Start",1);
    glutAddMenuEntry("Quit",2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    glutReshapeFunc(reshape);
    glutDisplayFunc(displayBubble);
    
    //Window initialization for quick sort
    glutInitWindowSize(W_WIDTH, W_HEIGHT);
    glutInitWindowPosition(W_WIDTH + spacer, W_HEIGHT + spacer);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    quickWindow = glutCreateWindow("Quick Sort Visualization");
    init();
    
    //Menu initialization for quick sort
    glutCreateMenu(quick_menu);
    glutAddMenuEntry("Start",1);
    glutAddMenuEntry("Quit",2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    glutReshapeFunc(reshape);
    glutDisplayFunc(displayQuick);
    
    //Window initialization for merge sort
    glutInitWindowSize(W_WIDTH, W_HEIGHT);
    glutInitWindowPosition(W_WIDTH + spacer, W_HEIGHT + spacer);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    quickWindow = glutCreateWindow("Merge Sort Visualization");
    init();
    
    //Menu initialization for merge sort
    glutCreateMenu(merge_menu);
    glutAddMenuEntry("Start",1);
    glutAddMenuEntry("Quit",2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    glutReshapeFunc(reshape);
    glutDisplayFunc(displayQuick);
    
    //Window initialization for shell sort
    glutInitWindowSize(W_WIDTH, W_HEIGHT);
    glutInitWindowPosition(W_WIDTH + spacer, W_HEIGHT + spacer);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    quickWindow = glutCreateWindow("Shell Sort Visualization");
    init();
    
    //Menu initialization for shell sort
    glutCreateMenu(shell_menu);
    glutAddMenuEntry("Start",1);
    glutAddMenuEntry("Quit",2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    glutReshapeFunc(reshape);
    glutDisplayFunc(displayQuick);
    
    glutMainLoop();
    
    return 0;
  }
     
}
 
 
    
       
 
 

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include<stdio.h>
#include <queue>
#include <string>
#include <iostream>
#include "Node.hpp"
using namespace std;

struct compare

{
    bool operator()(Node* A, Node* B) /*Needed a way to compare two nodes but without getting an error for having a simalar data type, so I used struct to contain different data types in one structure. In this case a char and an int */
    {
        return (A -> getfrequency() > B -> getfrequency());
    }
};


void displaytree(Node* root, string s) /* To display the tree stucture I had one represent the right of the tree and 0 for the left side. This method starts from the root and travels the pathway to the leaf node, if a ! is encountered, it continues until it reaches the a leaf node or a node with an actual character*/
{
    if(!root){
        
        return; 
    }
    
    if(root -> getvalue() != '!')
    {
        cout << root -> getvalue() << ": " << s << "\n";
    }
    
    
displaytree(root -> leftside, s + "0");
displaytree(root -> rightside, s + "1"); /* how it's able to print either right or left based on where the leaf node is currently located */

}


void huffmanbuilttree(char data[], int freq[], int size)
{
    Node* left;
    Node* right;
    Node* top;
    
    priority_queue<Node*, vector<Node*>, compare> minHeap; /* Extreamily importent this is needed in order for a minimum heap to be intialized, another reason why I had to use struct*/
    
    for (int a = 0; a < size; ++a)
        
    
        minHeap.push(new Node(data[a], freq[a]));

    while (minHeap.size() != 1) 
    {
        /* Until minheap runs out of leaf in the char except one, continue removing frequencies from the char stucture */
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        /* How we create a node without having a character attacted to it which would represent our leaf node*/
        top = new Node('!', left->getfrequency() + right->getfrequency());

        top->leftside = left;
        top->rightside = right;

        minHeap.push(top);
    
    
    }

    
    displaytree(minHeap.top(), "");
}

int main()
{
    char leafnode[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    
    int sizeofarr = sizeof(leafnode) / sizeof(leafnode[0]);
    
    huffmanbuilttree(leafnode, freq, sizeofarr);
}
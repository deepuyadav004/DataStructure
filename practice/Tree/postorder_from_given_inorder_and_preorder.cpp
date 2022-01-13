Given a preOrder and inOrder traversal of a binary tree your task is to print the postOrder traversal of the tree .You are required to complete the function printPostOrder which
prints the node of the tree in post order fashion . You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called
individually.

Example 1:

Input
6
4 2 5 1 3 6
1 2 4 5 3 6
Output 4  5  2  6  3 1
  
  // C++ program to print Postorder traversal from 
// given Inorder and Preorder traversals. 
#include<bits/stdc++.h>
using namespace std;

int preIndex = 0; 
void printPost(int in[], int pre[], int inStrt,
               int inEnd, map<int, int> hm) 
{ 
    if (inStrt > inEnd) 
        return;         

    // Find index of next item in preorder traversal in 
    // inorder. 
    int inIndex = hm[pre[preIndex++]]; 

    // traverse left tree 
    printPost(in, pre, inStrt, inIndex - 1, hm); 

    // traverse right tree 
    printPost(in, pre, inIndex + 1, inEnd, hm); 

    // print root node at the end of traversal 
    cout << in[inIndex] << " "; 
} 

void printPostMain(int in[], int pre[],int n) 
{
    map<int,int> hm ;
    for (int i = 0; i < n; i++)
    hm[in[i]] = i;
        
    printPost(in, pre, 0, n - 1, hm);
}

// Driver code 
int main()
{ 
    int in[] = { 4, 2, 5, 1, 3, 6 }; 
    int pre[] = { 1, 2, 4, 5, 3, 6 }; 
    int n = sizeof(pre)/sizeof(pre[0]);
    
    printPostMain(in, pre, n); 
    return 0;
} 

// #include "header.h"

/*
  Do not remove the "header.h" file.
  
*/
//-----Include any additional required headers here-----

#include <iostream>
#include <vector>

using namespace std;

//-----End of additional headers-----

    //-----Don't change/delete struct -----
    struct node {
        int data;
        node * left;
        node * right;
    };
    //----- Struct ends here

//-----Add new functions here(if any)-----

void createTree(int x, struct node *n) {
    // cout<<"Come to daddy";
    if(x>(*n).data) {
      
      if((*n).right!=NULL)
        createTree(x,(*n).right);
      else {
        node* e=new node();
        (*e).data=x;
        (*e).right=NULL;
        (*e).left=NULL;
        (*n).right=e;
    }
    }

    else {

      if((*n).left!=NULL)
        createTree(x,(*n).left);
      else {
        node* e=new node();
        (*e).data=x;
        (*e).right=NULL;
        (*e).left=NULL;
        (*n).left=e;
      }
    }

  return;
}

void inOrderTraversal(vector <int> *elements,node *n) {

  bool flag=false;

  while((*n).left!=NULL && flag==false) {
    inOrderTraversal(elements,(*n).left);
    flag=true;
  }

  (*elements).push_back((*n).data);
  if((*n).right!=NULL)
    inOrderTraversal(elements,(*n).right);

  return;
}

//-----New functions end here-----

/* Question: You need to write the implementations of the given functions .
             ( You may write any additional helper functions you want in the specified region only.
               Do not change the signature of the functions or structs already given.)
               Note that we would be explicitly calling makeBinarySearchTree(vec <int>) and inOrderElements(root) and makeBSTFromSortedVector(vec)
               to check the the functions. In summary, makeBinarySearchTree() function should take the distinct elements present in vector and form a BST from them
               by inserting the elements in same order as present in vector. It should follow the algorithm specified in class which is also present in description
               as pseudo code. inOrderElements() function, which takes the root node of BST as argument, must return the in-order traversal elements as a vector.
               makeBalancedBSTFromSortedVector() function must take a sorted vector and return the root node of a balanced binary search tree.
               You can assume that the vector always contains distinct elements and the length of vector is always of the form 2^n - 1, to form a balanced binary search tree.
               For detailed explanation of the question refer to the description part) 
*/


node* makeBinarySearchTree(vector <int> elements) {
    node* root=new node();
    (*root).data=elements[0];

    (*root).left=NULL;
    (*root).right=NULL;
    for(int i=1;i<elements.size();i++)  {
      createTree(elements[i],root);
    }
    
  return root;    // Make sure to change this to your correct return value..
}

vector<int> inOrderElements(node* root){
    // Write your code here
      vector <int> elements;
      inOrderTraversal(&elements,root);

    return elements;    // Make sure to change this to your correct return value..
}

node* makeBalancedBSTFromSortedVector(vector<int> sorted_elements){
    // Write your code here
    node* root=new node();
    int l_end,r_begin;
    if(sorted_elements.size()/2-1>0)
      l_end=sorted_elements.size()/2-1;
    else
      l_end=0;

    if(sorted_elements.size()/2+1>=sorted_elements.size())
      r_begin=sorted_elements.size()-1;
    else
      r_begin=sorted_elements.size()/2+1;

    vector <int> l(sorted_elements.begin(),sorted_elements.begin()+l_end+1);
    vector <int> r(sorted_elements.begin()+r_begin,sorted_elements.end());
    (*root).data=sorted_elements[sorted_elements.size()/2];
    

    if(sorted_elements.size()<=2) {
      if(sorted_elements.size()==1) {
          l.clear();
          r.clear();
        }
      else {
          r.clear();
        }
    }

    if(l.size()!=0)
      (*root).left=makeBalancedBSTFromSortedVector(l);
    else
      (*root).left=NULL;

    if(r.size()!=0)
      (*root).right=makeBalancedBSTFromSortedVector(r);
    else
      (*root).right=NULL;

    return root;    // Make sure to change this to your correct return value..
}


int main()  {

    vector <int> el;
    int no,c;
    cin>>no;

    for(int i=0;i<no;i++) {
      cin>>c;
      el.push_back(c);
    }
    node *n=new node();
    n=makeBinarySearchTree(el);

    vector <int> ele;  
    ele=inOrderElements(n);

    cout<<"inOrderTraversal=";
    for(int i=0;i<ele.size();i++)
      cout<<ele[i]<<" ";

    int nos,inp;
    cin>>nos;

    vector <int> num;

    for(int i=0;i<nos;i++) {
      cin>>inp;
      num.push_back(inp);
    } 

    node* mn=makeBalancedBSTFromSortedVector(num);
    vector <int> elem;
    elem=inOrderElements(mn);
    cout<<"inOrderTraversal=";
    for(int i=0;i<elem.size();i++)
      cout<<elem[i]<<" ";

  return 0;
}

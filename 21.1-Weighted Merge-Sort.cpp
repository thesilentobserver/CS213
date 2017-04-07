// #include "header.h"
/*
  Do not remove the "header.h" file.
*/

//-----Include any additional required headers here-----

#include <iostream>
#include <vector>

using namespace std;

//-----End of additional headers-----

//-----Add new functions here(if any)-----

void sortedMerge(vector <int> &num, vector <int> &weights, int start_l,int end_l,int start_r,int end_r) {
  vector <int> merged,n_weights;
  int a_itr=start_l,b_itr=start_r;
  int replace_pos=start_l;
  
  while(a_itr<=end_l && b_itr<=end_r) {
      if(weights[a_itr]!=weights[b_itr])  {
          if(weights[a_itr]>weights[b_itr]) {
            merged.push_back(num[a_itr]);
            n_weights.push_back(weights[a_itr]);
            a_itr++;
          }
          else  {
            merged.push_back(num[b_itr]);
            n_weights.push_back(weights[b_itr]);
            b_itr++;
          }
        }
      else  {
        if(num[a_itr]>num[b_itr]) {
          merged.push_back(num[a_itr]);
          n_weights.push_back(weights[a_itr]);
          a_itr++;
        }
        else
          if(num[a_itr]<num[b_itr]) {
            merged.push_back(num[b_itr]);
            n_weights.push_back(weights[b_itr]);
            b_itr++;
          }
        else
          if(num[a_itr]==num[b_itr])  {
            merged.push_back(num[a_itr]);
            merged.push_back(num[b_itr]);
            n_weights.push_back(weights[a_itr]);
            n_weights.push_back(weights[b_itr]);
            a_itr++;
            b_itr++;
          }
      }
  }

  while(a_itr<=end_l) {
    merged.push_back(num[a_itr]);
    n_weights.push_back(weights[a_itr]);
    a_itr++;
  }

  while(b_itr<=end_r) {
    merged.push_back(num[b_itr]);
    n_weights.push_back(weights[b_itr]);
    b_itr++;
  }

  for(vector <int>:: iterator itm=merged.begin(),itwn=n_weights.begin(),itn=num.begin()+start_l,itw=weights.begin()+start_l;itm!=merged.end(),itwn!=n_weights.end();itm++,itwn++,itn++,itw++) {
    *itn=*itm;
    *itw=*itwn;
  }
  return;
} 

// }
//-----New functions end here-----

/* Question: You need to write the implementation of the given function.
             ( You may write any additional helper functions you want in the specified region only.
               Do not change the signature of the function already given)
               For detailed explanation of the question refer to the description part) 
*/

/*
   The function customSort takes a vector "num" of integers as an input along with the vector "weights" which contains the weights
   of the correponding integers. We wish to sort this vector "num" from the indices start to end based on the fact that numbers 
   with higher weights appear first and in case the weights are equal , we put the greater number first in the list. We check the 
   correctness of your function by calling your function with start index being equal to 0 and end being num.size()-1. Your aim is
   to complete the given function.
  
   We also wish efficient algorithms. We expect an O(n*log(n)) algorithm here instead of a O(n^2) one.
   (Hint : You can think this problem in lines of mergesort !!)

   For graded-test cases:

   The size of the vectors "num" and "weights" lies in the range 10000 to 100000.
   The entries of "num" and "weights" lie in the range 10 to 99.

   If your program takes too much time, you would get a timeout !! 
*/

void customSort(vector<int> & num,vector<int> & weights,int start,int end) {
    // Write your code here
  if(end-start==0)
    return;
  int start_l=start;
  int end_l=(start+end)/2;
  int start_r=(start+end)/2+1;
  int end_r=end;
  customSort(num,weights,start_l,end_l);
  customSort(num,weights,start_r,end_r);
  sortedMerge(num,weights,start_l,end_l,start_r,end_r);
 return;
}


int main()  {

  int n,c;
  cout<<"Enter size of vector:";
  cin>>n;
  vector <int> num, weights;

  cout<<"Enter number vector:";
  for(int i=0;i<n;i++)  {
    cin>>c;
    num.push_back(c);
  }

  cout<<"Enter weight vector:";
  for(int i=0;i<n;i++)  {
    cin>>c;
    weights.push_back(c);
  }  

  customSort(num,weights,0,n-1);
  cout<<"Sorted Vector-\n";
  for(vector <int>::iterator it=num.begin();it!=num.end();it++)
    cout<<*it<<" ";
  cout<<endl;


  return 0;
}

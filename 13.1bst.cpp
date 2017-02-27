#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

#include <math.h>
// #include "header.h"
string numberToString(int i)	{
	ostringstream oss;
	oss<<i;
	return oss.str();
}

struct binaryTree {
	int n;
	vector <int> a;

	binaryTree(int c)	{
		n=c;
		int num=pow(2,n+1)-1;
		for(int i=0;i<num;i++)
			a.push_back(-1);
	}
};

string preOrderRepn(struct binaryTree bst, int i)	{
	string s="";
	if(i<=(pow(2,bst.n+1)-2))	{
		if(bst.a[i]==0)
			return s;
		s=s+numberToString(bst.a[i])+","+preOrderRepn(bst,2*i+1);
		s=s+preOrderRepn(bst,2*i+2);
		if(i==0)	{
			s.replace(s.end()-1,s.end(),".");
		}
		return s;
	}
	else
		return s;
	
}

string postOrderRepn(struct binaryTree bst, int i)	{
	string s="";
		if(i<=(pow(2,bst.n+1)-2))	{
			if(bst.a[i]==0)
				return s;
			s=postOrderRepn(bst,2*i+1)+postOrderRepn(bst,2*i+2)+numberToString(bst.a[i])+",";
			if(i==0)	{
				s.replace(s.end()-1,s.end(),".");
			}
			return s;
		}
		else
			return s;
	
}

int height(struct binaryTree bst, int i)	{
		int h=1;
		if (i>=(bst.a).size())
			return 0;
		if(bst.a[i]==0)
			return 0;
		else
			return h+max(height(bst,2*i+1),height(bst,2*i+2));
}




int heightOfBinaryTree(struct binaryTree bst)	{
	return height(bst,0)-1;
}
	

int main()	{
	binaryTree bst(2);
	bst.a[0]=100;
	bst.a[1]=1;
	bst.a[2]=2;
	bst.a[3]=8;	
	bst.a[4]=8;	
	bst.a[5]=8;	
	bst.a[6]=8;
	// cout<<bst.a.size()<<endl;
	cout<<preOrderRepn(bst,0)<<endl;
	cout<<postOrderRepn(bst,0)<<endl;
	cout<<heightOfBinaryTree(bst)<<endl;
	return 0;
}
/* Question  Your task is to fill code in the function prefix_to_infix() **/
#include <iostream>
#include <stdio.h>
// #include <cstdlib>
#include <string>
#include <stack>
// #include <algorithm>
// #include "header.h"
// #include <vector>

using namespace std;


string prefix_to_infix(string expr) {
    // fill in this function
    // create extra functions if needed
	stack <string> s;
	int l=expr.length();
	string infix="";
	string temp="";
	for(int i=l-1;i>=0;i--)
	{
		const char c=expr.at(i);

		if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='%')
		{
			temp="("+s.top()+c;
			s.pop();
			temp=temp+s.top()+")";
			s.pop();
			s.push(temp);
		}
		else
		{
			s.push(string(1,expr.at(i)));
		}
	}	

	infix=s.top();
	return infix;
}


int main()	{

	string s;
	cin>>s;
	cout<<prefix_to_infix(s)<<endl;
	return 0;
}

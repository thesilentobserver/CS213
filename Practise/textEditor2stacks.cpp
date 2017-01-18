#include<iostream>
#include<stack>
#include<stdio.h>

using namespace std;

void moveLeft(stack <char> &left,stack <char> &right)
	{
		char c=left.top();
		left.pop();
		right.push(c);
		return;
	}

void moveRight(stack <char> &left,stack <char> &right)
	{
		char c=right.top();
		right.pop();
		left.push(c);
		return;
	}

void backspace(stack <char> &left)
	{
		left.pop();
		return;
	}

void deleteFunc(stack <char> &right)
	{
		right.pop();
		return;
	}

void findReplace(stack <char> &left,stack <char> &right,char f,char r)
	{
		while(!left.empty())
			moveLeft(left,right);

		while(!right.empty())
			{
				char c=right.top();
				right.pop();
				if(c==f)
					left.push(r);
				else
					left.push(c);
			}

		return;	
	}





int main()
	{
		stack <char> left,right;
		char input=' ';
		while(1)
			{
				cin>>input;
				// cout<<"Character read= "<<input<<'\n';
				if(input=='%')
					break;
				left.push(input);
			}
		cout<<"ORIGINAL:\n";
		cout<<"left stack= ";
		stack <char> l=left;
		for(int i=0;i<left.size();i++)
			{
				
				// cout<<"SIZE of l= "<<l.size();
				// cout<<"Inside first print";
				cout<<l.top();
				l.pop();
			}
		cout<<'\n';
			
		cout<<"right stack= ";
		stack <char> r=right;
		for(int i=0;i<right.size();i++)
			{
				cout<<r.top();
				r.pop();
			}
		cout<<'\n';
		
		moveLeft(left,right);
		l=left;
		cout<<"MOVE LEFT:\n";

		cout<<"left stack= ";
		for(int i=0;i<left.size();i++)
			{
				cout<<l.top();
				l.pop();
			}
		cout<<'\n';
			
		cout<<"right stack= ";
		r=right;
		for(int i=0;i<right.size();i++)
			{
				cout<<r.top();
				r.pop();
			}
		cout<<'\n';
		
		moveRight(left,right);
		cout<<"MOVE RIGHT:\n";
		
		cout<<"left stack= ";
		l=left;
		for(int i=0;i<left.size();i++)
			{
				cout<<l.top();
				l.pop();
			}
		cout<<'\n';
			
		cout<<"right stack= ";
		r=right;
		for(int i=0;i<right.size();i++)
			{
				cout<<r.top();
				r.pop();
			}
		cout<<'\n';
		
		moveLeft(left,right);
		cout<<"MOVE LEFT:\n";

		cout<<"left stack= ";
		l=left;
		for(int i=0;i<left.size();i++)
			{
				cout<<l.top();
				l.pop();
			}
		cout<<'\n';
			
		cout<<"right stack= ";
		r=right;
		for(int i=0;i<right.size();i++)
			{
				cout<<r.top();
				r.pop();
			}
		cout<<'\n';
		
		moveLeft(left,right);
		cout<<"MOVE LEFT:\n";

		cout<<"left stack= ";
		l=left;
		for(int i=0;i<left.size();i++)
			{
				cout<<l.top();
				l.pop();
			}
		cout<<'\n';
			
		cout<<"right stack= ";
		r=right;
		for(int i=0;i<right.size();i++)
			{
				cout<<r.top();
				r.pop();
			}
		cout<<'\n';
		
		backspace(left);
		cout<<"BACKSPACE:\n";

		cout<<"left stack= ";
		l=left;
		for(int i=0;i<left.size();i++)
			{
				cout<<l.top();
				l.pop();
			}
		cout<<'\n';
			
		cout<<"right stack= ";

		r=right;
		for(int i=0;i<right.size();i++)
			{
				cout<<r.top();
				r.pop();
			}
		cout<<'\n';
		
		deleteFunc(right);
		cout<<"DELETE:\n";

		cout<<"left stack= ";
		l=left;
		for(int i=0;i<left.size();i++)
			{
				cout<<l.top();
				l.pop();
			}
		cout<<'\n';
			
		cout<<"right stack= ";
		r=right;
		for(int i=0;i<right.size();i++)
			{
				cout<<r.top();
				r.pop();
			}
		cout<<'\n';
		
		findReplace(left,right,'a','A');
		cout<<"FIND AND REPLACE:\n";

		cout<<"left stack= ";
		l=left;
		for(int i=0;i<left.size();i++)
			{
				cout<<l.top();
				l.pop();
			}
		cout<<'\n';
			
		cout<<"right stack= ";
		r=right;
		for(int i=0;i<right.size();i++)
			{
				cout<<r.top();
				r.pop();
			}
		cout<<'\n';
		
		return 0;
	}
// #include "header.h"
/*
  Do not remove the "header.h" file.
*/

//-----Include any additional required headers here-----
#include <stack>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

//-----End of additional headers-----

//-----Add new functions here(if any)-----


//-----New functions end here-----

/* Question: You need to write the implementation of the given function.
             ( You may write any additional helper functions you want in the specified region only.
               Do not change the signature of the function already given)
               For detailed explanation of the question refer to the Description part) 
*/

/*
   The function reverseWordsOfSentence takes a sentence (string) as an input and then returns a string with 
   the words of the sentence present from end to the beginning in order seperated by spaces 
*/

string reverseWordsOfSentence(string sentence) {
    // Write your code here
	stack <char> revWord;
	int len=sentence.length();
	string revSentence;
	int count=0;

	for(int i=len-1;i>=0;i--)
		{
			if(sentence.at(i)==' ')
				{
					while(!revWord.empty())
						{
							char c=revWord.top();
							revSentence+=c;
							revWord.pop();
						}
					revSentence+=" ";
				}
			else
				{
					revWord.push(sentence.at(i));
				}
		}

	// For the first word starting at i=0,at which the loop terminates

	while(!revWord.empty())
		{
			char c=revWord.top();
			revSentence+=c;
			revWord.pop();
		}

	return revSentence;
}


int main()
	{
		string sentence;
		getline(cin,sentence);
		cout<<reverseWordsOfSentence(sentence);
		return 0;
	}
	
//-----Include required headers here-----
// #include<iostream>
#include<string>
using namespace std;
//-----End of headers-----


//-----Add new functions here(if any)-----

//-----New functions end here-----

/* Question : Function to convert a given binary string to 
gray code string as explained in the problem description. */
string binarytoGray(string binary) {
    // Write your code below this line.
    int len=binary.length();
    string gray="";
    gray.append(binary,0,1);

    for(int i=1;i<len;i++)
    	{
    		if(binary[i]!=binary[i-1])
    			gray.append("1");
    		else
    			gray.append("0");
      	}

    return gray;
}
 
/* Question : Function to convert a gray code string to 
binary string as explained in the problem description. */
string graytoBinary(string gray) {
    // Write your code below this line.
    int len=gray.length();
    string binary="";
    binary.append(gray,0,1);

    for(int i=1;i<len;i++)
    	{	
    		if(gray.at(i)=='0')
    			binary.append(binary,i-1,1);
    		else
    			{
    				if(binary.at(i-1)=='0')
    					binary.append("1");
    				else
    					binary.append("0");
       			}
    	}

    return binary;
}

/*
int main()
	{
		string bin="01001";
		cout<<binarytoGray(bin)<<" "<<graytoBinary(binarytoGray(bin));
		return 0;
	}
*/
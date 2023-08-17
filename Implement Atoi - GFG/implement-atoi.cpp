//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int sign=1,i=0;
        
        if(s[0]=='-')
        {
            sign=-1;
            ++i;
        }
        int res=0;
        for(int j=i;j<s.size();j++)
        {
            int a=s[j]-'0';
            if(a>=0 && a<=9)
            res=(res*10)+a;
            else
            return -1;
        }
        return res*sign;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends
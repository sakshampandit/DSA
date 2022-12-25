//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:
    static bool Compare(struct val p1, struct val p2){
        if(p1.second < p2.second)
        return true;
        else
        return false;
    }
    
    /*You are required to complete this method*/
    int maxChainLen(struct val p[],int n){
     
        sort(p,p+n,Compare);
        int count = 1;
        int j = 1;
        int d = p[0].second;
        while(j<n){
            if(p[j].first > d){
                count++;
                d = p[j].second;
            }
            j++;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends
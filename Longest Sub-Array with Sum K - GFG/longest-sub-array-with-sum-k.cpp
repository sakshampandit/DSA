//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        // int sum=0,ans=0;
        // unordered_map<int,int>mp;
        // mp[0]=-1;
        // int i=0;
        // while(i<N)
        // {
        //     sum+=A[i];
        //     if(mp.find(sum-k)!=mp.end())
        //     {
        //         ans=max(ans,i-mp[sum-k]);
        //     }
        //     if(mp.find(sum)==mp.end())
        //       mp[sum]=i;
        //       i++;
        // }
        // return ans; 
        unordered_map<int,int>m;
        m[0]=-1;
        int sum=0,ans=0;
        int i=0;
        while(i<N)
        {
            sum+=A[i];
            if(m.find(sum-K)!=m.end())
            {
                ans=max(ans,i-m[sum-K]);
            }
            if(m.find(sum)==m.end())
            m[sum]=i;
            i++;
        }
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
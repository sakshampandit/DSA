//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string a[], int n)
    {
        // your code here
        if(n==0)
        return "-1";
        if(n==1)
        return a[0];
        sort(a,a+n);
        int l=min(a[0].size(),a[n-1].size());
        int i=0,c=0;
        while(i<l&&a[0][i]==a[n-1][i])
        {
            i++;
            c++;
        }
        if(c==0)
        return "-1";
        return a[0].substr(0,c);
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
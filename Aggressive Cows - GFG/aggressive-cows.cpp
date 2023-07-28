//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool possible(vector<int>&stalls,int n,int mid,int k)
    {
        int cord=stalls[0],c=1;
        for(int i=1;i<n;i++)
        {
            if(stalls[i]-cord>=mid)
            {
                c++;
                cord=stalls[i];
            }
            if(c==k)
            return true;
            
            
        }
        return false;
          }
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        // Write your code here
        int lo=1;
        int hi=stalls[n-1]-stalls[0];
        
        while(lo<=hi)
        {   int mid=lo+(hi-lo)/2;
            if(possible(stalls,n,mid,k)==true)
            {
            lo=mid+1;
            }
            else
            {
                hi=mid-1;
            }
        }
        return hi;
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
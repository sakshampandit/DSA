//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int dp(int idx,int n,vector<vector<int>> &intervals,vector<int> &memo){
        if(idx>=n) return 0;
        if(memo[idx]!=-1) return memo[idx];
        int ans=dp(idx+1,n,intervals,memo);
        int l=0,r=n-1,new_idx=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(intervals[idx][1]<=intervals[mid][0]){
                new_idx=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,dp(new_idx,n,intervals,memo)+intervals[idx][2]);
        return memo[idx]=ans;
    }
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        // Write your code here.
        sort(intervals.begin(),intervals.end());
        vector<int> memo(n+5,-1);
        return dp(0,n,intervals,memo);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends
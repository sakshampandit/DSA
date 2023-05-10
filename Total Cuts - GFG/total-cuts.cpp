//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int n,int K,vector<int> &A){
        vector<int> rightMin(n);
        rightMin[n-1] = INT_MAX;
        for(int i = n-2; i >= 0; --i)
            rightMin[i] = min(rightMin[i+1],A[i+1]);
        int cuts = 0,leftMax = 0;
        for(int i = 0; i < n-1; ++i){
            leftMax = max(leftMax,A[i]);
            int sum = leftMax + rightMin[i];
            if(sum >= K) ++cuts;
        }
        return cuts;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends
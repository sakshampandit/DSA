//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int sumSubarrayMins(int n, vector<int> &a) {
        // code here
        stack<int>s;
        vector<int>left(n,-1);
        vector<int>right(n,n);
        
        for(int i=0;i<n;i++)
        {
            while(!s.empty()&& a[s.top()]>=a[i])
            s.pop();
            if(!s.empty())
            left[i]=s.top();
            
            s.push(i);
        }
        s=stack<int>();
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && a[s.top()]>a[i])
            s.pop();
            if(!s.empty())
            right[i]=s.top();
            
            s.push(i);
        }
        long long res=0;
        for(int i=0;i<n;i++)
        {
            int l=i-left[i];
            int r=right[i]-i;
            res+=(a[i]*l*r);
            res%=1000000007;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
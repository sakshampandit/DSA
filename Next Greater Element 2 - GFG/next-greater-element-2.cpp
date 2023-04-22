//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int n, vector<int>& arr) {
        // code here
        int ele;
        stack<int>s;
        vector<int>ans(n,-1);
        for(int i=2*n-1;i>=0;i--)
        {
            ele=arr[i%n];
            while(!s.empty() && s.top()<=ele)
            s.pop();
            if(i<n)
            ans[i]=(s.empty())?-1:s.top();
            s.push(ele);
        }
        return ans;
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
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
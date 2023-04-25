//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string nums, int k) {
        stack<int>s;
        int n=nums.size();
        for(char c:nums)
        {
            while(!s.empty() && k>0 && s.top()>c)
            {   
                s.pop();
                k--;
            }
            if(!s.empty()|| c!='0')
            s.push(c);
        }
        
        while(!s.empty() && k--)
        {
          s.pop();   
        }
        
        // string ans = "";
        while(!s.empty())
        {
            nums[n-1] = (s.top());
            s.pop();
            n--;
        }
        
        
        // reverse(ans.begin(), ans.end());
        // return ans == "" ? "0" : ans;
        // cout << ans;
        if(n < nums.size())
            return nums.substr(n);
        // if(s.empty())
        return "0";
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        // code here'
        string ans;
        stack<char>st;
        for(auto x:s)
        {
            if(x=='(')
            {
                if(st.size()>0)
                ans.push_back(x);
                
                st.push(x);
            }
            else
            {
                st.pop();
                if(!st.empty())
                ans.push_back(x);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends
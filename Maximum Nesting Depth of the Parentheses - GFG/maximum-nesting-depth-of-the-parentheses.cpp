//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string s) {
        // code here
        int ans=0,c=0;
        for(int i=0;i<s.size();i++)
        {
            ans=max(ans,c);
            if(s[i]=='(')
            c++;
            else  if(s[i]==')')
            c--;
        }
        return ans;
        // ans=3
        // c=0
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
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
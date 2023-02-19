//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) {
        // Code here
        int a=-1,b=-1,c=-1;
        int co=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a')
            a=i;
            else if(s[i]=='b')
            b=i;
            else
            c=i;
            co+=min(c,min(a,b))+1;
                    }
                    return co;
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
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends
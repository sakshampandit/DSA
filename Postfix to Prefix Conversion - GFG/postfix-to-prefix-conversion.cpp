//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string s) {
        // Write your code here
        stack<string>st;
        string t;
        for(int i=0;i<s.size();i++)
        {
            if(isalpha(s[i]))
            {   
                string temp;
                temp+=s[i];
                st.push(temp);
            }
            else
            {
                string s1=st.top();
                st.pop();
                string s2=st.top();
                st.pop();
                t=s[i]+s2+s1;
                st.push(t);
            }
            
        }
        return t;
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends
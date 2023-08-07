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
        // ABC/-AK/L-*
        // ABC
        // A/BC
        // -A/BC AK
        // -A/BC /AK L
        // -A/BC -/AKL
        // *-A/BC-/AKL
        string res="";
        stack<string>st;
        // reverse(s.begin(),s.end());
        for(auto c:s)
        {
            if(isalnum(c))
            {
                string temp;
                temp+=c;
                st.push(temp);
            }
            else
            {
                string s1=st.top();
                st.pop();
                string s2=st.top();
                st.pop();
                string t=c+s2+s1;
                st.push(t);
            }
        }
        res=st.top();
        return res;
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
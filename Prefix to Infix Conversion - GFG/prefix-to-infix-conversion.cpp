//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string s) {
        // Write your code here
        stack<string>st;
        reverse(s.begin(),s.end());
        string t;
        for(int i=0;i<s.length();i++)
        { if(isalpha(s[i])){
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
           t= '('+s1+s[i]+s2+')';
            st.push(t);
        }
        }
        return  t;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends
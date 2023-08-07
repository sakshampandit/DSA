//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int precedence(char c)
    {
        if(c=='^')
        return 3;
        else if(c=='/'|| c=='*')
        return 2;
        else if(c=='+'||c=='-')
        return 1;
        else
        return -1;
    }
    string infixToPostfix(string s) {
        // Your code here
        stack<char>st;
        string res="";
        for(int i=0;i<s.size();i++)
        {   
            // CONDITION 1
            if(isalnum(s[i]))
            res+=s[i];
            // CONDITION 2
            else if(s[i]=='(')
            st.push(s[i]);
            
            // CONDITION 3
            else if(s[i]==')')
            {
                while(!st.empty() && st.top()!='(')
                {
                    res+=st.top();
                    st.pop();
                }
                if(!st.empty())
                st.pop();
            }
            // CONDITION 4
            else 
            {
                while(!st.empty() && precedence(st.top())>=precedence(s[i]))
                {
                    res+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty())
        {
            res+=st.top();
            st.pop();
        }
        return res;
    }
};




//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends
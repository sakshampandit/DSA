//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string s) {
        // your code here
        string ans;
        int maxi=-1,flag=0;
        for(int i=0;i<s.size();i++)
        {
            if((s[i]-'0')%2!=0)
            {   flag=1;
                maxi=i;
            }
        }if(flag==0)
        return "";
        else
        return s.substr(0,maxi+1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends
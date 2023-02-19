//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    unordered_map<char,int> m;
    int i=0,j=0,n=s.size(),maxi=-1;
    while(j<n)
    {
        if(m.find(s[j])!=m.end())
        m[s[j]]++;
        else
        m[s[j]]=1;
        
        if(m.size()==k)
        {
            maxi=max(maxi,j-i+1);
        }
        if(m.size()>k)
        {
            while(m.size()>k)
            {
                m[s[i]]--;
                if(m[s[i]]==0)
                m.erase(s[i]);
                i++;
            }
        }
        j++;
    }
    return maxi;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends
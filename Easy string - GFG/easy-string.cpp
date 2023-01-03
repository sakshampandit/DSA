//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string transform(string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << transform(s) << endl;
    }
return 0;
}


// } Driver Code Ends


string transform(string s) {
    string ans = "";
    int cnt = 1;
    s.push_back('#');

    for (int i = 0; i < s.length()-1; i++)
    {
        if( tolower(s[i]) == tolower(s[i+1]) ) 
            cnt++;
        else {
            ans += to_string(cnt);
            ans.push_back(tolower(s[i]));
            cnt = 1;
        }
    }
    
    return ans;
}


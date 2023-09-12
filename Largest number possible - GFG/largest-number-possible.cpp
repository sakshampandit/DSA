//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        string ans="";
        if(N*9<S){
            return "-1";
        }
        if(S==0 && N>1){
            return "-1";
        }
        while(N!=0){
            if(S>=9 && N>0){
                ans+='9';
                S=S-9;
                N=N-1;
            }
            else if(S==0 && N>0){
                ans+='0';
                N=N-1;
            }
            else if(S<9 && N==1){
                ans+=S+'0';
                N=0;
            }
            else if(S<9 && N>1){
                ans+=S+'0';
                N=N-1;
                S=0;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
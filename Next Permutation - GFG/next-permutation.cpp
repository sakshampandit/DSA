//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // void swap(int p,int q)
    // {
    //     int temp=p;
    //     p=q;
    //     q=temp;
    //     return;
    // }
    vector<int> nextPermutation(int n, vector<int> a){
        // code here
        int inf=-1;
        for(int i=n-1;i>0;i--)
        {
            if(a[i]>a[i-1])
            {
                inf=i;
                break;
            }
        }
        if(inf==-1)
        { 
            reverse(a.begin(),a.end());
            return a;
        }
        else
        {   
            // x=3 prev=5
            int prev=inf;
        //   int x=a[inf-1];
        //   cout<<x<<endl;
        //   cout<<a[prev]<<endl;
            for(int i=inf+1;i<n;i++)
            {
                if(a[i]>a[inf-1] and a[i]<=a[prev])
                prev=i;
            }
            // cout<<x<<endl;
            // cout<<a[prev]<<endl;
            swap(a[inf-1],a[prev]);
            // cout<<x<<endl;
            // cout<<a[prev]<<endl;
            // cout<<x<<endl;
            reverse(a.begin()+inf,a.end());
            return a;
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
    priority_queue<int,vector<int>,greater<int>>pq;
    int x=0;
    for(int i=0;i<N;i++)
    {
        pq.push(arr[i]);
    }
    map<int,int>m;
    while(!pq.empty())
    {   int val=pq.top();
        pq.pop();
        if(m.find(val)==m.end())
        {x=x+1;
        m[val]=x;}
    
    }
    vector<int>v;
    for(int i=0;i<N;i++)
    {
        v.push_back(m[arr[i]]);
    }
return v;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
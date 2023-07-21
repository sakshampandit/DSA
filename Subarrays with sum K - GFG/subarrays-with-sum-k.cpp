//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int nums[], int n, int k)
    {
        // code here
        unordered_map<int,int>mp;
        int i,sum=0,count=0;
        mp[0]=1;
        for(i=0;i<n;i++)
        {
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end())
               count+=mp[sum-k];
            //    else
               mp[sum]++;
//             i=2  sum=3 count=2  
//             0 1
//             1 1
            


        }
        return count;  
    }
    // i=4 ans=3  sum=10 k=10
    // 0  2
    // 1  1
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
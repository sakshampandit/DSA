//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>a, int n, int k)
    {
        // code here
        int l=0,r=n-1,mid,ans=n;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            if(a[mid]<k)
            l=mid+1;
            else if(a[mid]>=k)
            {
                ans=mid;
                r=mid-1;
            }
        }
        return ans;
         //  l=2 r=1 mid=2 ans=2 
        //   l=1 r=0 mid=0 ans=1
    }
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
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
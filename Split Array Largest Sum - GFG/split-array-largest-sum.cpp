//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   
        // code here
    int possible(int a[],int n,int k,int mid)
    {
        int c=1,sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            if(sum>mid)
            {
                c++;
                sum=a[i];
            }
        }
        return c<=k;
    }
    int splitArray(int a[] ,int n, int k) {
        
        int l,mid,r,sum=0,ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
        }
        l=*max_element(a,a+n);
        r=sum;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            if(possible(a,n,k,mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
        // n=4,k=1
        // l=9 r=23 mid=16
        // sum=9   ,c=1
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
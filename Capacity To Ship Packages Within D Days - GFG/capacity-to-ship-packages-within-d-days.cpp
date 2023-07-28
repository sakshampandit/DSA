//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int days(int a[],int mid,int n)
    {
        int load=0;
        int d=1;
        for(int i=0;i<n;i++)
        {
            if(load+a[i]>mid)
            {
                d+=1;
                load=a[i];
            }
            else
            load+=a[i];
        }
        return d;
    }
    int leastWeightCapacity(int a[], int n, int d) {
        // code here
        int l=*max_element(a,a+n);
        int r=accumulate(a,a+n,0);
        int mid;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            if(days(a,mid,n)<=d)
            {
                r=mid-1;
                
            }
            else
            l=mid+1;
        }
        return l;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

 class Solution {
  public:
  bool possible(int arr[],int n,int mid,int students)
  {
      int sum=0,d=1;
      for(int i=0;i<n;i++)
      {
          sum+=arr[i];
          if(sum>mid)
          {
              d++;
              sum=arr[i];
          }
      }
      return d<=students;
  }
int findPages(int arr[], int n, int m) 
     {   // code here
        int maxi=0,sum=0;
        for(int i=0;i<n;i++)
        {   sum+=arr[i];
            maxi=max(maxi,arr[i]);
        }
        if(n==m)
        return maxi;
        int lo=maxi;
        int hi=sum;
        int ans=0;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(possible(arr,n,mid,m)==true)
            {
                ans=mid;
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }if(m>n)
        return -1;
        else
        return ans;
 }
        
    };


//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends
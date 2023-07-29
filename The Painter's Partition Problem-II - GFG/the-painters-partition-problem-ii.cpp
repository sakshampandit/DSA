//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool possible(int a[],int n ,int k,long long mid)
        {
            long long sum=0,c=1;
            for(int i=0;i<n;i++)
            {   sum+=a[i];
                if(sum>mid)
                {
                    c++;
                    sum=a[i];
                }
            }
            return c<=k;
        }
    long long minTime(int a[], int n, int k)
    {
       long long l,mid,r,sum=0,ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            
        }
        l=*max_element(a,a+n),r=sum;
        if(n==k)
        return l;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            if(possible(a,n,k,mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        // }if(k>n)
        // return -1;
        // else
        return ans;
        // n=2 k=1
        // sum=5 l=5 r=5 mid=5
    }
    };

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends
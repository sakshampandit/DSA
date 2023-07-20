//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int a[], int n) {
	    // code here
	    int x[n];
	    int y[n];
	    int c=0,d=0;
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]>=0)
	         x[c++]=a[i];
	         else
	         y[d++]=a[i];
	    }
	    int p=0,q=0,r=0;
	    while(p<c && q<d)
	    {
	        a[r++]=x[p++];
	        a[r++]=y[q++];
	    }
	    while(p<c)
	    {
	        a[r++]=x[p++];
	    }
	    while(q<d)
	    {
	        a[r++]=y[q++]; 
	    }
	    
	}
// 9 4 5 0 2	
// -2 -1 -5 -3
// 9 -2 4 -1 5
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
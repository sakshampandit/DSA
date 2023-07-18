//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	void pushZerosToEnd(int nums[], int n) {
	    // code here
	    int c=0;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                c++;
            else
            ans.push_back(nums[i]);
        }
        for(int i=0;i<c;i++)
        {
            ans.push_back(0);
        }
       
        for(int i=0;i<ans.size();i++)
            nums[i]=ans[i];
	}
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
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
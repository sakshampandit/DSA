//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long subarrayRanges(int n, vector<int> &a) {
        // code here
        long long sum=0;
        for(int i=0;i<n;i++)
        {  int mini=a[i];
           int maxi=a[i];
            for(int j=i;j<n;j++)
            {
                mini=min(mini,a[j]);
                maxi=max(maxi,a[j]);
                sum+=maxi-mini;
            }
        }
        return sum;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayRanges(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
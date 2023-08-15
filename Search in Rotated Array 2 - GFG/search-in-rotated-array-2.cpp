//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int n, vector<int>& a, int key) {
        // Code here
        int l=0,r=n-1,mid;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            if(a[mid]==key)return true;
            else if(a[l]==a[mid] && a[mid]==a[r])
            {
                l=l+1;
                r=r-1;
            }
            else if(a[l]<=a[mid])
            {
                if(key>=a[l] && key<a[mid])
                r=mid-1;
                else
                l=mid+1;
            }
            else
            {
                if(key>a[mid] && key<=a[r])
                {
                    l=mid+1;
                }
                else
                r=mid-1;
            }
        }
        return false;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends
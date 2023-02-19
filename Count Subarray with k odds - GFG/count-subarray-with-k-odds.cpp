//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        int sum=0,c=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            nums[i]=0;
            else
            nums[i]=1;
        }
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum==k)
            c++;
            if(m.find(sum-k)!=m.end())
            c+=m[sum-k];
            if(m.find(sum)!=m.end())
            m[sum]++;
            else
            m[sum]=1;
        }
        return c;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends
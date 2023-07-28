//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int Solve(int N, vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(left<=right)
        {
            int mid=(left+right)/2;
            int time=timefunc(mid,piles);
            if(time<=h)
            {
                ans=mid;
                right=mid-1;
            }else
            {
                left=mid+1;
            }
        }
        return ans;
    }
    
    int timefunc(int mid,vector<int> piles)
    {
        int hours=0;
        for(int i=0;i<piles.size();i++)
        {
        //   hours+=(piles[i]/mid)+((piles[i]%mid)!=0);
        hours+=ceil((double)piles[i]/mid);
        }
        return hours;
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
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
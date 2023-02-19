//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long maxScore(vector<int> &cardPoints, int n, int k) {
        // code here
        int ans=0,score=0,s=0;
        vector<int> sum(n,0);
        for(int i=0;i<n;i++)
        {
            s+=cardPoints[i];
            sum[i]=s;
        }
        if(n==k)
        return s;
        for(int i=0;i<=k;i++)
        {
            int j=i+n-k-1;
            if(i==0)
            ans=sum[j];
            else
            ans=sum[j]-sum[i-1];
            
            score=max(score,s-ans);
        }
        return score;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends
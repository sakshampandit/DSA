//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxChildren(int n, int m, vector<int> &greed, vector<int> &cookie) {
        // code here
        int curr=0,total=0,i=0;
        sort(greed.begin(),greed.end());
        sort(cookie.begin(),cookie.end());
        while(i<n && curr<m)
        {
            if(greed[i]<=cookie[curr])
            {
                total++;
                curr++;
                i++;
            }
            else
            curr++;
        }
        return total;
    }
};

//         while(p < greed.size() && q < sz.size()) {
//             if(sz[q] >= greed[p]) {
//                 count++; p++; q++;
//             } else q++;
//         }
//         return count;
//     }

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<int> greed(N), sz(M);
        for (int i = 0; i < N; i++) {
            cin >> greed[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> sz[i];
        }
        Solution obj;
        cout << obj.maxChildren(N, M, greed, sz) << endl;
    }
    return 0;
}
// } Driver Code Ends
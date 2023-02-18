//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int n, vector<int> &fruits) {
        int i=0,j=0,ans=0;
        map <int,int> m;
        while(j<n)
        {
            m[fruits[j]]++;
            while(m.size()>2)
            {
            if(m[fruits[i]]==1)
            {
                m.erase(fruits[i]);
            }
            else
            {
                m[fruits[i]]--;
            }
            i++;
            }
        ans=max(ans,j-i+1);
        j++;
        }
    
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends
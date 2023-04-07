//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        // code here
        if(N%groupSize!=0)
        return false;
        priority_queue<int,vector<int>,greater<int>>pq;
        map<int,int>m;
        for(auto it:hand)m[it]++;
        for(auto it:m)pq.push(it.first);
        while(!pq.empty())
        {
            int top=pq.top();
            for(int i=top;i<top+groupSize;i++)
            {
                if(m.find(i)==m.end())
                return false;
                m[i]--;
                if(m[i]==0)
                {
                    if(i!=pq.top())
                    {
                        return false;
                    }
                    pq.pop();
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
   static bool comp(pair<int,int>a,pair<int,int>b)
    {
        if(a.second==b.second)return a.first<b.first;
        else
        return a.second<b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++)
        {
            v[i]={start[i],end[i]};
        }
        sort(v.begin(),v.end(),comp);
        int c=1,i=0,j=1;
        while(j<n)
        {
            if(v[i].second<v[j].first)
            {
                c++;
                i=j;
                j++;
            }
            else
            j++;
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
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
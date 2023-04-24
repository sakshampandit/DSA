//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int> &asteroids) {
        // code here
        stack<int>s;
        int i=0;
        while(i<n)
        {
            if(s.empty())
            {
                s.push(asteroids[i]);
                ++i;
            }
            else
            {
                if((s.top()>0 && asteroids[i]>0)||(s.top()<0 && asteroids[i]<0)||(s.top()<0 && asteroids[i]>0))
                {
                    s.push(asteroids[i]);
                    i++;
                }
                else if(s.top()>0 && asteroids[i]<0)
                {
                    int a=s.top();
                    int b=(asteroids[i]);
                    s.pop();
                    if(a==abs(b))
                    {
                        i++;
                    }
                    else if(a<abs(b))
                    {
                        
                        continue;
                    }
                    else{
                    s.push(a);    
                    i++;}
                }
            }
        }
        vector<int>ans;
        while(!s.empty())
        {
            int x=s.top();
            ans.push_back(x);
            s.pop();        
            
        }
            reverse(ans.begin(),ans.end());
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

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
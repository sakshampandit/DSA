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
        {   //if the stack is empty then push asteroid
            if(s.empty())
            {
                s.push(asteroids[i]);
                ++i;
            }
            else
            {   
                // conditions
                // 1) if both are  + +,-- then they are in same direction
                // 2) if stack element is negative and asteroid is positive because negative in stack means 
                //    and asteroid in +ve they are going in opp direction
                if((s.top()>0 && asteroids[i]>0)||(s.top()<0 && asteroids[i]<0)||(s.top()<0 && asteroids[i]>0))
                {
                    s.push(asteroids[i]);
                    i++;
                }
                 // the only condition where they collide is stack is +ve and asteroid is -ve
                else if(s.top()>0 && asteroids[i]<0)
                {
                    int a=s.top(); // asteroid in stack
                    int b=(asteroids[i]);// asteroids outside stack
                    s.pop();
                    // both are equal
                    if(a==abs(b))
                    {
                        i++;
                    }
                    // outside asteroid is bigger then we require more asteoid from stack to destroy it
                    else if(a<abs(b))
                    {
                        
                        continue;
                    }
                    else{
                   // if stack in asteroid has destroyed outside stack then push that stack again 
                    s.push(a);    
                    i++;}
                }
            }
        }
        // push all the remaining asteroids in vector
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
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{  vector<int> nextSmallerElement(long long arr[], int n){
      stack<int> st;
      st.push(-1);
      vector<int> ans(n);

      for(int i=n-1; i>=0; i--){
          int curr = arr[i];
          while(st.top() != -1 && arr[st.top()]>=curr){
              st.pop();
          }
          //ans is store ka top
          ans[i] = st.top();
          st.push(i);
      }
      return ans;
    }
    vector<int> prevsmallerElement(long long arr[], int n){
      stack<int> st;
      st.push(-1);
      vector<int> ans(n);

      for(int i=0; i<n; i++){
          int curr = arr[i];
          while(st.top() != -1 && arr[st.top()]>=curr){
              st.pop();
          }
          //ans is store ka top
          ans[i] = st.top();
          st.push(i);
      }
      return ans;
    }
    public:
    long long getMaxArea(long long arr[], int n)
    {

        vector<int> next(n);
        next = nextSmallerElement(arr,n);

        vector<int> prev(n);
        prev = prevsmallerElement(arr,n);

        long long area = INT_MIN;

        for(int i=0; i<n; i++){
            long long l = arr[i];

            if(next[i] == -1){
                next[i] = n;
            }
            long long b = next[i] - prev[i] - 1;
            long long newArea = l*b;
            area = max(area,newArea);

        }
        return area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends
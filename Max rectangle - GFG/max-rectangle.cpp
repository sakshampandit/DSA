//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
   vector<int> nextSmallerElement(int arr[], int n){
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
    vector<int> prevsmallerElement(int arr[], int n){
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
    int maxhist(int arr[], int n)
    {

        vector<int> next(n);
        next = nextSmallerElement(arr,n);

        vector<int> prev(n);
        prev = prevsmallerElement(arr,n);

        int area = INT_MIN;

        for(int i=0; i<n; i++){
            int l = arr[i];

            if(next[i] == -1){
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area,newArea);

        }
        return area;
    }
    int maxArea(int a[MAX][MAX], int n, int m){
        // int curRow[n]=a[0];
        // vector<int>ans;
        int maxAns=maxhist(a[0],m);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1)
                {
                    a[i][j]+=a[i-1][j];
                }
            }
            int curAns=maxhist(a[i],m);
            maxAns=max(maxAns,curAns);
        }
        return maxAns;
    }
    
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends
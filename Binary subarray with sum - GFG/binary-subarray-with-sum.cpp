//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int numberOfSubarrays(vector<int>& nums, int N, int goal){
        // code here
        int sum=0,c=0;
        unordered_map<int,int> m;
        for(int i=0;i<N;i++)
        {   sum+=nums[i];
            if(sum==goal)
            c++;
            if(m.find(sum-goal)!=m.end())
            c+=m[sum-goal];
            if(m.find(sum)!=m.end())
            m[sum]++;
            else
            m[sum]=1;
        }
        return c;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends
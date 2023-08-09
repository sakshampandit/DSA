//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int a[], int n){
        // code here
        stack<int>s;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && a[s.top()]<a[i])
            {
                int ele=s.top();
                s.pop();
                if (!s.empty())
                {
                     int ele2 = s.top();
                     int distance = i - ele2 - 1;
                     int bounded_height = min(a[ele2], a[i]) - a[ele];
                     ans +=bounded_height * distance;
                }
            }
            s.push(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends
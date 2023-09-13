//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
	int perfectSum(int ar[], int n, int sum)
	{
        int mod=1e9+7;
        int dp[n+1][sum+1];
        int zero=1;
        vector<int>arr;
        int k=0;
        for(int i=0;i<n;i++) {
            if(ar[i]!=0) arr.push_back(ar[i]),k++;
            else  zero=(zero*2)%mod;;
        }
        n=k;
        
        for(int i=0;i<=sum;i++){
            dp[0][i]=0;
        }
      
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        
    
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j>=arr[i-1]) dp[i][j]=(dp[i-1][j]+dp[i-1][j-arr[i-1]])%mod;
                else dp[i][j]=dp[i-1][j]%mod;
            }
        }
       dp[n][sum]=(dp[n][sum]*zero)%mod;
        return dp[n][sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
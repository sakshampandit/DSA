//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.length();
    int dp[n+1][n+1];

    // Initialize the table with 0s
    memset(dp, 0, sizeof(dp));

    // Fill the table using bottom-up approach
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // If characters match and indices are not the same
            if (str[i-1] == str[j-1] && i != j)
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // The last element of the table will contain the length of the longest repeating subsequence
    return dp[n][n];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
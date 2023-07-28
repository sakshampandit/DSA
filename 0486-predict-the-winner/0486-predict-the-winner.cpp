class Solution {
public:
    int f( vector<int> &nums,int i,int j,   vector<vector<int>> &dp){
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];

        int a = nums[i] + min(f(nums,i+2,j,dp),f(nums,i+1,j-1,dp));
        int b = nums[j] + min(f(nums,i,j-2,dp),f(nums,i+1,j-1,dp));
        dp[i][j] = max(a,b);
        return dp[i][j];
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int sum =0;
        for( auto i : nums){
            sum+= i;
        }
         int ans = f(nums,0,n-1,dp);
         int ans2 = sum -ans;
         return ans>=ans2;
         
        
    }
};
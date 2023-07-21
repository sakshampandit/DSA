class Solution {
public:

    int findNumberOfLIS(vector<int>& nums) {
       int n=nums.size();

       vector<int>dp(n,1),ct(n,1); 
       int mx_len=0;

       for(int i=0;i<n;i++){
           for(int j=i-1;j>=0;j--){
               if(nums[i]>nums[j]){
                   if(dp[i]<1+dp[j]){
                       ct[i]=ct[j];
                   }else if(dp[i]==1+dp[j]){
                       ct[i]+=ct[j];
                   }
                   dp[i]=max(dp[i],1+dp[j]);
               }
           }
           mx_len=max(mx_len,dp[i]);
       }
       int ans=0;
       for(int i=0;i<n;i++)if(dp[i]==mx_len)ans+=ct[i];

       return ans;
    }
};
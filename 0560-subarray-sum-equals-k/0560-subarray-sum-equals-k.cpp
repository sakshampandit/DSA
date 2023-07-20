class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int i,sum=0,count=0;
        mp[0]=1;
        for(i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end())
               count+=mp[sum-k];
            //    else
               mp[sum]++;
            
            


        }
        return count;  
        
    }
};
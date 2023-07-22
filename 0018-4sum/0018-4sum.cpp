class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        // long long  sum=0;
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int low=j+1;
                int high=nums.size()-1;
                while(low<high)
                {
                   
                  long long sum=(long long)nums[i]+nums[j]+nums[low]+nums[high];
                    if(sum==target)
                    {
                        s.insert({nums[i],nums[j],nums[low],nums[high]});
                        low++;
                        high--;
                    }
                    else if(sum>target)
                        high--;
                    else
                        low++;
                    
                }
            }
        }
        for(auto it:s)
            ans.push_back(it);
        return ans;
    }
};
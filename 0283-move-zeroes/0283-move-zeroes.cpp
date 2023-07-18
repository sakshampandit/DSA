class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int c=0;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                c++;
            else
            ans.push_back(nums[i]);
        }
        for(int i=0;i<c;i++)
        {
            ans.push_back(0);
        }
        nums.clear();
        for(int i=0;i<ans.size();i++)
            nums.push_back(ans[i]);
    }
};
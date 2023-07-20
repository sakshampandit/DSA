class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=0;
        map<int,int>m;
        vector<int>v;
       for(int i=0;i<nums.size();i++)
       {
           m[nums[i]]=j++;
           
       }
       for(int i=0;i<nums.size();i++){
        if(m.find(target-nums[i])!=m.end() && (i!=m[target-nums[i]]))
        {
           v.push_back(i);
           v.push_back(m[target-nums[i]]);
            break;
        }
           
        }
        return v;
    }
};
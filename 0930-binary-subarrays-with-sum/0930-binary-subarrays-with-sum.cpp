class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //j=0 n=5 sum=0 goal=0 ans=2
        int sum=0,c=0;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
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
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int sum=0,n=nums.size(),c=0;
        unordered_map <int,int>m;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
                nums[i]=0;
            else
                nums[i]=1;
        }
        for(int i=0;i<n;i++)
        {   sum+=nums[i];
            if(sum==k)
            {
                c++;
            }
            if(m.find(sum-k)!=m.end())
            {
                c+=m[sum-k];
            }
           if(m.find(sum)!=m.end())
               m[sum]++;
           else
               m[sum]=1;
        }
        return c;
    }
};
class Solution {
public:
    bool possible(vector<int>&nums,int mid,int k)
    {
        int sum=0,c=1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>mid)
            {
                c++;
                sum=nums[i];
            }
        }return c<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=INT_MIN,r=0,mid,ans=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            l=max(l,nums[i]);
            r+=nums[i];
        }
         if(n==k)
            return l;
        if(k>n)
            return -1;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            if(possible(nums,mid,k)==true)
            {
             ans=mid;
             r=mid-1;   
            }
            else
             l=mid+1;   
        }
        return ans;
    }
};
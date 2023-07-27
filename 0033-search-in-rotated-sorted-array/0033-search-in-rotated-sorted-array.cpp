class Solution {
public:
    int search(vector<int>& nums, int k) {
        int l=0,r=nums.size()-1,mid;
        while(l<=r)
        {
            mid=l+(r-l)/2;
           if(nums[mid]==k)
               return mid;
            else if(nums[l]<=nums[mid])
            {
                if(nums[l]<=k && nums[mid]>k)
                    r=mid-1;
                else
                    l=mid+1;
            }
            else
            {
                if(nums[mid]<k && nums[r]>=k)
                    l=mid+1;
                else
                    r=mid-1;
            }
        }
         return -1;
    }
};
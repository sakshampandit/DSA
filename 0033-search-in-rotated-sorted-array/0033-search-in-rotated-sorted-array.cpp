class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(),l=0,r=n-1,mid;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[l]<=nums[mid])
            {
                if(target>=nums[l] && nums[mid]>target)
                {
                    r=mid-1;
                }
                else
                    l=mid+1;
            }
            else
            {
                if(target>nums[mid] && target<=nums[r])
                {
                    l=mid+1;
                }
                else
                    r=mid-1;
            }
        }
        return -1;
    }
};
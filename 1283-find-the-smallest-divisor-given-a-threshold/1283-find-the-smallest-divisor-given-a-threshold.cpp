class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,r=*max_element(nums.begin(),nums.end()),mid;
        while(l<=r)
        {  int sum=0;
            mid=l+(r-l)/2;
            for(int i=0;i<nums.size();i++)
            {
                sum+=ceil((double)nums[i]/mid);
            }
            if(sum<=threshold)
            {
             r=mid-1;
            }
            else
            l=mid+1;   
        }
        return l;
    }
};
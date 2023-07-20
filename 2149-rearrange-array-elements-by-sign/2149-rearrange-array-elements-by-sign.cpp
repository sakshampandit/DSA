class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>a;
        vector<int>b;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                a.push_back(nums[i]);
            else
                b.push_back(nums[i]);
                
        }
        // nums.clear();
        int i=0,j=0,k=0;
        while(i<a.size() && j<b.size())
        {
            nums[k++]=a[i++];
            nums[k++]=b[j++];
        }
        while(i<a.size())
        {
            nums[k++]=a[i++];
        }
        while(i<b.size())
        {
            nums[k++]=b[j++];
        }
        
        return nums;
    }
};
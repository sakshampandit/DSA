class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int n=nums.size();
        int num1=INT_MIN,num2=INT_MIN;int c1=0,c2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==num1)
                c1++;
            else if(nums[i]==num2)
                c2++;
            else if(c1==0 && nums[i]!=num2)
            {
                num1=nums[i];
                c1=1;
            }
            else if(c2==0 && nums[i]!=num1)
            {
                num2=nums[i];
                c2=1;
            }
            else
            {
                c1--;
                c2--;
            }
        }int count1=0,count2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==num1)
                count1++;
            if(nums[i]==num2)
                count2++;
        }vector<int>ans;
        int mini=int(n/3)+1;
        if(count1>=mini)
            ans.push_back(num1);
        if(count2>=mini)
            ans.push_back(num2);
       
        return ans;
    }
};
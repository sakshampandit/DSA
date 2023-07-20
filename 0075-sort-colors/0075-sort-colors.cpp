class Solution {
public:
    void sortColors(vector<int>& nums) {
//      map 0,1,2
        int ans=0;
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
//           0 1 2
//           2 2 2
            m[nums[i]]++;
        }
        // vector<int>v;
        nums.clear();
        for(auto i:m)
        { int c=i.second;
            while(c)
            {
                nums.push_back(i.first);
                --c;
            }
        }
    
    }
};
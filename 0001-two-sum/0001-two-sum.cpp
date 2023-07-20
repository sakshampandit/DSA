class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=0;
        map<int,int>m;
        vector<int>v;
       for(int i=0;i<nums.size();i++){
        if(m.find(target-nums[i])!=m.end())
        {
           v.push_back(i);
           v.push_back(m[target-nums[i]]);
            break;
        }
            m[nums[i]]=j++;
           
        }
        return v;
    }
};
// class Solution{   
// public:
//     int getPairsCount(int arr[], int n, int sum) {
//         // code here
//         unordered_map<int,int> m;
//         int ans = 0;
//         int diff;
        
//         for(int i =0; i<n; i++)
//         {
//             diff = sum - arr[i];
//             if( m[diff] )
//             {
//                 ans = ans + m[diff];
//             }
//             m[ arr[i] ] ++;
//         }
//         return ans;
//     }
// };
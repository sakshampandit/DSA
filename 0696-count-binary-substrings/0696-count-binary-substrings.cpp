class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev=0,curr=1,ans=0;
        for(int i=1;i<s.size();i++)
        {
            if(s[i-1]!=s[i])
            {
                ans+=min(curr,prev);
                prev=curr;
                curr=1;
            }
            else
                curr++;
        }
        ans+=min(curr,prev);
        return ans;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
       if (n==0)
           return "";
        if(n==1)
            return strs[0];
        else
        {
            sort(strs.begin(),strs.end());
            int l=min(strs[0].size(),strs[n-1].size());
            int i=0,c=0;
            while(i<l && strs[0][i]==strs[n-1][i])
            {
                i++;
                c++;
                
            }
            if(c==0)
                return "";
            else
                return strs[0].substr(0,c);
        }
    }
};
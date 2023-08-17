class Solution {
public:
    string longestPalindrome(string s) {
        int start=0,end=1,l,r;
        for(int i=1;i<s.size();i++)
        {
        
            l=i-1;
            r=i;
        while(l>=0 && r<s.size() && s[l]==s[r])
        {
            if(r-l+1>end)
            {
                start=l;
                end=r-l+1;
            }
            l--;
            r++;
        }
            l=i-1;
            r=i+1;
            while(l>=0 && r<s.size() && s[l]==s[r])
        {   if(r-l+1>end)
            {
                start=l;
                end=r-l+1;
            }
            l--;
            r++;
        }
        }
        
            return s.substr(start,end);
    }
    
};
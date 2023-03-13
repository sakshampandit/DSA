class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int ml=1,start=0,end=0;
        for(int i=0;i<n-1;i++)
        {
          int l=i,r=i;
            while(l>=0 && r<n)
            {
                if(s[l]==s[r])
                {
                    l--;
                    r++;
                }else
                    break;
            }
            int len=r-l-1;
            if(len>ml)
            {
                ml=len;
                start=l+1;
                end=r-1;
                
            }
            
        }
        for(int i=0;i<n-1;i++)
        {
          int l=i,r=i+1;
            while(l>=0 && r<n)
            {
                if(s[l]==s[r])
                {
                    l--;
                    r++;
                }else
                    break;
            }
            int len=r-l-1;
            if(len>ml)
            {
                ml=len;
                start=l+1;
                end=r-1;
                
            }
            
        }
        return s.substr(start,ml);
        
    }
};
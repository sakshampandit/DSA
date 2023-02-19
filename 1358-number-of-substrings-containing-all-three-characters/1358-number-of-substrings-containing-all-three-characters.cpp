class Solution {
public:
    int numberOfSubstrings(string s) {
        // a=0,b=1,c=2,co=0
        int a=-1,b=-1,c=-1;
        int co=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a')
               a=i;
            else if(s[i]=='b')
                b=i;
            else
                c=i;
            if(i>1)
                co+=min(a,min(b,c))+1;
        }
        return co;
        
    }
};
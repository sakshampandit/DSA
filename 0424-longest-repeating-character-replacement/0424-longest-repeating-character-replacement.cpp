class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> m;
        int i=0,j=0,c=0,l=0;
        int n=s.size();
        while(j<n)
        {
            m[s[j]]++;
            c=max(c,m[s[j]]);
            if((j-i+1)-c>k)
            {
               if(m[s[i]]==1)
                   m.erase(s[i]);
                else
                   m[s[i]]--;
                i++;
            }
            l=max(l,j-i+1);
            j++;
        }
        return l;
    }
};
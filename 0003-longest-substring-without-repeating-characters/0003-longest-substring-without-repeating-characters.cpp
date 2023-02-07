class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       set<char>Set;
       int a=0,b=0,max=0;
       while(a<s.size())
       {
           auto it=Set.find(s[a]);
           if(it==Set.end())
           {
            if(a-b+1>max)
             max=a-b+1;
            Set.insert(s[a]);
            a++;
           }
           else
           {
               Set.erase(s[b]);
               b++;
           }
       }
       return max; 
    }
};
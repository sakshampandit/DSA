class Solution {
public:
    string reverseWords(string s) {
        string ans="",t="";
        int l=s.size();
        for(int i=l-1;i>=0;i--)
        {
            if(s[i]==' ')
            {   reverse(t.begin(),t.end());
               if(ans.size()>0 && t.size()>0)
               {
                   ans+=' '+t;
                  
               }
               if(ans.size()==0 && t.size()>0)
              { ans+=t;}
             t="";
             
            }
            else
             { t+=s[i];}
        }
               reverse(t.begin(),t.end());
               if(ans.size()>0 && t.size()>0)
               {
                   ans+=' '+t;
               }
    
            if(ans.size()==0 && t.size()>0)
             ans+=t;
               
        return ans;
             
          
    }
};
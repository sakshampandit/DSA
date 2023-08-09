class Solution {
public:
     int MOD=1000000007;
    int sumSubarrayMins(vector<int>& a) {
        int n=a.size();
     vector<int>left(n,-1);
     vector<int>right(n,n);   
     stack<int>s;
     for(int i=0;i<a.size();i++)
     {
         while(!s.empty() && a[s.top()]>=a[i])
             s.pop();
         if(!s.empty())
             left[i]=s.top();
         s.push(i);
     }
        s=stack<int>();
         for(int i=n-1;i>=0;i--)
     {
         while(!s.empty() && a[s.top()]>a[i])
             s.pop();
         if(!s.empty())
             right[i]=s.top();
         s.push(i);
     }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int l=i-left[i];
            int r=right[i]-i;
            // res+=((a[i]*l*r)%1000000007);
            long long total = (l*r)%MOD;   

            total = (total*a[i])%MOD;

            ans = (ans + total)%MOD;
            
        }
        return ans%MOD;
    }
};
class Solution {
public:
    bool possible(vector<int>&weights,int days,int mid)
    {
        int currentweight=0;
        int day=1;
        for(int i=0;i<weights.size();i++)
        {
            if(currentweight+weights[i]>mid){
            day++;
            currentweight=0;
            }
            currentweight+=weights[i];
        }
        return day<=days;
        
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int l=0,r=0,mid;
        for(int i=0;i<n;i++)
        {
            l=max(l,weights[i]);
            r+=weights[i];
        }
        int ans=r;
      while(l<=r)
      {
           mid=l+(r-l)/2;
          if(possible(weights,days,mid)==true)
          {   
              ans=mid;
              r=mid-1;
          }
          else
              l=mid+1;
         
      }
        return ans;
    }
};
class Solution {
public:
  long long timefunc(int mid,vector<int> piles)
    {
       long long hours=0;
        for(int i=0;i<piles.size();i++)
        {
        //   hours+=(piles[i]/mid)+((piles[i]%mid)!=0);
        hours+=ceil((double)piles[i]/mid);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(left<=right)
        {
            int mid=(left+right)/2;
            long long time=timefunc(mid,piles);
            if(time<=h)
            {
                ans=mid;
                right=mid-1;
            }else
            {
                left=mid+1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int s=INT_MAX,e=INT_MIN,ans=-1;
        for(int i=0;i<n;i++){
            s=min(s,bloomDay[i]);
            e=max(e,bloomDay[i]);
        }
        while(s<=e){
            int mid=s+(e-s)/2;
            int c=0,no=0;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid)
                    c++;
                else
                    c=0;
                if(c==k){
                    c=0;
                    no++;
                }
                if(no>=m)
                {
                    ans=mid;
                    e=mid-1;
                }
            }
            if(no<m)
                s=mid+1;
            // else{
            //     ans=mid;
            //     e=mid-1;
            // }
        }
        return ans;
    }
};
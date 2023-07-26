class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(hour<=dist.size()-1){return -1;}
        int i=1, j=1e7;
        while(i<=j){
            int mid=i+(j-i)/2;
            double cnt=0;
            for(int k=0; k<dist.size()-1; k++){
                cnt+=dist[k]/mid+(dist[k]%mid!=0);
            }
            //cout<<cnt<<" "<<mid<<endl;
            if(((double)dist[dist.size()-1]/mid)+cnt>hour){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return i;
    }
};
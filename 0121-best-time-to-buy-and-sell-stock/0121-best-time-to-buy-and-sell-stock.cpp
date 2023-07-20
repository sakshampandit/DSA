class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi=INT_MAX;
        int m=0;
        for(int i=0;i<prices.size();i++)
        {
            mi=min(mi,prices[i]);
            m=max(m,prices[i]-mi);
        }
        return m;
    }
};
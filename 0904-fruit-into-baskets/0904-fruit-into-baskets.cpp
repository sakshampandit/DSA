class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      int i=0,j=0,ans=0;
      map<int,int> m;
        int n=fruits.size();
        while(j<n)
        {
            m[fruits[j]]++;
            if(m.size()>2)
            {
                if(m[fruits[i]]==1)
                    m.erase(fruits[i]);
                else
                {
                    m[fruits[i]]--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
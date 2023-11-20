class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int lastM = -1, lastP = -1, lastG = -1;
        
        // Finding the last house for each type of garbage
        for(int i = n - 1; i >= 0; i--) {
            if(lastM == -1 && garbage[i].find("M") != string::npos)
                lastM = i;
            if(lastP == -1 && garbage[i].find("P") != string::npos)
                lastP = i;
            if(lastG == -1 && garbage[i].find("G") != string::npos)
                lastG = i;

            // To avoid unnecessaray iterations
            if(lastM != -1 && lastP != -1 && lastG != -1)
                break;
        }
        
        int ans = 0;
        // Time to pick up garbage
        for(auto g: garbage)
            ans += g.size();

        // Time to travel
        if(lastM != -1)
            ans = accumulate(travel.begin(), travel.begin() + lastM, ans);
        if(lastP != -1)
            ans = accumulate(travel.begin(), travel.begin() + lastP, ans);
        if(lastG != -1)
            ans = accumulate(travel.begin(), travel.begin() + lastG, ans);

        return ans;
    }
};
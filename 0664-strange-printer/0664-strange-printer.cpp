class Solution {
public:
    int solve(int start,int end,string s,vector<vector<int>> &mem) {
        if(start > end)             return 0;
        if(mem[start][end] != -1)   return mem[start][end];
        int res = 0;
        // choice 1 : dont want to merge
        res = 1 + solve(start, end-1, s, mem);

        // choice 2 : Want to merge
        for(int i=start; i<end; i++) {
            if(s[i] == s[end])
                res = min(res, solve(start, i, s, mem) + solve(i+1, end-1, s, mem));
        }
        return mem[start][end] = res;
    }

    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> mem(n+1, vector<int>(n+1, -1));
        return solve(0, n-1, s, mem);
    }
};
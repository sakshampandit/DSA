class Solution {
public:
    bool rotateString(string s, string goal) {
       int a=s.size();
        int b=goal.size();
        if(a!=b)
            return false;
        else
        {
            string temp=s+s;
            if(temp.find(goal)!=string::npos)
                return true;
            else
                return false;
        }
    }
};
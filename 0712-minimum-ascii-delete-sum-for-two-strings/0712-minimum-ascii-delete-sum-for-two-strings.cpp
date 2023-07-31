class Solution {
public:
    int minimumDeleteSum(string word1, string word2) {
        
int n1=word1.length();
int n2=word2.length();
int dp[n1+1][n2+1];

int sum=0;
        for(int i=0 ; i<n1; i++)
        {
            sum=sum+word1[i];
        }
        for(int i=0 ; i<n2; i++)
        {
            sum=sum+word2[i];
        }
        for(int i=0 ; i<= n1; i++)
        {
            dp[i][0]=0;
        }
        for(int i=0 ; i<= n2; i++)
        {
            dp[0][i]=0;
        }
        for(int i=1 ; i<= n1; i++)
        {
            for(int j=1 ; j<= n2; j++)
            {
                int op1=0,op2=0;
                if(word1[i-1]==word2[j-1])
                {op1=dp[i-1][j-1]+word1[i-1];}
                else{
                op2=max(dp[i-1][j],dp[i][j-1]);
                }
                dp[i][j]=max(op1,op2);
            }
        }
        return sum-2*dp[n1][n2];
    }
};
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution{
public:
long long int largestPrimeFactor(int N){

long long int factprime =0;

if(N==0 || N==1) return -1;

for(int i = 2; i*i<=N; i++)
if(N%i == 0)
while(N%i==0 && N>i)
N=N/i;

if(N>1)
factprime = N;
return factprime;

}
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
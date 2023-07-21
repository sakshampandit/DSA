//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int a[], int n)
    {
      //Your code here
      unordered_set<int>s(a,a+n);
      int ans=0;
      for(int i=0;i<n;i++)
      {
          if(s.find(a[i]-1)!=s.end())
          continue;
          else
          {
              int count=0;
              int current=a[i];
              while(s.find(current)!=s.end())
              {
                  count++;
                  current++;
              }
              ans=max(ans,count);
          }
      }
      return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends
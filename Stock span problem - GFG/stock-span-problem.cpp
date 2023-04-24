//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int prices[], int n)
    {
       // Your code here]
       stack<pair<int,int>>s;
       vector<int>ans;
    //   if(s.empty())
    //       {
    //         s.push({prices[0],1});
    //         ans.push_back(1);
    //       }
            
       for(int i=0;i<n;i++)
       {
           int day=1;
            while(!s.empty() && s.top().first<=prices[i])
           {day+=s.top().second;
           s.pop();
           }
           s.push({prices[i],day});
           ans.push_back(day);
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& a, int n) 
    {
        // code here 
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            s.push(i);
            
        }
        //s=0 1 
        //z=1
        while(s.size()!=1)
        {
            int x=s.top();
            s.pop();
            int y=s.top();
            s.pop();
            if(a[x][y]==1)
            s.push(y);
            else
            s.push(x);
        }
        int z=s.top();
        //verify the element
        bool flag=true;
        for(int i=0;i<a[0].size();i++)
        {
            if(a[z][i]!=0)
            flag=false;
        }
        if(flag==false)
        return -1;
        else{
        flag=true;
        
        for(int i=0;i<a.size();i++)
        {
            if(a[i][z]!=1 && i!=z)
            flag=false;
        }
        if(flag==false)
        return -1;
        else
        return z;
        }
        
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
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
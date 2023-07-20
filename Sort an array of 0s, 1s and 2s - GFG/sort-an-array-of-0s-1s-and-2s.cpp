//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int nums[], int n)
    {
        // code here 
        //Approach take a map and count no. of 0,1,2; and print it orderly
        int j=0;
        map<int,int>m;
        for(int i=0;i<n;i++)
        {
//           0 1 2
//           2 2 2
            m[nums[i]]++;
        }
        // vector<int>v;
         int a[n];
        for(auto i:m)
        { int c=i.second;
            while(c)
            {
                a[j++]=i.first;
                --c;
            }
        }
        for(int i=0;i<n;i++)
        nums[i]=a[i];
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends
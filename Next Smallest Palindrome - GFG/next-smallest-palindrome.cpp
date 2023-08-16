//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> generateNextPalindrome(int arr[], int n) {
	    // code here
        int mid= n/2;
        
        int a, b;
        
        vector<int> ans;
	       
       if(n%2==1)
       {
	       a= mid-1;
           b= mid+1;
       }
       else
       {
           a= mid-1;
           b= mid;
       }
	       
       bool check = false; 
       
       while(a>=0)
       {
           if(arr[a]>arr[b])
           {
               check=true;
               break;
           }
           
           if(arr[a]<arr[b])
           {
               break;
           }
           a--;
           b++;
       }
       
       if(check==true)
       {
           int i=0;
	       int j= n-1;
	           
           while(i<j)
           {
               arr[j]=arr[i];
               i++;
               j--;
           }  
           
           for(int i=0;i<n;i++)ans.push_back(arr[i]);
           
           return ans;
           
       }
       else
       {
           if(n%2==1 and arr[mid]<9)
           {
               arr[mid]+=1;
               
               int i=0;
               int j=n-1;
               
               while(i<j)
               {
                   arr[j]=arr[i];
                   j--;
                   i++;
               }
               
               for(int i=0;i<n;i++)ans.push_back(arr[i]);
               
               return ans;
           }
           
           
           int i;
           for(i=mid-1;i>=0;i--)
           {
               if(arr[i]<9)
               {
                   break;
               }
           }
           
           if(i!=-1)
           {
	           arr[i]+=1;
	           
	           for(int j= i+1;j<=mid;j++)
	             arr[j]=0;
	             
	           int i=0;
	           int j= n-1;
	           
	           while(i<j)
	           {
	               arr[j]=arr[i];
	               i++;
	               j--;
	           } 
	           
	           for(int i=0;i<n;i++)ans.push_back(arr[i]);
               
           }
           else
           {
               int size= n+1-2;
               
               ans.push_back(1);
               
               for(int i=1;i<=size;i++)ans.push_back(0);
               
               ans.push_back(1);
               
               return ans;
               
           }
           
       }
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
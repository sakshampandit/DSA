//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++
// Step 1:- Here we created a data type so as to store the value,the index of the array and the position in that particular array
// Step 2:- Then we took a comparator to compare the to data values and return its answer to the priority queue
// Step 3:- We make a priority queue ie,priority_queue<data type,vector of vectors,comparator for every time comparing>
// Step 4:- then we will enter k value first in our queue in the form of user defined data type
// Step 5:- Now we will run the loop till queue is empty and extract the minimum value which is at the top and simultaneously poping it
// Step 6:- push the value in the answer vector and then check if there is next element in that particular array from which value was extracted 
class data
{   public:
    int val,vpos,apos;
    data(int v,int ap,int vp)
    {
        val=v;
        apos=ap;
        vpos=vp;
    }
};
struct mycomp{
    bool operator()(data &d1,data &d2)
    {
        return d1.val>d2.val;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        //code here
        priority_queue<data,vector<data>,mycomp>pq;
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            data d(arr[i][0],i,0);
            pq.push(d);
        }
        while(!pq.empty())
        {
            data curr=pq.top();
            pq.pop();
            ans.push_back(curr.val);
            int vp=curr.vpos,ap=curr.apos;
            if(vp+1<arr[ap].size())
            {
                data d(arr[ap][vp+1],ap,vp+1);
                pq.push(d);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends
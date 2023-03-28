class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
      priority_queue <int> pq;
        // code here
        int n=arr.size();
        int x=n-k;
        for(int i=0;i<n;i++)
        {
            pq.push(arr[i]);
        }
    //    vector<int> v;
        for(int i=0;i<k-1;i++)
        {
            pq.pop();
        }  
        return pq.top();
    }
};//1 2 3 4 5 6
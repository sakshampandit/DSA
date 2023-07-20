class Solution {
public:
    void nextPermutation(vector<int>& a) {
       int inf=-1,n=a.size();
        for(int i=n-1;i>0;i--)
        {
            if(a[i]>a[i-1])
            {
                inf=i;
                break;
            }
        }
        if(inf==-1)
        { 
            reverse(a.begin(),a.end());
           
        }
        else
        {   
            // x=3 prev=5
            int prev=inf;
        //   int x=a[inf-1];
        //   cout<<x<<endl;
        //   cout<<a[prev]<<endl;
            for(int i=inf+1;i<n;i++)
            {
                if(a[i]>a[inf-1] and a[i]<=a[prev])
                prev=i;
            }
            // cout<<x<<endl;
            // cout<<a[prev]<<endl;
            swap(a[inf-1],a[prev]);
            // cout<<x<<endl;
            // cout<<a[prev]<<endl;
            // cout<<x<<endl;
            reverse(a.begin()+inf,a.end());
        }     
    }
};
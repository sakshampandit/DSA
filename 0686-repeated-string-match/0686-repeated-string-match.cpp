class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s=a;
//         itne size tk loop chalega hi jitna n hai
        int n=b.size()/a.size();
//         counter
        int res=1;
        for(int i=0;i<=n+1;i++)
        {
//             agar b occur kargya s mein return kardo warna badate jaao s ko a se
            if(s.find(b)!=string::npos)
              return res;
            s+=a;
            res++;
        }
        
        return -1;
    }
};

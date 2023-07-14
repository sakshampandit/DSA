//{ Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            String s = br.readLine();
            String[] S = s.split(" ");
            int[] v = new int[n];
            for(int i = 0; i < n; i++)
            {
                v[i] = Integer.parseInt(S[i]);
            }
            Solution ob = new Solution();
           System.out.println(ob.max_xor(v, n));
            
        }
    }
}


// } Driver Code Ends


//User function Template for Java

class Solution
{   
    static class TrieNode
    {
        TrieNode zero;
        TrieNode one;
    }
static void insert(TrieNode root,int n)
    {
        TrieNode curr=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(n>>i)&1;
            if(bit==0)
            {
                if(curr.zero==null)
                {   
                    TrieNode newNode=new TrieNode();
                    curr.zero= newNode;
                }
                   curr=curr.zero;
            }
            else
            {
                if(curr.one==null)
                {
                    TrieNode newNode=new TrieNode();
                    curr.one=newNode;
                }
                   curr=curr.one;
            }
        }
    }
    static int maxroot(TrieNode root,int n){
          TrieNode curr=root;
          int ans=0;
          for(int i=31;i>=0;i--)
          {
              int bit=(n>>i)&1;
      if(bit==1)
             {if(curr.zero!=null)
             {
                 ans+=(1<<i);
                 curr=curr.zero;
             }
             else
                 curr=curr.one;
             }
       else
              { 
                 if(curr.one!=null)
                 {
                     ans+=(1<<i);
                     curr=curr.one;
                 }
                 
                 else
                 {
                     curr=curr.zero;
                 }
              }
            }
                 return ans;
    }
             
          
        
    
    int max_xor(int a[] , int n)
    {
        //code here
        TrieNode root=new TrieNode();
        int ans=0;
        for(int i=0;i<n;i++)
        {
          insert(root,a[i]);   
        }
        for(int i=1;i<n;i++)
        {
            ans=Math.max(ans,maxroot(root,a[i]));
        }
        return ans;
    }
    
};
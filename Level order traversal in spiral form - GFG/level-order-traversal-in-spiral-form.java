//{ Driver Code Starts
//Initial Template for Java



//Initial Template for Java

//Contributed by Sudarshan Sharma
import java.util.LinkedList; 
import java.util.Queue; 
import java.io.*;
import java.util.*;

class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}


class GfG {
    
    static Node buildTree(String str){
        
        if(str.length()==0 || str.charAt(0)=='N'){
            return null;
        }
        
        String ip[] = str.split(" ");
        // Create the root of the tree
        Node root = new Node(Integer.parseInt(ip[0]));
        // Push the root to the queue
        
        Queue<Node> queue = new LinkedList<>(); 
        
        queue.add(root);
        // Starting from the second element
        
        int i = 1;
        while(queue.size()>0 && i < ip.length) {
            
            // Get and remove the front of the queue
            Node currNode = queue.peek();
            queue.remove();
                
            // Get the current node's value from the string
            String currVal = ip[i];
                
            // If the left child is not null
            if(!currVal.equals("N")) {
                    
                // Create the left child for the current node
                currNode.left = new Node(Integer.parseInt(currVal));
                // Push it to the queue
                queue.add(currNode.left);
            }
                
            // For the right child
            i++;
            if(i >= ip.length)
                break;
                
            currVal = ip[i];
                
            // If the right child is not null
            if(!currVal.equals("N")) {
                    
                // Create the right child for the current node
                currNode.right = new Node(Integer.parseInt(currVal));
                    
                // Push it to the queue
                queue.add(currNode.right);
            }
            i++;
        }
        
        return root;
    }
    void inOrder(Node node) {
        if (node == null) {
            return;
        }
 
        inOrder(node.left);
        System.out.print(node.data + " ");
 
        inOrder(node.right);
    }
    
	public static void main (String[] args) throws IOException{
	        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	        
	        int t=Integer.parseInt(br.readLine());
    
	        while(t-- > 0){
	            String s = br.readLine();
    	    	Node root = buildTree(s);
                Spiral g = new Spiral();
                ArrayList<Integer> result = g.findSpiral(root);
                for(int value : result)
                System.out.print(value + " ");
			    System.out.println();
    	        
	        }
	}
}




// } Driver Code Ends


//User function Template for Java


/*
// A Binary Tree node
class Node
{
    int data;
    Node left, right;

    Node(int item)
    {
        data = item;
        left = right = null;
    }
}
*/

class Spiral
{
    List<List<Integer>> arr= new ArrayList<>();
    
    ArrayList<Integer> findSpiral(Node root) 
    {
        inorder(root,0);
        ArrayList<Integer> ans=new ArrayList<Integer>();
        for(int i=0; i<arr.size(); i++){
            if(i%2==1) ans.addAll(arr.get(i));
            else for(int j=arr.get(i).size()-1; j>=0; j--) ans.add(arr.get(i).get(j));
            
        }
        return ans;
        
       
    }
    void inorder(Node root, int k){
        if(root==null ) return;
        if(arr.size()<=k) arr.add(new ArrayList<Integer>());
        inorder(root.left, k+1);
        arr.get(k).add(root.data);
        inorder(root.right, k+1);
    }
}

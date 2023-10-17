class Solution {
public:
    // time/space: O(n)/O(n)
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // find the parent for each node
        unordered_map<int, int> node2parent;
        for (int node = 0; node < n; node++) {
            if (leftChild[node] != -1) {
                // each node must have only 1 parent
                if (node2parent.count(leftChild[node]) != 0) return false;
                node2parent[leftChild[node]] = node;
            }
            if (rightChild[node] != -1) {
                // each node must have only 1 parent
                if (node2parent.count(rightChild[node]) != 0) return false;
                node2parent[rightChild[node]] = node;
            }
        }

        // find the root of the binary tree
        int root = -1;
        for (int node = 0; node < n; node++) {
            // a root node has no parent
            if (node2parent.count(node) == 0) {
                // return false if there are more than 1 root
                if (root != -1) return false;
                root = node;
            }
        }
        // no root is found
        if (root == -1) return false;

        // travel the binary tree from the root, there must be no cycle
        vector<bool> visited(n, false);
        if (hasCycle(root, leftChild, rightChild, visited)) return false;

        // all nodes must be visited
        for (int node = 0; node < n; node++) {
            if (!visited[node]) return false;
        }
        
        return true;
    }
private:
    bool hasCycle(int node, vector<int>& leftChild, vector<int>& rightChild, vector<bool>& visited) {
        // terminate
        if (node == -1) return false;
        if (visited[node]) return true;
        visited[node] = true;

        // enumerate
        bool is_left_cycle = hasCycle(leftChild[node], leftChild, rightChild, visited);
        bool is_right_cycle = hasCycle(rightChild[node], leftChild, rightChild, visited);
        return (is_left_cycle || is_right_cycle);
    }
};
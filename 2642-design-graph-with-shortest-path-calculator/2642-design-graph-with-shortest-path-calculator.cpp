class Graph {
public:
    // time: O(E) = O(n ^ 2)
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        graph = vector<vector<pair<int, int>>>(n);
        for (auto& edge : edges) addEdge(edge);
    }
    
    // time: O(1)
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }
    
    // time/space: O(ElogV)/O(V) = O(n^2 * logn)/O(n)
    int shortestPath(int node1, int node2) {
        vector<int> costs(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        costs[node1] = 0;
        pq.push({0, node1});

        while (!pq.empty()) {
            auto [curr_cost, curr_node] = pq.top();
            pq.pop();
            for (auto [next_node, next_cost] : graph[curr_node]) {
                int cost = curr_cost + next_cost;
                if (cost >= costs[next_node]) continue;
                costs[next_node] = cost;
                pq.push({cost, next_node});
            }
        }
        
        if (costs[node2] == INT_MAX) return -1;
        return costs[node2];
    }
private:
    // space: O(E) = O(n ^ 2)
    int n;
    vector<vector<pair<int, int>>> graph;       // graph[from] = {to, cost}
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
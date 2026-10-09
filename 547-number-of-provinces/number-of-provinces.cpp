
class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj,
             vector<int>& visited) {

        visited[node] = 1;

        for (int neighbor : adj[node]) {
            if (visited[neighbor] == 0) {
                dfs(neighbor, adj, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> visited(n, 0);
        int provinces = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                provinces++;
                dfs(i, adj, visited);
            }
        }

        return provinces;
    }
};

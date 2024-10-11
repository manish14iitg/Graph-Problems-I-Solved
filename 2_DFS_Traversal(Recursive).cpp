   // T.C. = O(V+E)
   // S.C. = O(V) -> recursive stack(O(v) in worst case) + visited array(O(v))
   // It is like Traveling the cities from your home town visit all unvisited places
   // one by one, if you explored all the possible places then you return to where you came.
   // it can be implemented by stack that can be accessed at next file.


   void DFS(int node,vector<int> adj[],vector<bool>&visited,vector<int>&ans){
        visited[node] = 1;
        ans.push_back(node);
        for(int i = 0; i < adj[node].size(); i++){
            if(visited[adj[node][i]] == 0){
                DFS(adj[node][i],adj,visited,ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        vector<bool>visited(V,0);
        int node = 0; // starting point
        DFS(node,adj,visited,ans);
        return ans;
    }

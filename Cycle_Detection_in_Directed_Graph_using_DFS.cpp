bool DFS(int node,vector<int> adj[],vector<bool>&path,vector<bool>&visited){
        path[node] = 1;
        visited[node] = 1;
        for(int i = 0; i<adj[node].size();i++){
            if(path[adj[node][i]])
            return 1;
            
            if(visited[adj[node][i]])
            continue; // if this side is already visited in previous path why to visit again.
            
            if(DFS(adj[node][i],adj,path,visited))
            return 1;
        }
        path[node] = 0;
        return 0;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        // using DFS
        // if we encounter any node second time in our current
        // path we will declare a cycle.
        // if we didn't found any cycle yet will return and
        // we will remove it from our path but not from
        // visited array.
        vector<bool>path(V,0);
        vector<bool>visited(V,0);
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                if(DFS(i,adj,path,visited))
                return 1;
            }
        }
        return 0;
    }

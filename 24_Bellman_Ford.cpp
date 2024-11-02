vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        // Bellman ford -> for directed graph
        // 1.) check if there is a negative cycle present in the graph
        // 2.) if no -ve cycle returns the distance vector from src to all nodes
        
        // steps:-
        // 1.) relax all edges V-1 times
        
        
        // distance vector
        vector<int>dist(V,1e8);
        dist[src] = 0;
        for(int i = 0; i<V-1; i++){
            // flag to check if there was any change in all the edges, if no change directly return the answer, as there won't be any change in the future;
            bool flag = 0;
            for(int j = 0; j< edges.size(); j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                if(dist[u] == 1e8) continue; // means we can't even reach u from src, so no need to check for this one, wiil give incorrect answer;
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    flag = 1;
                }
            }
            if(flag == 0){
                return dist;
            }
        }
        // 2.) Relax all edges one more time to check negative cycle
        for(int j = 0; j< edges.size(); j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
                if(dist[v] > dist[u] + w){
                    // cycle detected
                    vector<int>ans;
                    ans.push_back(-1);
                    return ans;
                }
        }
        return dist;
    }

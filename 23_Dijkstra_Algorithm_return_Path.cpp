vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        // create adjancy list
        vector<pair<int,int>> adj[n+1];
                  //neighbour,weight
        for(int i = 0; i< m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        // Dijkstra Algorithm
        vector<int>dist(n+1,INT_MAX);
        dist[1] = 0;
        vector<int>parent(n+1,-1);
        vector<bool>explored(n+1,0);
        
        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>> p;
        p.push({0,1});
        while(!p.empty()){
            int node = p.top().second;
            p.pop();
            
            for(int i = 0; i< adj[node].size(); i++){
                if(!explored[adj[node][i].first]){
                    if(dist[adj[node][i].first] > dist[node] + adj[node][i].second){
                        dist[adj[node][i].first] = dist[node] + adj[node][i].second;
                        parent[adj[node][i].first] = node; // extra line
                        p.push({dist[adj[node][i].first],adj[node][i].first});
                    }
                }
            }
            
            explored[node] = 1;
        }
        vector<int>path;
        // if we can't reach destination
        if(parent[n] == -1){
            path.push_back(-1);
            return path;
        }
        // and if we can
        
        int node = n;
        while(node != -1){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(dist[n]);
        reverse(path.begin(),path.end());
        return path;
    }

void topo(int node,vector<pair<int,int>> adj[],stack<int>&s,vector<bool>&visited){
        visited[node] = 1;
        for(int i = 0; i < adj[node].size(); i++){
            if(visited[adj[node][i].first] == 0){
                topo(adj[node][i].first,adj,s,visited);
            }
        }
        s.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>> adj[V];
        
        for(int i = 0; i<E; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            adj[u].push_back({v,w});
        }
        
        // topo sort
        stack<int>s;
        vector<bool>visited(V,0);
        topo(0,adj,s,visited);
        // find answer from the stack
        vector<int>ans(V,-1);
        ans[0] = 0;
        while(!s.empty()){
            int node = s.top();
            s.pop();
            for(int i = 0; i< adj[node].size(); i++){
                if(ans[adj[node][i].first] == -1){
                    // if visiting first time, just update value with it's weight + parent node's distance from 0(ans[node]);
                    ans[adj[node][i].first] = ans[node] + adj[node][i].second;
                }else{
                    // if already visited once check if this time the distance is minimum or not;
                    ans[adj[node][i].first] = min(ans[adj[node][i].first], ans[node] + adj[node][i].second);
                }
            }
        }
        return ans;
    }

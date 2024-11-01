vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        // BFS
        // adjancy creation
        vector<int> adj[N];
        for(int i = 0; i<M; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        q.push(src);
        
        vector<int> ans(N,-1);
        ans[src] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i = 0; i<adj[node].size(); i++){
                if(ans[adj[node][i]] == -1){
                    // -1 means we are reaching this node first time
                    ans[adj[node][i]] = ans[node]+1;
                    q.push(adj[node][i]);
                }
            }
        }
        return ans;
    }

// This will give a TLE because of DFS.


void dfs(int node,vector<int> adj[],vector<bool>visited,vector<int>&ans){
        visited[node] = 1;
        for(int i = 0; i< adj[node].size(); i++){
            if(visited[adj[node][i]] == 0){
                if(ans[adj[node][i]] == -1){
                    ans[adj[node][i]] = ans[node] + 1;
                }else{
                    ans[adj[node][i]] = min(ans[adj[node][i]],ans[node]+1);
                }
                dfs(adj[node][i],adj,visited,ans);
            }
        }
    }
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        // DFS
        // adjancy creation
        vector<int> adj[N];
        for(int i = 0; i<M; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>ans(N,-1);
        ans[src] = 0;
        vector<bool>visited(N,0);
        dfs(src,adj,visited,ans);
        return ans;
    }

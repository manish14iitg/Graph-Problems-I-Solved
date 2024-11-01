vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        //code here
        vector<int> adj[n];
        for(int i = 0; i< m; i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        // indegree
        vector<int>indeg(n);
        for(int i = 0; i<n; i++){
            for(int j = 0; j< adj[i].size(); j++){
                indeg[adj[i][j]]++;
            }
        }
        // queue
        queue<int>q;
        for(int i = 0; i<n; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        // ans vector
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int i = 0; i< adj[node].size(); i++){
                indeg[adj[node][i]]--;
                if(!indeg[adj[node][i]])
                q.push(adj[node][i]);
            }
        }
        if(ans.size() == n)
        return ans;
        vector<int>temp;
        return temp;
    }

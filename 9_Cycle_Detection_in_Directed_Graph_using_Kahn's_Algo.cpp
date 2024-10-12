bool isCyclic(int V, vector<int> adj[]) {
        // code here
        // using kahn's algorithm
        // for the cycle part every node will always have atleast
        // 1 indegree, so i won't be pushed in the queue
        // atlast q.size() < V means cycle detected.
        
        vector<int>indegree(V,0);
        queue<int>q;
        for(int i = 0; i< V; i++){
            for(int j = 0; j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        for(int i = 0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int cnt = 0;// all time count of nodes in queue
        while(!q.empty()){
            int node = q.front();
            cnt++;
            q.pop();
            for(int i = 0; i<adj[node].size();i++){
                indegree[adj[node][i]]--;
                if(!indegree[adj[node][i]]){
                    q.push(adj[node][i]);
                }
            }
        }
        if(cnt < V){
            return 1;
        }
        return 0;
    }

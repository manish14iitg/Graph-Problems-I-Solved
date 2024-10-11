bool DetectCycle(int node,int parent, vector<int> adj[], vector<bool>&visited){
        queue<pair<int,int>>q;
        q.push(make_pair(node,parent));
        visited[node] = 1;
        while(!q.empty()){
            node = q.front().first;
            parent = q.front().second;
            q.pop();
            for(int i = 0; i< adj[node].size();i++){
                if(parent == adj[node][i])
                continue;
                if(visited[adj[node][i]])
                return 1;
                q.push(make_pair(adj[node][i],node));
                visited[adj[node][i]] = 1;
            }
            
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        // using DFS
        // recursive call for every node with a parent, 
        //if neighoubor is parent it is actually returning 
        //to where it came, so will skip this consition
        // and if neighobor is already visited, cycle is detected
        // and if no cycle is detected for any neighbor it will return 0;
        // also for not connected graph we have to check this for every
        // part of the graph by a loop;
        
        vector<bool>visited(V,0);
        for(int i = 0; i< V; i++){
            if(visited[i] == 0){
                if(DetectCycle(i,-1,adj,visited))
                return 1;
            }
        }
        return 0;
    }

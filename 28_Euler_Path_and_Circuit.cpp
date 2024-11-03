void dfs(int node, vector<int>adj[], vector<bool>&visited){
        visited[node] = 1;
        for(int i = 0; i<adj[node].size(); i++){
            if(visited[adj[node][i]] == 0){
                dfs(adj[node][i],adj,visited);
            }
        }
    }
	int isEulerCircuit(int V, vector<int>adj[]){
	    // Code here
	    int odd_deg = 0;
	    vector<int>degree(V,0); // calculate degree for each node
	    for(int i = 0; i<V; i++){
	        degree[i] = adj[i].size();
	        if(degree[i]%2 != 0)
	        odd_deg++;
	    }
	    if(odd_deg != 0 && odd_deg != 2) // 1,3,4,5,6,7,...
	    return 0;
	    
	    vector<bool>visited(V,0);
	    for(int i = 0; i<V; i++){
	        if(degree[i] != 0){
	            dfs(i,adj,visited); // traverse graph to know if we graph is connected or not , 0 degree nodes do not have edges
	            break;
	        }
	    }
	    for(int i = 0; i<V; i++){
	        if(degree[i] != 0)
	        if(visited[i] == 0){
	            return 0;
	        }
	    }
	    if(odd_deg == 0)
	    return 2;
	    
	    return 1;
	}

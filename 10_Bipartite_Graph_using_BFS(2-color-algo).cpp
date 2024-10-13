// 2-color-method
// it will look at its neighbors, if color is not assigned yet, assign opposite color of the current node;s color
// if already assigned and is same with the node's color will return 0;

bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>color(V,-1);
	    queue<int>q;
	    for(int j = 0; j<V;j++){
	        if(color[j] == -1){
        	    q.push(j);
        	    color[j] = 0;
        	    while(!q.empty()){
        	        int node = q.front();
        	        q.pop();
        	        for(int i = 0; i<adj[node].size(); i++){
        	            if(color[adj[node][i]] == color[node]){
        	                return 0;
        	            }
        	            if(color[adj[node][i]] == -1){
        	                color[adj[node][i]] = !color[node];
        	                q.push(adj[node][i]);
        	            }
        	        }
        	    }
	        }
	    }
	    
	    return 1;
	}

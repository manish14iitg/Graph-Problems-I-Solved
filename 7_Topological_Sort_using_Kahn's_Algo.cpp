vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    // Using BFS or Kahn's Algorithm
	    
	    // track indegree count in a vector
	    // push nodes with indegree count 0 in queue
	    // decrease indegree count of its neighbors
	    // now if any neghibor indegree count is 0 push it in the queue
	    
	    vector<int>indegree(V,0);
	    for(int i = 0; i<V; i++){
	        for(int j = 0; j< adj[i].size(); j++){
	            indegree[adj[i][j]]++;
	        }
	    }
	    queue<int>q;
	    for(int i = 0; i<V; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    vector<int>ans;
	    while(!q.empty()){
	        int node = q.front();
	        ans.push_back(node);
	        q.pop();
	        for(int i = 0; i< adj[node].size(); i++){
	            indegree[adj[node][i]]--;
	            if(indegree[adj[node][i]] == 0){
	                q.push(adj[node][i]);
	            }
	        }
	    }
	    return ans;
	}

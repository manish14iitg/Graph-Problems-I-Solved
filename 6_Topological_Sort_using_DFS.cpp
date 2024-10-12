// A simple dfs traversal but we have to push a elemnet in stack after all its neighbors are in the stack already


void DFS(int node,vector<int> adj[], vector<bool>&visited,stack<int>&s){
	    visited[node] = 1;
	    for(int i = 0; i<adj[node].size();i++){
	        if(!visited[adj[node][i]]){
	            DFS(adj[node][i],adj,visited,s);
	        }
	    }
	    s.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    // using DFS
	    stack<int>s;
	    vector<bool>visited(V,0);
	    for(int i = 0; i<V; i++){
	        if(!visited[i]){
	            DFS(i,adj,visited,s);
	        }
	    }
	    vector<int>ans;
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}

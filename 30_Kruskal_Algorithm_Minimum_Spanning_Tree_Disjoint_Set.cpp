int findparent(int u, vector<int>&parent){
	    if(u == parent[u]) return u;
	    
	    return parent[u] = findparent(parent[u],parent);
	}
	void unionByRank(int u, int v, vector<int>&parent, vector<int> &rank){
	    int Pu = findparent(u,parent);
	    int Pv = findparent(v,parent);
	    
	    if(rank[Pu] > rank[Pv]){
	        parent[Pv] = Pu;
	    }else if(rank[Pu] < rank[Pv]){
	        parent[Pu] = Pv;
	    }else{
	        parent[Pu] = Pv;
	        rank[Pv]++;
	    }
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // Disjoint set
        // create a temp vector with weight and edge information so iwill help in creating priority queue in less time, O(E) instead ElogE
        vector<pair<int,pair<int,int>>> temp;
        for(int i = 0; i< V; i++){
            for(int j = 0; j<adj[i].size(); j++){
                int u = i;
                int v = adj[i][j][0];
                int w = adj[i][j][1];
                temp.push_back({w,{u,v}});
            }
        }
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > pq(temp.begin(),temp.end());
        
        int edges = 0;
        int cost = 0;
        vector<int> parent(V);
        vector<int>rank(V,0);
        for(int i = 0; i<V; i++){
            parent[i] = i;
        }
        while(!pq.empty()){
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            int w = pq.top().first;
            pq.pop();
            if(findparent(u,parent) != findparent(v,parent)){
                unionByRank(u,v,parent,rank);
                cost += w;
                edges++;
            }
            if(edges >= V) break;
        }
        
        return cost;
    }

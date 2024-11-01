vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        // T.C. => ElogE, S.C. => V + E
        // METHOD :-
        // we will select a vertex that is not explord yet and has the
        // minimum value of distance from src node among all the unexplored
        
        // for above we can use priority queue(min heap) to reduce T.C.
        
        // node, now for every unexplored neighbour of this node, we will update the
        // minimum value to reach that node from src.
        int n = adj.size();
        // THIS WILL CHECK IF ANY NODE HAS ITS CORRECT MIN VALUE OR NOT
        // 0 -> WE NEED TO UPDATE IT FURTHER, 1-> WE HAVE THE MIN VALUE FOR THIS NODE
        
        vector<bool>explored(n,0);
        priority_queue<pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>>>pq;
        pq.push({0,src});
        // why INT_MAX -> we can easily find that unexplored vertex with minimum value among all of unexplored node 
        vector<int>ans(n,INT_MAX);
        ans[src] = 0;
        
        // have to check for every node
        while(!pq.empty()){
            int node = pq.top().second;
            
            pq.pop();
            
            // here we selected the node
            
            for(int i = 0; i<adj[node].size(); i++){
                int neighbour = adj[node][i].first;
                int weight = adj[node][i].second;
                if(!explored[neighbour]){
                    if(ans[neighbour] > ans[node] + weight){
                        ans[neighbour] = ans[node] + weight;
                        
                        pq.push({ans[neighbour],neighbour});
                    }
                        
                }
            }
            // here we updated all the neibhours value
            // and the node is explored now
            explored[node] = 1;
        }
        
        return ans;
            
    }

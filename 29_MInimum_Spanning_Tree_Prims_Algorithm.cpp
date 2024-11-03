int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<bool>mst(V,0);
        int cost = 0;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        pq.push({0,0});
        int cnt = V;
        
              //weight,node
        while(cnt){
            int node = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            if(mst[node] == 0)
            {
                cost += weight;
                mst[node] = 1;
            }
            else
            continue;
            
            
            for(int i = 0; i< adj[node].size(); i++){
                int neighbour = adj[node][i][0];
                int neighbour_weight = adj[node][i][1];
                if(mst[neighbour] == 0){
                    pq.push({neighbour_weight,neighbour});
                    
                }
            }
            cnt--;
        }
        
        return cost;
    }

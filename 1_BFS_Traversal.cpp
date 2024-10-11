        // T.C. = O(V+E)
        // S.C. = O(V)
        vector<int>ans;
        queue<int>q;
        q.push(0); // starting point
        vector<bool>visited(V,0);
        visited[0] = 1;
        
        while(!q.empty()){
            int i = q.front(); // this is the index of adjancy list
            q.pop();
            ans.push_back(i);
            for(int j = 0; j < adj[i].size(); j++){
                if(visited[adj[i][j]] == 0)  // check if the node is already visited
                q.push(adj[i][j]);
                visited[adj[i][j]] = 1;
            }
        }
        return ans;

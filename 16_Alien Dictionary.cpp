string findOrder(string dict[], int n, int k) {
        // code here
        vector<int> adj[k];
        vector<int>indeg(k,0);

        for(int i = 0; i< n-1; i++){
            int j =0;
            int k = 0;
            while(j < dict[i].size() && k
            < dict[i+1].size() && dict[i][j] == dict[i+1][k]){
                j++;k++;
            }
            if(j == dict[i].size()){
                continue;
            }
            adj[dict[i][j] - 'a'].push_back(dict[i+1][k] - 'a');
            indeg[dict[i+1][k] - 'a']++;
        }
        
        // kahn's algo
        queue<int>q;
        for(int i = 0; i<k; i++){
            if(!indeg[i])
            q.push(i);
        }
        string ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans += node + 'a';
            for(int i = 0; i< adj[node].size(); i++){
                indeg[adj[node][i]]--;
                if(!indeg[adj[node][i]])
                q.push(adj[node][i]);
                
            }
        }
        if(ans.size() == k)
        return ans;
        return "";
    }

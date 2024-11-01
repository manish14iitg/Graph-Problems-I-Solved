int row[8] = {1,0,-1,0,1,-1,1,-1};
    int col[8] = {0,1,0,-1,1,-1,-1,1};
    bool valid(int i,int j, int n, int m){
        if(i < 0 || i >= n || j < 0 || j>= m){
            return 0;
        }
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    grid[i][j] = '0';
                    queue<pair<int,int>>q;
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        int new_i = q.front().first;
                        int new_j = q.front().second;
                        q.pop();
                        for(int k = 0; k<8; k++){
                            if(valid(new_i+row[k],new_j+col[k], n, m) && grid[new_i+row[k]][new_j+col[k]] == '1'){
                                grid[new_i+row[k]][new_j+col[k]] = '0';
                                q.push(make_pair(new_i+row[k],new_j+col[k]));
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }

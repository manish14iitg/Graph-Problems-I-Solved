bool valid(int i,int j,int row, int col){
        if(i >= row || i < 0 || j >= col || j < 0){
            return 0;
        }
        return 1;
    }
    int helpaterp(vector<vector<int>> arr)
    {
        //code here
        int n = arr.size();
        int m = arr[0].size();
        queue<pair<int,int>>q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j < m; j++){
                if(arr[i][j] == 2){
                    q.push(make_pair(i,j));
                }
            }
        }
        int cnt = 0;
        while(!q.empty()){
            int size = q.size();
            int x = 0;
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                if(valid(i+1,j,n,m) && arr[i+1][j] == 1){
                    arr[i+1][j] = 2;
                    q.push(make_pair(i+1,j));
                    x = 1;
                } if(valid(i-1,j,n,m) && arr[i-1][j+1] == 1){
                    q.push(make_pair(i-1,j));
                    arr[i-1][j] = 2;
                    x = 1;
                }
                 if(valid(i,j+1,n,m) && arr[i][j+1] == 1){
                    q.push(make_pair(i,j+1));
                    arr[i][j+1] = 2;
                    x = 1;
                }
                 if(valid(i,j-1,n,m) && arr[i][j-1] == 1){
                    q.push(make_pair(i,j-1));
                    arr[i][j-1] = 2;
                    x = 1;
                }
                
            }if(x) cnt++;
            
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(arr[i][j] == 1){
                    return -1;
                }
            }
        }
        return cnt;

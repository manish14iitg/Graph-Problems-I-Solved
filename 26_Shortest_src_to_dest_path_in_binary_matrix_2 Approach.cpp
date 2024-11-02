// Approach - 1
// T.C. => N*M , S.C. => N*M for visited vector + min(N,M) for queue max size

    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0] == 0 || A[X][Y] == 0)
        return -1;
        
        if(X == 0 && Y == 0)
        return 0;
        
        vector<vector<bool>> visited(N, vector<bool>(M,0));
        queue<pair<pair<int,int>,int>> q;
                    // i  , j   , step
        q.push({{0,0},0});
        visited[0][0] = 1;
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int step = q.front().second;
            q.pop();
            for(int k = 0; k< 4; k++){
                int new_i = row[k] + i;
                int new_j = col[k] + j;
                if(new_i >= 0 && new_i < N && new_j >= 0 && new_j < M && A[new_i][new_j] == 1 && visited[new_i][new_j] == 0) {
                    if(new_i == X && new_j == Y)
                    return step+1;
                    
                    q.push({{new_i,new_j},step+1});
                    visited[new_i][new_j] = 1;
                }
            }
        }
        
        return -1;
    }


// Approach - 2
// T.C. => N*M , S.C. => min(N,M) -> max size of queue
// to decrease space do not use visited matrix, instead make the node as 0 in given matrix so other nodes will not visit this node second time;
// Also no need to use step variable in queue, it is a level order traversal so we can keep track of levels with queue size as step increment;

    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0] == 0 || A[X][Y] == 0)
        return -1;
        
        if(X == 0 && Y == 0)
        return 0;
        
        queue<pair<int,int>> q;
                    // i  , j
        q.push({0,0});
        A[0][0] = 0; // at time of push in queue just make that node as 0, so any other node won.t be able to reach this node again;
        int step = 0;
        while(!q.empty()){
            
            int cnt = q.size();
            while(cnt--){
              int i = q.front().first;
              int j = q.front().second;
              q.pop();
              for(int k = 0; k< 4; k++){
                  int new_i = row[k] + i;
                  int new_j = col[k] + j;
                  if(new_i >= 0 && new_i < N && new_j >= 0 && new_j < M && A[new_i][new_j] == 1) {
                      if(new_i == X && new_j == Y)
                      return step+1;
                      
                      q.push({new_i,new_j});
                      A[new_i][new_j] = 0; // make this neeghbour node 0;
                  }
              }
            }
          step++;
        }
        
        return -1;
    }

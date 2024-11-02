  int row[8] = {2,2,-2,-2,1,-1,1,-1};
  int col[8] = {1,-1,1,-1,2,2,-2,-2};
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
      // converting in 0-based indexing
	    KnightPos[0]--;
	    KnightPos[1]--;
	    TargetPos[0]--;
	    TargetPos[1]--;
      
	    if(KnightPos[0] == TargetPos[0] && KnightPos[1] == TargetPos[1]) return 0;
	    
	    queue<pair<int,int>>q;
	    q.push({KnightPos[0],KnightPos[1]});
	    vector<vector<bool>>visited(N, vector<bool>(N,0));
	    visited[KnightPos[0]][KnightPos[1]] = 1;
	    
	    int step = 0;
	    while(!q.empty()){
	        int cnt = q.size();
	        while(cnt--){
	            int i = q.front().first;
	            int j = q.front().second;
	            q.pop();
	            for(int k = 0; k<8; k++){
	                int new_i = i + row[k];
	                int new_j = j + col[k];
	                if(new_i >= 0 && new_i < N && new_j >= 0 && new_j < N && visited[new_i][new_j] == 0){
	                    if(TargetPos[0] == new_i && new_j == TargetPos[1]) return step+1;
	                    
	                    q.push({new_i,new_j});
	                    visited[new_i][new_j] = 1;
	                }
	            }
	        }
	        step++;
	    }
	    return -1;
	}

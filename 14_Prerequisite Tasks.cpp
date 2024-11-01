bool isPossible(int N,int P, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<int> adjList[N];
	    for(int i = 0; i< P; i++){
	        adjList[pre[i].second].push_back(pre[i].first);
	    }
	    
	    vector<int>indegree(N,0);
	    for(int i = 0; i<N; i++){
	        for(int j = 0; j<adjList[i].size(); j++){
	            indegree[adjList[i][j]]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i = 0; i<N; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    int cnt = 0;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        cnt++;
	        for(int i = 0; i< adjList[node].size(); i++){
	            indegree[adjList[node][i]]--;
	            if(indegree[adjList[node][i]] == 0){
	                q.push(adjList[node][i]);
	            }
	        }
	    }
	    if(cnt == N)
	    return true;
	    return false;
	}

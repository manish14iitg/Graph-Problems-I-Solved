class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // create djancy list
        vector<int> adj[n];
        for(int i = 0; i < relations.size(); i++){
            adj[relations[i][0]-1].push_back(relations[i][1]-1);
        }

        // kahn's algo
        // indegree
        vector<int>indegree(n,0);
        for(int i = 0; i< n; i++){
            for(int j = 0; j< adj[i].size(); j++){
                indegree[adj[i][j]]++;
            }
        }
        queue<int>q;
        for(int i = 0; i< n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        // max time to complete prev course
        vector<int>prevCourseTime(n,0);
        while(!q.empty()){
            int maxi = INT_MIN;
            int size = q.size();
            while(size--){
                int node = q.front()+1;
                q.pop();
                
                for(int i = 0; i< adj[node-1].size(); i++){
                    indegree[adj[node-1][i]]--;
                    if(indegree[adj[node-1][i]] == 0){
                        q.push(adj[node-1][i]);
                        
                    }prevCourseTime[adj[node-1][i]] = max(prevCourseTime[adj[node-1][i]],time[node-1]+prevCourseTime[node-1]);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i< n; i++)
        ans = max(ans,prevCourseTime[i]+ time[i]);

        return ans;
        
    }
};

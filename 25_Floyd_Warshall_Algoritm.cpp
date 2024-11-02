void shortestDistance(vector<vector<int>>& mat) {
        // Code here
        // T.C. => O(V^3) , S.C. => O(1)
        int n = mat.size();
        for(int k = 0; k<n; k++) // k is intermediate
        for(int i = 0; i<n; i++) // i is starting node (u)
        for(int j = 0; j<n; j++) // j is ending node (v)
            if(mat[i][k] != -1 && mat[k][j] != -1){ // if we can't reach u to k OR k to v then why to check for intermediate path for this case;
                if(mat[i][j] == -1){ // if we can't reach u to v directly,  then obiously we have to go through intermediate k;
                    mat[i][j] = mat[i][k] + mat[k][j]; // u -> v = u -> k + k -> v
                }else{ // but if we can reach u -> v directly then we have to check which is minimum;
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        
    
    }

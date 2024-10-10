
vector<int>ans;
        vector<int>exploreIndex(V,-1);
        stack<int>st;
        ans.push_back(0);
        exploreIndex[0]=0;
        st.push(0);
        
        while(!st.empty())
        {
            //take out the node
            int node=st.top();
            //take out the index for exploration
            int j=exploreIndex[node];
            //explore
            while(j<adj[node].size())
            {
                if(exploreIndex[adj[node][j]]==-1) //unvisited
                {
                    exploreIndex[adj[node][j]]=0; //put the index for exploration
                    exploreIndex[node]++; //increase the index to be explored next time
                    st.push(adj[node][j]); //push the node into the stack
                    ans.push_back(adj[node][j]); //add the node to the answer
                    break;
                }
                j++;
            }
            
            if(j==adj[node].size()) //all adjacent nodes explored
            st.pop();
        }
        
  return ans;

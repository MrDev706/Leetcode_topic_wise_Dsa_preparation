
//Breadth -first- search

class solution{
    public: 
    vector<int> bfsOfGraph(int v, vector<int> adj[]){
        vector<bool> visited(v, false);
        int s=0;
        visited[s] = true;
        vector<int> res;
        queue<int> q;
        q.push(s);

        while(!q.empty()){
            int t = q.front();
            res.push(t);
            q.pop();
            for(auto x:adj[t]){
                if(!visited[x]){
                    v[visited] = true;
                    q.push(x);
                }
            }
        }


    }
}
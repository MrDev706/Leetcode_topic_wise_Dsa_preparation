//Count the number of nodes at given level in a tree using BFS

//GFG: https://www.geeksforgeeks.org/count-number-nodes-given-level-using-bfs/

class graph {
    int v;
    list<int> * adj;

    public:

    Graph(int v);
    void addEdge(int v, int w);
    int Bfs(int s, int l);

    Graph:: Graph(int v){
        this->v = v;
        adj = new list<int>[v];
    }

    Graph:: addEdge(int v, int w){
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    Graph:: Bfs(int s, int l){
        bool* visited new bool[v];
        int level[v];
        list<int> queue;
        visited[s] = true;
        queue.push(s);
        level[s] = 0;
        while(!queue.empty(){

            s = queue.front();
            queue.pop_front();

            for(auto i=adj[s].begin(); i!= adj[s].end(); ++i){
                if(!visited[*i]){
                    level[*i] = level[s] + 1;
                    visited[*i] = true;
                    queue.push_back(*i); 
                }
            }
        })
           int count = 0;
    for (int i = 0; i < V; i++)
        if (level[i] == l)
            count++;   
    return count; 



    }


}
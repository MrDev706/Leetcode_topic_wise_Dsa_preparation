//Find the number of trees in a forest

/*Explanation : There are 2 trees
                   0       3
                  / \       \
                 1   2       4
                 */

//  Input :  edges[] = {0, 1}, {0, 2}, {3, 4}


void addEdge(vector<int>adj[], int i, int v){
    adj[v].push_back(i);
    adj[i].push_back(v);
}
void dfsTil(int u, vector<int> adj[], vector<bool>&visited){
    visited[u] = true;
    for(int l=0; i<adj[u].size(); i++){
        if(visited[adj[u][l]] == false){
            dfsTil(adj[u][l], adj, visited);
        }
    }

}

int coutForest(vector<int> adj[], int v){
    vector<bool> visited(v);
    for(int i=0; i<v; i++){
        if(visited[i]==false){
            dfsTil(i, adj, visited);
            res++;
        }
    }
    return res;
}
int main(){
    int v = 5;
    vector<int>adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 3, 4);
    cout<<countForest(adj, v);
    return 0;
}


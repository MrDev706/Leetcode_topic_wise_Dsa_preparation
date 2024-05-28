//Count nodes within K-distance from all nodes in a set
//https://www.geeksforgeeks.org/count-nodes-within-k-distance-from-all-nodes-in-a-set/


int nodesKDistanceFromMarked(int edges[][2], int V, int[] marked, int N, int K){
    V = V+1;
    vector<int> g[V];
    int u, v;

    for(int i=0; i<(V-1); i++){
        u = edges[i][0];
        v = edges[i][1];
        g[u].push_back(v);
        g[v].push_back(u);

    }
    bool mark[V] = {false};

    for(int i =0; i<N; i++){
        mark[marked[i]] = true;
    }

    vector<int> tmp(V, -1), dl(V, -1), dr(V, -1);

    u = bfsWithDist(g, mark, 0, tmp);
    v = bfsWithDist(g, mark, u, dl);
    bfsWithDist(g, mark, v, dr);

}



int main(){

    int edges[][2] =
    {
        {1, 0}, {0, 3}, {0, 8}, {2, 3},
        {3, 5}, {3, 6}, {3, 7}, {4, 5},
        {5, 9}
    };

    int v = sizeof(edges)/sizeof(edges[0]);
    int marked[] = {1, 2, 4};
    int N = sizeof(marked) / sizeof(marked[0]);
 
    int K = 3;
    cout << nodesKDistanceFromMarked(edges, V, marked, N, K);
    return 0;
}
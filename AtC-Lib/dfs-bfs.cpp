#include<bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

// dfs
vector<bool> seen;
void dfs(Graph &G, int start){
    seen[start] = true;
    for(auto next_v : G[start])
    {
        if(seen[next_v])	continue;
        dfs(G, next_v);
    }
}


// bfs
vector<int> bfs(Graph &G, int start){
    int graph_size = (int)G.size();
    vector<int> dist(graph_size, -1);
    queue<int> que;
    dist[start] = 0;
    que.push(start);
    while(!que.empty()){
        int visit = que.front();
        que.pop();
        for(int next_visit : G[visit]){
            if(dist[next_visit]!=-1)
                continue;
            dist[next_visit] = dist[visit]+1;
            que.push(next_visit);
        }
    }
    return dist;
}
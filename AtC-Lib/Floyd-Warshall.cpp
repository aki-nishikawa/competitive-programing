#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1LL<<60;

struct Edge{
    int to;
    ll weight;
    Edge(int to, ll weight):to(to), weight(weight){}
};
using Graph = vector<vector<Edge>>;

vector<vector<ll>> Floyd_Warshall(Graph &G){
    int graph_size = G.size();
    vector<vector<ll>> res(graph_size+1, vector<ll>(graph_size+1, INF));
    for(int i = 1; i < graph_size; i++){
        if(G[i].size() == 0)    continue;
        res[i][i] = 0;
        for(auto &x : G[i])  res[i][x.to] = x.weight;
    }
    for(int k = 1; k < graph_size; k++)
        for(int i = 1; i < graph_size; i++)
            for(int j = 1; j < graph_size; j++)
                res[i][j] = min(res[i][j], res[i][k] + res[k][j]);
    return res;
}

int main(){
    int n, m;
    cin >> n >> m;
    Graph G(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        ll weight;
        cin >> a >> b >> weight;
        G[a].push_back(Edge(b,weight));
    }
}
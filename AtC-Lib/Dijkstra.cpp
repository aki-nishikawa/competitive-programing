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

vector<ll> Dijkstra(Graph &G, int start){
    int graph_size = (int)G.size();
    vector<ll> distance(graph_size, INF);
    priority_queue<pair<ll, int>,
                    vector<pair<ll, int>>,
                    greater<pair<ll, int>>> que;
    distance[start] = 0;
    que.push(make_pair(distance[start], start));
    while(!que.empty()){
        auto [dist ,visit] = que.top();
        que.pop();
        if (distance[visit] != dist) continue;
        for(Edge& next_edge : G[visit]){
            ll next_dist = dist + next_edge.weight;
            if(distance[next_edge.to] <= next_dist) continue;
            distance[next_edge.to] = next_dist;
            que.push(make_pair(distance[next_edge.to], next_edge.to));
        }
    }
    return distance;
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
        G[b].push_back(Edge(a,weight));
    }
}
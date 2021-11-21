#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

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

int main(){
    int n;  cin >> n;
    vector<ll> ts(n);
    Graph G(n);
    seen.assign(n, false);
    rep(i, n)
    {
        cin >> ts[i];
        int k;  cin >> k;
        rep(j, k){
            int to; cin >> to;
            G[i].push_back(to-1);
        }
    }
    seen[n-1] = true;
    dfs(G, n-1);
    ll ans = 0;
    rep(i, n)
    {
        if(seen[i]) ans += ts[i];
    }
    cout << ans << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

struct UnionFind{
    vector<int> fr, bc;
    UnionFind(int n) : fr(n, -1), bc(n, -1) {}
    int root(int x){
        if(fr[x]==-1)
            return x;
        else
            return root(fr[x]);
    }
    void unite(int x, int y){
        bc[x] = y;
        fr[y] = x;
    }
    void dis(int x, int y){
        bc[x] = -1;
        fr[y] = -1;
    }
    vector<int> echo(int x){
        int rx = root(x);
        vector<int> res(1, rx);
        while(bc[rx] != -1){
            rx = bc[rx];
            res.push_back(rx);
        }
        return res;
    }
};
int main(){
    int n, q;   cin >> n >> q;
    auto uf = UnionFind(n+1);
    rep(i, q){
        int t, x, y;    cin >> t;
        if(t == 1){
            cin >> x >> y;
            uf.unite(x, y);
        }else if(t ==2){
            cin >> x >> y;
            uf.dis(x, y);
        }else{
            cin >> x;
            auto vec = uf.echo(x);
            cout << vec.size() << ' ';
            for(auto x : vec)   cout << x << ' ';
            cout << endl;
        }
    }
    return 0;
}
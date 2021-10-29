#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct UnionFind{
    vector<int> par, siz;
    UnionFind(int n) : par(n, -1), siz(n, 1) {}

    int root(int x){
        if(par.at(x)==-1)
            return x;
        else
            return par[x] = root(par.at(x));
    }
    bool ifsame(int x, int y){
        return root(x) == root(y);
    }
    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if (rx == ry)
            return;
        if(siz.at(x)<siz.at(y))
            swap(x, y);
        par.at(y) = rx;
        siz.at(x) += siz.at(y);
    }
    int size(int x){
        return siz.at(root(x));
    }
};
#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
    int n, m;   cin >> n >> m;
    ll st = 0;
    bool ans = true;
    rep(i, n)   rep(j, m){
        ll b;   cin >> b;
        if(i == 0 && j == 0){
            st = b;
        }else{
            if(b != st + (i * 7) + j)   ans = false;
            if(b%7 == 0 && j != m-1)    ans = false;
            if(b%7 == 1 && j != 0)  ans = false;
        }
    }
    if(ans) cout << "Yes" << endl;
    else    cout << "No" << endl;
    return 0;
}
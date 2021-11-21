#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
    int n;  cin >> n;
    vector<ll> x(n), y(n);
    rep(i, n)   cin >> x[i] >> y[i];
    map<pair<ll, ll>, int> mp;
    int ans = 0;
    rep(i, n)
    {
        for(int j = i + 1; j < n; j++)
        {
            ll dx = x[j] - x[i];
            ll dy = y[j] - y[i];
            ll g = __gcd(abs(dx), abs(dy));
            if(mp[make_pair(dx/g, dy/g)] == 0)
            {
                ans++;
                mp[make_pair(dx/g, dy/g)]++;
            }
            if(mp[make_pair(-dx/g, -dy/g)] == 0)
            {
                ans++;
                mp[make_pair(-dx/g, -dy/g)]++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
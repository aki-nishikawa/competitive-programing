#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
    string x;   cin >> x;
    int ans = 0;
    for(auto c : x)
    {
        if(c == '.')    break;
        ans *= 10;
        ans += c - '0';
    }
    if(x[(int)(x.size())-3] - '0' >= 5) ans++;
    cout << ans << endl;
    return 0;
}
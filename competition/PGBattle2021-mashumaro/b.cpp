#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main(){
    string x;   cin >> x;
    string ans;
    bool f = false;
    for(auto c : x){
        if(c == '0' && !f){
            ans += '1';
            f = true;
        }else if(f) ans += '1';
        else    ans += c;
    }
    cout << ans << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
    int n;  cin >> n;
    int w,x,y;
    bool ans = true;
    rep(i, n-1){
        int a, b;   cin >> a >> b;
        if(i == 0){
            w = a, x = b;
        }else if(i == 1){
            if(a == w)  y = a;
            else if(a == x) y = a;
            else if(b == w) y = b;
            else if(b == x) y = b;
            else{
                ans = false;
                break;
            }
        }else{
            if(a != y && b != y){
                ans = false;
                break;
            }
        }
    }
    if(ans) cout << "Yes" << endl;
    else    cout << "No" << endl;
    return 0;
}
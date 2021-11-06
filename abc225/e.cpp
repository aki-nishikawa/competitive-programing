#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
const double PI = 3.14159265358979;
const double INF = 1.797693e+308;

bool compare_by_b(pair<double, double> a, pair<double, double> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main(){
    int n;  cin >> n;
    vector<pair<double, double>> vec, tmp;
    rep(i, n){
        ll x, y;    cin >> x >> y;
        double a, b;
        a = (double)(y-1)/(double)(x);
        if(x == 1)   b = INF;
        else    b = (double)(y)/(double)(x-1);
        vec.push_back(make_pair(a, b));
        tmp.push_back(make_pair(x, y));
    }
    //cout << "########## input ##########" << endl;
    //for(auto &[a, b]: tmp)
    //    cout << a << " : " << b << endl;
    //cout << "########## fraction ##########" << endl;
    //for(auto &[a, b]: vec)
    //    cout << a << " : " << b << endl;
    sort(vec.begin(), vec.end(), compare_by_b);
    //cout << "########## sorted ##########" << endl;
    //for(auto &[a, b]: vec)
    //    cout << a << " : " << b << endl;
    //cout << "########## answer ##########" << endl;
    int ans = 0;
    double now = 0;
    for(auto &[a, b]: vec)
    {
        if(a >= now){
            ans++;
            now = b;
            //cout << a << " : " << b << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
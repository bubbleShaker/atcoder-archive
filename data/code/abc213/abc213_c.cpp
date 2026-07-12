#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

vector<int> compress(vector<int> a) {
    int n = a.size();
    map<int,int> mp;
    rep(i,n) mp[a[i]] = 0;
    int id = 1;
    for(auto& p : mp) p.second = id++;
    rep(i,n) a[i] = mp[a[i]];
    return a;
}

int main(void){
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i] >> b[i];
    a = compress(a);
    b = compress(b);
    rep(i,n) {
        cout << a[i] << " " << b[i] << endl;
    }
    return 0;
}

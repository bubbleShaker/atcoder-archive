#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int m;
    cin >> m;
    vector<int> d(m);
    rep(i,m) cin >> d[i];
    int sum = 1;
    rep(i,m) sum += d[i];
    int cen = sum/2;
    int mo = 0;
    rep(i,m) {
        cen -= d[i];
        if(cen <= 0) {
            cen += d[i];
            mo = i+1;
            break;
        }
    }
    cout << mo << " " << cen << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int ma = 0;
    int mai = -1;
    rep(i,n){
        if(h[i] > ma) {
            ma = h[i];
            mai = i+1;
        }
    }
    cout << mai << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using T = tuple<int,int,int>;

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string s = "", t = "";
    rep(i,3) {
        char c;
        cin >> c;
        s += c;
    }
    rep(i,3) {
        char c;
        cin >> c;
        t += c;
    }
    int d = 0;
    rep(i,3) if(s[i] != t[i]) d++;
    if(d == 0 || d == 3) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
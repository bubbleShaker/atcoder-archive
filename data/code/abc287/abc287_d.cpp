#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    string s, t;
    cin >> s >> t;
    int st = (int)t.size();
    vector<vector<bool>> vs(2, vector<bool>(st+1, true));
    rep(i,st) {
        if(s[i] != t[i]) {
            if(s[i] != '?' && t[i] != '?') {
                vs[1][i+1] = false;
            }
        }
    }
    int ss = (int)s.size();
    for(int i = ss-st; i < ss; i++) {
        int ti = i-(ss-st);
        if(s[i] != t[ti]) {
            if(s[i] != '?' && t[ti] != '?') {
                vs[0][ti] = false;
            }
        }
    }
    for(int i = st-2; i >= 0; i--) {
        if(vs[0][i+1] == false) vs[0][i] = false;
    }
    for(int i = 2; i < st+1; i++) {
        if(vs[1][i-1] == false) vs[1][i] = false;
    }
    rep(i,st+1) {
        if(vs[0][i] && vs[1][i]) {
            cout << "Yes" << endl;
        }else cout << "No" << endl;
    }
    return 0;
}

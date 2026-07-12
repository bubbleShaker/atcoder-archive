#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    string s;
    cin >> s;
    int n = (int)s.size();
    int ans = -1;
    rep(i,n) {
        if(s[i] == 'a') ans = i+1;
    }
    cout << ans << endl;
    return 0;
}

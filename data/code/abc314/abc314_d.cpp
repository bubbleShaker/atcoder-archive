#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(void){
    int n, q;
    string s;
    cin >> n >> s >> q;
    vector<int> lt(n);
    int last = -1, type = 2;
    rep(qi,q) {
        int t, x; char c;
        cin >> t >> x >> c;
        if(t == 1) {
            x--;
            s[x] = c;
            lt[x] = qi;
        } else {
            last = qi;
            type = t;
        }
    }
    
    rep(i,n) {
        if (lt[i] < last) {
            if (type == 2) s[i] = tolower(s[i]);
            else s[i] = toupper(s[i]);
        }
    }
    cout << s << endl;
    return 0;
}

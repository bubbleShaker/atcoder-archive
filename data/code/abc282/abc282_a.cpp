#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(void){
    int k;
    cin >> k;
    string s = "";
    rep(i,k) {
        s += 'A' + i;
    }
    cout << s << endl;
    return 0;
}

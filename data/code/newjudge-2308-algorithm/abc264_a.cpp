#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(void){
    string s = "atcoder";
    int l, r;
    cin >> l >> r;
    cout << s.substr(l-1, r-l+1);
    return 0;
}

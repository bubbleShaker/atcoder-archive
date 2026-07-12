#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int n, m, p;
    cin >> n >> m >> p;
    n -= m;
    if(n<0) {
        cout << 0 << endl;
        return 0;
    }
    n /= p;
    cout << n+1 << endl;
    return 0;
}

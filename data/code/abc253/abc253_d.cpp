#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    ll n, a, b;
    cin >> n >> a >> b;
    ll c = lcm(a, b);
    ll qa = n/a;
    ll qb = n/b;
    ll qc = n/c;
    ll s0 = n*(n+1)/2;
    ll sa = a*qa*(qa+1)/2;
    ll sb = b*qb*(qb+1)/2;
    ll sc = c*qc*(qc+1)/2;
    cout << s0-(sa+sb)+sc << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 0; i < n-1; i++) {
        if(a[i]+1 != a[i+1]) {
            cout << a[i]+1 << endl;
            return 0;
        }
    }
    return 0;
}

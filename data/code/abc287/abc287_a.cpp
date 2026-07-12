#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for(int i = 0; i < n; ++i)
using namespace std;
using namespace atcoder;

int main(void){
    int n;
    cin >> n;
    vector<string> v(n);
    rep(i,n) cin >> v[i];
    int mi = (int)ceil((double)n/2);
    int c = 0;
    rep(i,n) {
        if(v[i] == "For") c++;
    }
    if(c < mi){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}

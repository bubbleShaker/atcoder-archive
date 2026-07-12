#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int n;
    cin >> n;
    int l = 1, r = n;
    while(r-l > 1) {
        int cen = (l+r)/2;
        cout << "? " << cen << endl;
        int s; cin >> s;
        if(s == 0) l = cen;
        else r = cen;
    }
    cout << "! " << l << endl;
    return 0;
}

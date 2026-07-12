#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    if(n%2) cout << "Black" << endl;
    else cout << "White" << endl;
    return 0;
}
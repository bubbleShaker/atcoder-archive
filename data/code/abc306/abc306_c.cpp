#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

int main(void){
    int n;
    cin >> n;
    int nn = n*3;
    vector<int> a(nn);
    rep(i,nn) {
        cin >> a[i];
    }
    map<int,int> mp;
    vector<int> ans;
    rep(i,nn) {
        mp[a[i]] += 1;
        if(mp[a[i]] == 2) {
            ans.push_back(a[i]);
        }
    }
    int si = ans.size();
    rep(i,si) {
        cout << ans[i] << " \n"[i+1 == si];
    }
    return 0;
}

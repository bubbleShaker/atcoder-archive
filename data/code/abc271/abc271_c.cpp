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
    set<int> ans;
    deque<int> deq,tmp;
    rep(i,n) {
        if(deq.empty()) {deq.push_back(a[i]); continue;}
        if(deq.back() != a[i]) deq.push_back(a[i]);
        else tmp.push_back(a[i]);
    }
    deq.insert(deq.end(), tmp.begin(), tmp.end());
    for(int i = 1; i <= n; i++) {
        if(deq.empty()) break;
        if(deq.front() == i) {
            ans.insert(i);
            deq.pop_front();
        }else {
            if((int)deq.size() >= 2) {
                rep(j,2) {
                    deq.pop_back();
                }
                ans.insert(i);
            }else break;
        }
    }

    cout << (int)ans.size() << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    int n;
    cin >> n;
    string s;
    cin >> s;
    deque<int> dq;
    dq.push_back(n);
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == 'R') dq.push_front(i);
        if(s[i] == 'L') dq.push_back(i);
    }
    for(int v : dq){
        cout << v << " ";
    }
    return 0;
}

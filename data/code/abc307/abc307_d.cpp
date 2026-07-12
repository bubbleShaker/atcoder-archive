#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;
using llP = pair<ll,ll>;

int main(void){
    int n;
    cin >> n;
    string s;
    cin >> s;
    deque<string> dq;
    dq.push_back("");
    
    rep(i,n) {
        if(s[i] == '(') dq.push_back("(");
        else if(s[i] == ')') {
            if((int)dq.size() == 1) {
                dq.back().push_back(')');
            }
            else dq.pop_back();
        }
        else {
            dq.back().push_back(s[i]);
        }
    }
    for(auto s : dq){
        cout << s;
    }
    return 0;
}

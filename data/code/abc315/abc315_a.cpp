#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
using P = pair<int,int>;

int main(void){
    string s;
    cin >> s;
    string ans;
    string b = "aiueo";
    set<char> st;
    rep(i,(int)b.size()){
        st.insert(b[i]);
    }
    rep(i,(int)s.size()) {
        if(!st.count(s[i])){
            ans.push_back(s[i]);
        }
    }
    cout << ans << endl;
    return 0;
}

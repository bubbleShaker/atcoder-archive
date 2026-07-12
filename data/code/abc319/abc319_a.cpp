#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
using ll = long long;
using vi = vector<int>;
using P = pair<int,int>;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    map<string, int> mp;
    vector<string> s = {"tourist",
    "ksun48" ,
    "Benq" ,
    "Um_nik" ,
    "apiad" ,
    "Stonefeang",
    "ecnerwala" ,
    "mnbvmar" ,
    "newbiedmy" ,
    "semiexp" };
    vector<int> v = {
        3858,
        3679,
        3658,
        3648,
        3638,
        3630,
        3613,
        3555,
        3516,
        3481
    };
    rep(i,10) {
        mp[s[i]] = v[i];
    }
    string ts;
    cin >> ts;
    cout << mp[ts] << endl;
    return 0;
}
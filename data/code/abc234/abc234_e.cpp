#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ull = unsigned long long;
using ll = long long;
using Int = long long;
using vi = vector<int>;
using P = pair<int,int>;
using lP = pair<ll,ll>;
using dP = pair<double,double>;
using T = tuple<int,int,int>;
using lT = tuple<ll,ll,ll>;
using dT = tuple<double,double,double>;
using mint = modint1000000007;
#define rep(i,n) for(Int i = 0; i < (Int)n; ++i)
#define all(X) (X).begin(), (X).end()
#define rall(X) (X).rbegin(), (X).rend()
const int INF = INT_MAX / 2;
const ll INFL = 1LL << 60;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);
    
    Int x; cin >> x;
    set<Int> st;
    for(Int k = 1; k <= 10; k++) { 
        for(Int i = 1; i <= 9; i++) { //始点
            for(Int j = 0; j <= 9; j++) { 
                vector<Int> num;
                Int base = i;
                rep(l,k) {
                    num.push_back(base);
                    base += j;
                    if(base >= 10) break;
                }
                Int n = num.size();
                if(n != k) continue;
                Int val = 0;
                rep(l,k) {
                    val = val*10 + num[l];
                }
                st.insert(val);
            }
        }
    }
    for(Int k = 1; k <= 10; k++) {
        for(Int i = 9; i >= 1; i--) { //始点
            for(Int j = 0; j <= 9; j++) { 
                vector<Int> num;
                Int base = i;
                rep(l,k) {
                    num.push_back(base);
                    base -= j;
                    if(base < 0) break;
                }
                Int n = num.size();
                if(n != k) continue;
                Int val = 0;
                rep(l,k) {
                    val = val*10 + num[l];
                }
                st.insert(val);
            }
        }
    }
    st.insert(1111111111);
    st.insert(2222222222);
    st.insert(3333333333);
    st.insert(4444444444);
    st.insert(5555555555);
    st.insert(6666666666);
    st.insert(7777777777);
    st.insert(8888888888);
    st.insert(9999999999);
    
    st.insert(11111111111);
    st.insert(22222222221);
    st.insert(33333333333);
    st.insert(44444444444);
    st.insert(55555555555);
    st.insert(66666666666);
    st.insert(77777777777);
    st.insert(88888888888);
    st.insert(99999999999);
    
    st.insert(111111111111);
    st.insert(222222222222);
    st.insert(333333333333);
    st.insert(444444444444);
    st.insert(555555555555);
    st.insert(666666666666);
    st.insert(777777777777);
    st.insert(888888888888);
    st.insert(999999999999);
    
    st.insert(1111111111111);
    st.insert(2222222222222);
    st.insert(3333333333333);
    st.insert(4444444444444);
    st.insert(5555555555555);
    st.insert(6666666666666);
    st.insert(7777777777777);
    st.insert(8888888888888);
    st.insert(9999999999999);
    
    st.insert(11111111111111);
    st.insert(22222222222222);
    st.insert(33333333333333);
    st.insert(44444444444444);
    st.insert(55555555555555);
    st.insert(66666666666666);
    st.insert(77777777777777);
    st.insert(88888888888888);
    st.insert(99999999999999);
    
    st.insert(111111111111111);
    st.insert(222222222222222);
    st.insert(333333333333333);
    st.insert(444444444444444);
    st.insert(555555555555555);
    st.insert(666666666666666);
    st.insert(777777777777777);
    st.insert(888888888888888);
    st.insert(999999999999999);
    
    st.insert(1111111111111111);
    st.insert(2222222222222222);
    st.insert(3333333333333333);
    st.insert(4444444444444444);
    st.insert(5555555555555555);
    st.insert(6666666666666666);
    st.insert(7777777777777777);
    st.insert(8888888888888888);
    st.insert(9999999999999999);
    
    st.insert(11111111111111111);
    st.insert(22222222222222222);
    st.insert(33333333333333333);
    st.insert(44444444444444444);
    st.insert(55555555555555555);
    st.insert(66666666666666666);
    st.insert(77777777777777777);
    st.insert(88888888888888888);
    st.insert(99999999999999999);
    
    st.insert(111111111111111111);
    auto itr = st.lower_bound(x);
    cout << *itr << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int n, p, q, r, s;
    cin >> n >> p >> q >> r >> s;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<int> pq, rs;
    for(int i = p-1; i < q; i++){
        int t = a[i];
        pq.push_back(t);
    }
    for(int i = r-1; i < s; i++){
        int t = a[i];
        rs.push_back(t);
    }
    for(int i = p-1; i < q; i++){
        a[i] = rs[i-(p-1)];
    }
    for(int i = r-1; i < s; i++){
        a[i] = pq[i-(r-1)];
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " \n"[i+1 == n];
    }
    return 0;
}

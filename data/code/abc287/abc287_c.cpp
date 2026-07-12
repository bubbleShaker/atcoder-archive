#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

bool solve(){
    int N, M;
    cin >> N >> M;
    dsu uf(N);
    vector<int> deg(N);
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        uf.merge(u, v);
        deg[u]++; deg[v]++;
    }

    int co = 0;
    int ct = 0;
    for(int i = 0; i < N; i++){
        if(deg[i] == 1) co++;
        else if(deg[i] == 2) ct++;
    }

    if(!(co == 2 && ct == (N-2))) return false;

    int p = uf.leader(0);

    for(int i = 1; i < N; i++){
        if(uf.leader(i) != p) return false;
    }
    return true;
}

int main(){
    if(solve()){
        cout << "Yes" << endl;
        return 0;
    }else{
        cout << "No" << endl;
        return 0;
    }
    return 0;
}

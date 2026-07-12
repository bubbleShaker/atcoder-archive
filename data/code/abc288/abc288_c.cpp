#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int N, M;
    cin >> N >> M;
    dsu uf(N);
    int ans = 0;
    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        A--; B--;
        if(uf.same(A, B)){
            ans++;
            continue;
        }else{
            uf.merge(A, B);
        }
    }
    cout << ans << endl;
    return 0;
}
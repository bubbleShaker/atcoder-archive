#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(2, vector<int>(M));
    for(int i = 0; i < M; i++) cin >> A[0][i] >> A[1][i];
    int K;
    cin >> K;
    vector<vector<int>> C(2, vector<int>(K));
    for(int i = 0; i < K; i++) cin >> C[0][i] >> C[1][i];
    
    int ans = 0;
    
    for(int bit = 0; bit < 1 << K; bit++){
        int count = 0;
        int mask = bit;
        vector<int> t(K);
        vector<bool> d(N+1);
        for(int i = 0; i < K; i++){
            if(mask & 1) t[i] = 1;
            mask = mask >> 1;
        }
        for(int i = 0; i < K; i++){
            int tmp = t[i];
            d[C[tmp][i]] = true;
        }
        
        for(int i = 0; i < M; i++){
            if(d[A[0][i]] && d[A[1][i]]) count++;
        }
        
        ans = max(ans, count);
    }
    cout << ans << endl;
    return 0;
}
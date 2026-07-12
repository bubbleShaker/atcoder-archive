#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for(int i = 1; i <= N; i++)
typedef long long ll;
vector<vector<ll>> A(110, vector<ll>(110));

int main(void){
    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> A[i][j];
        }
    }
    
    ll ans = 0;
    
    for(int i = 0; i < M; i++){
        for(int j = i+1; j < M; j++){
            ll sum = 0;
            for(int k = 0; k < N; k++){
                sum += max(A[k][i], A[k][j]);
            }
            if(sum > ans) ans = sum;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}

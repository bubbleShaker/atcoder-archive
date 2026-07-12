#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> a(M, vector<int>(N));
    vector<vector<bool>> ch(N, vector<bool>(N, false));
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> a[i][j];
        }
    }
    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N-1; j++){
            int tmp1 = a[i][j];
            int tmp2 = a[i][j+1];
            ch[tmp1-1][tmp2-1] = true;
            ch[tmp2-1][tmp1-1] = true;
        }
    }
    
    int ans = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            if(!ch[i][j]) ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
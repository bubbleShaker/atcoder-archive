#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N, D;
    cin >> N >> D;
    vector<string> S(N);
    vector<vector<int>> t(N, vector<int>(D));
    for(int i = 0; i < N; i++) cin >> S[i];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < D; j++){
            if(S[i][j] == 'o') t[i][j] = 1;
        }
    }
    
    for(int i = 0; i < N-1; i++){
        for(int j = 0; j < D; j++){
            t[i+1][j] = t[i+1][j] * t[i][j];
        }
    }
    
    int ans = 0;
    int ma = 0;
    
    for(int i = 0; i < D; i++){
        if(t[N-1][i] == 1) ans++;
        else ans = 0;
        ma = max(ans, ma);
    }
    
    cout << ma << endl;
    
    return 0;
}
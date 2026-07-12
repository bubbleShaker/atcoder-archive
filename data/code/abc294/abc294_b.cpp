#include <bits/stdc++.h>
using namespace std;

int main(void){
    int h, w;
    cin >> h >> w;
    vector<vector<int>> A(h, vector<int>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> A[i][j];
        }
    }
    
    vector<string> S(h);
    
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(A[i][j] == 0) S[i].push_back('.');
            else{
                int tmp = A[i][j] - 1;
                S[i].push_back('A'+tmp);
            }
        }
    }
    
    for(int i = 0; i < h; i++) cout << S[i] << endl;
    return 0;
}
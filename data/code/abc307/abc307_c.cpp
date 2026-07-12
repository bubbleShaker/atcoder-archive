#include <bits/stdc++.h>
using namespace std;

int main(void){
    int HA, WA, HB, WB, HX, WX;
    cin >> HA >> WA;
    vector<string> A(HA);
    for(int i = 0; i < HA; i++){
        cin >> A[i];
    }
    cin >> HB >> WB;
    vector<string> B(HB);
    for(int i = 0; i < HB; i++){
        cin >> B[i];
    }
    cin >> HX >> WX;
    vector<string> X(HX);
    for(int i = 0; i < HX; i++){
        cin >> X[i];
    }
    
    vector<string> C(31);
    for(int i = 0; i < 31; i++){
        C[i] = "...............................";
    }
    
    int A_c = 0;
    
    for(int i = 0; i < HA; i++){
        for(int j = 0; j < WA; j++){
            if(A[i][j] == '#') A_c++;
        }
    }
    
    int B_c = 0;
    
    for(int i = 0; i < HB; i++){
        for(int j = 0; j < WB; j++){
            if(B[i][j] == '#') B_c++;
        }
    }
    
    int X_c = 0;
    
    for(int i = 0; i < HX; i++){
        for(int j = 0; j < WX; j++){
            if(X[i][j] == '#') X_c++;
        }
    }
    
    for(int dx = 0; dx < 31 - HA + 1; dx++){
        for(int dy = 0; dy < 31 - WA + 1; dy++){
            for(int i = 0; i < HA; i++){
                for(int j = 0; j < WA; j++){
                    C[i+dx][j+dy] = A[i][j];
                }
            }
            vector<string> tmp = C;
            for(int i = 0; i < 31 - HB + 1; i++){
                for(int j = 0; j < 31 - WB + 1; j++){
                    for(int k = 0; k < HB; k++){
                        for(int l = 0; l < WB; l++){
                            if(C[i+k][j+l] == '#') continue;
                            C[i+k][j+l] = B[k][l];
                        }
                    }
                    
                    int C_c = 0;
                    for(int k = 0; k < 31; k++){
                        for(int l = 0; l < 31; l++){
                            if(C[k][l] == '#') C_c++;
                        }
                    }
                    
                    bool f = true;
                    int T_c = 0;
                    for(int m = 9; m < HX + 9; m++){
                        for(int n = 9; n < WX + 9; n++){
                            if(C[m][n] != X[m-9][n-9]){
                                f = false;
                                break;
                            }
                            if(C[m][n] == '#') T_c++;
                        }
                        if(!f) break;
                    }
                    if(f){
                        if(T_c == C_c){
                            cout << "Yes" << endl;
                            return 0;
                        }
                    }
                        
                    C = tmp;
                }
            }
            for(int i = 0; i < 31; i++){
                C[i] = "...............................";
            }
        }
    }
    
    cout << "No" << endl;
    return 0;
}
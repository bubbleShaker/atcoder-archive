#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    string S;
    cin >> N >> S;
    
    bool flag = false;
    for(int i = 0; i < N; i++) if(S[i] == 'o') flag = true;
    
    for(int i = 0; i < N; i++) if(S[i] == 'x') flag = false;
    
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}

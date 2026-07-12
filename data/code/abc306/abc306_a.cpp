#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    string S;
    string nS = "";
    
    cin >> N >> S;
    
    for(int i = 0; i < N; i++){
        nS.push_back(S[i]);
        nS.push_back(S[i]);
    }
    
    cout << nS << endl;
    
    return 0;
}

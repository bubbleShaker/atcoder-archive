#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N;
    string S;
    cin >> N >> S;
    
    int ind;
    
    for(int i = 0; i < N; i++){
        if(S[i] == '*') ind = i;
    }
    
    int count = 0;
    
    for(int i = 0; i < ind; i++){
        if(S[i] == '|') count++;
    }
    
    if(count == 0 || count == 2){
        cout << "out" << endl;
    }else{
        cout << "in" << endl;
    }
    
    return 0;
}

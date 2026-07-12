#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    vector<string> W(N);
    for(int i = 0; i < N; i++) cin >> W[i];
    
    for(int i = 0; i < N; i++){
        if(W[i] == "and" || W[i] == "not" || W[i] == "that" || W[i] == "the" || W[i] == "you"){
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;
    return 0;
}

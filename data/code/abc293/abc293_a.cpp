#include <bits/stdc++.h>
using namespace std;

int main(void){
    string S;
    cin >> S;
    for(int i = 1; i <= (S.size()/2); i++){
        char tmp = S[2*i-1];
        S[2*i-1] = S[2*i-2];
        S[2*i-2] = tmp;
    }
    cout << S << endl;
    return 0;
}

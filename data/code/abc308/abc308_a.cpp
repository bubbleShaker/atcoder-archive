#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> S(8);
    bool f = true;
    int i;
    
    for(i = 0; i < 8; i++){
        cin >> S[i];
        if(S[i] < 99 || S[i] > 676) f = false;
        else if((S[i] % 25)) f = false;
    }
    
    for(i = 0; i < 7; i++){
        if(S[i] > S[i+1]) f = false;
    }
    
    cout << (f ? "Yes" : "No") << endl;
}
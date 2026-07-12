#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int N;
    cin >> N;
    
    vector<string> S(N);
    vector<ll> A(N);
    for(int i = 0; i < N; i++){
        cin >> S[i] >> A[i];
    }
    
    ll mi = 10000000000;
    int ind;
    
    for(int i = 0; i < N; i++){
        if(mi > A[i]){
            mi = A[i];
            ind = i;
        }
    }
    
    for(int i = 0; i < N; i++){
        cout << S[ind%N] << endl;
        ind++;
    }
    
    return 0;
}

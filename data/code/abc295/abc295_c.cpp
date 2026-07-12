#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

int main(void){
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    
    ll c = 0;
    
    for(int i = 0; i < N - 1; i++){
        if(A[i] == A[i+1]){
            c++;
            A[i] = -1;
            A[i+1] = -1;
        }
    }
    
    cout << c << endl;
    return 0;
}
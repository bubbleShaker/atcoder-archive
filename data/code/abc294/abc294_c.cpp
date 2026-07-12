#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

int main(void){
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    vector<ll> B(M);
    
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];
    
    for(int i = 0; i < N; i++){
        ll t = A[i];
        ll ind = lower_bound(B.begin(), B.end(), t) - B.begin();
        cout << i + 1 + ind;
        if(i != N-1) cout << " ";
        else cout << endl;
    }
    
    for(int i = 0; i < M; i++){
        ll t = B[i];
        ll ind = lower_bound(A.begin(), A.end(), t) - A.begin();
        cout << i + 1 + ind;
        if(i != M-1) cout << " ";
        else cout << endl;
    }
    
    return 0;
}
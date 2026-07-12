#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int N, P, Q;
    cin >> N >> P >> Q;
    
    vector<int> D(N);
    for(int i = 0; i < N; i++) cin >> D[i];
    
    int mi = P;
    
    for(int i = 0; i < N; i++){
        mi = min(mi, Q+D[i]);
    }
    
    cout << mi << endl;
    
    return 0;
}

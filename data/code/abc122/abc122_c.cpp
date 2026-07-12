#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N, Q;
    string S;
    cin >> N >> Q >> S;
    
    vector<int> sum(N+1);
    for(int i = 0; i < N; i++){
        if(S[i] == 'A' && S[i+1] == 'C'){
            sum[i+1] = sum[i] + 1;
        }else{
            sum[i+1] = sum[i];
        }
    }
    
    for(int i = 0; i < Q; i++){
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << sum[r] - sum[l] << endl;
    }
    
    return 0;
}

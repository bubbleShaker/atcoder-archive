#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int Q;
    cin >> Q;
    
    bitset<100010> is_prime(0);
    for(int i = 2; i <= 100000; i++) is_prime.set(i);
    for(int i = 2; i <= 100000; i++){
        if(is_prime[i]){
            for(int j = 2*i; j <= 100000; j += i){
                is_prime.reset(j);
            }
        }
    }
    
    vector<int> s(100010);
    for(int i = 2; i <= 100000; i++){
        if(is_prime[i] && (i % 2) && is_prime[(i+1)/2]){
            s[i] = s[i-1] + 1;
        }else{
            s[i] = s[i-1];
        }
    }
    
    for(int i = 0; i < Q; i++){
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l-1] << endl;
    }
    
    return 0;
}
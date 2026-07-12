#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll N;
    
    cin >> N;
    
    if(N <= pow(10, 3.0) - 1){
        cout << N << endl;
        return 0;
    }
    
    for(int i = 3; i <= 8; i++){
        if(N >= pow(10, double(i)) && N <= pow(10, double(i+1)) - 1){
            int tmp = N / (ll)pow(10, (double)(i-2));
            cout << tmp*(ll)pow(10, (double)(i-2)) << endl;
            return 0;
        }
    }
}
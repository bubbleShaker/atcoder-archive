#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int N, Q;
    cin >> N >> Q;
    vector<int> c(N+1);
    for(int i = 0; i < Q; i++){
        int n, x;
        cin >> n >> x;
        if(n == 1){
            c[x]++;
        }else if(n == 2){
            c[x] += 2;
        }else{
            if(c[x] >= 2){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
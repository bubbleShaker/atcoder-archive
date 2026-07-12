#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int N;
    cin >> N;
    
    vector<int> s(2*N + 2);
    for(int i = 1; i <= N; i++){
        int p;
        cin >> p;
        s[2*i] = s[p] + 1;
        s[2*i+1] = s[p] + 1;
    }
    
    for(int i = 1; i <= 2*N + 1; i++){
        cout << s[i] << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    
    vector<string> A(N);
    
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    string t1, t2, t3, t4, ns1, ns2;
    
    t1 = A[0];
    t2 = A[N-1];
    
    
    for(int i = 0; i < N; i++){
        t3 += A[i][0];
        t4 += A[i][N-1];
    }
    
    ns1 = t3[1] + t1.substr(0, N-1);
    ns2 = t2.substr(1, N-1) + t4[N-2];
    
    cout << ns1 << endl;
    
    for(int i = 2; i < N; i++){
        string tmp = t3[i] + A[i-1].substr(1, N-2) + t4[i-2];
        cout << tmp << endl;
    }
    
    cout << ns2 << endl;
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<long int> L(87);
    int i, N;
    
    L.at(0) = 2;
    L.at(1) = 1;
    
    cin >> N;
    
    for(i = 2; i <= N; i++){
        L.at(i) = L.at(i-1) + L.at(i-2);
    }
    
    cout << L.at(N) << endl;
}
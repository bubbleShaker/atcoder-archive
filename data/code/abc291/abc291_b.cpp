#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    int n5 = n*5;
    vector<int> x(n5);
    for(int i = 0; i < n5; i++) cin >> x[i];
    sort(x.begin(), x.end());
    for(int i = 0; i < n; i++) x[i] = 0;
    reverse(x.begin(), x.end());
    for(int i = 0; i < n; i++) x[i] = 0;
    double sum = 0;
    for(int i = 0; i < n5; i++){
        sum += x[i];
    }
    
    sum /= (double)(3*n);
    cout << fixed << setprecision(10);
    cout << sum << endl;
    return 0;
}
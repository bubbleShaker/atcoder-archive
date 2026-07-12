#include <bits/stdc++.h>
using namespace std;
int main(){
    long long r,d;
    vector<long long> x(11);
    cin>>r>>d>>x[0];
    for(int i=1;i<=10;i++){
        x[i]=r*x[i-1]-d;
        cout<<x[i]<<endl;
    }
    return 0;
}
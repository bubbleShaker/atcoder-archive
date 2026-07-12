#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    long long bunsi=0,bunbo=1;
    for(int i=0;i<n;i++){
        bunbo=lcm(bunbo,a[i]);
    }
    for(int i=0;i<n;i++){
        bunsi+=bunbo/a[i];
    }
    cout<<fixed<<setprecision(10);
    cout<<(double)bunbo/bunsi<<endl;
    return 0;
}
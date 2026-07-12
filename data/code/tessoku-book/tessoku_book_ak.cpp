#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,b;
    cin>>n>>m>>b;
    vector<long long> a(n),c(m);
    long long aSum=0,cSum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        aSum+=a[i];
    }
    for(int i=0;i<m;i++){
        cin>>c[i];
        cSum+=c[i];
    }
    cout<<m*aSum+n*cSum+m*n*b<<endl;
    return 0;
}
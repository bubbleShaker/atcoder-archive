#include <bits/stdc++.h>
using namespace std;
long long fl(long long a,long long b){
    return a/b;
}
long long ce(long long a,long long b){
    return (a+(b-1))/b;
}
int main() {
    long long x;
    cin>>x;
    if(x<0){
        x=-x;
        cout<<-fl(x,10)<<endl;
    }else{
        cout<<ce(x,10)<<endl;
    }
    return 0;
}
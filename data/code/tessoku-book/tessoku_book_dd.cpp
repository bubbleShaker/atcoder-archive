#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long a3=n/3;
    long long a5=n/5;
    long long a7=n/7;
    long long a15=n/15;
    long long a35=n/35;
    long long a21=n/21;
    long long a105=n/105;
    cout<<a3+a5+a7+a105-a15-a35-a21<<endl;
    return 0;
}
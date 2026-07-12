#include <bits/stdc++.h>
using namespace std;

int main(){
    map<char,char> mapEnki;
    mapEnki['A']='T';
    mapEnki['T']='A';
    mapEnki['C']='G';
    mapEnki['G']='C';
    char b;cin>>b;
    cout<<mapEnki[b]<<endl;
    return 0;
}
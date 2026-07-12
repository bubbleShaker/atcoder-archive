#include <bits/stdc++.h>
using namespace std;
int main(){
    int h1,m1,h2,m2,k;cin>>h1>>m1>>h2>>m2>>k;
    int startTime=h1*60+m1;
    int endTime=h2*60+m2;
    cout<<endTime-startTime-k<<endl;
    return 0;
}
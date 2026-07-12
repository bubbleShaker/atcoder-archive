#include <bits/stdc++.h>
using namespace std;
int main(){
    int x,y;cin>>x>>y;
    for(int d=0;d<=x;d++){
        int t=x-d;
        if(d*2+t*4==y){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
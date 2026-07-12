#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;cin>>a>>b>>c>>d;
    int turn=0;
    while(a>0&&c>0){
        if(turn%2==0){
            c-=b;
        }else{
            a-=d;
        }
        turn++;
    }
    if(a<=0)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}
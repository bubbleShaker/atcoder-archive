#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    cin>>x>>y;
    int dif=y-x;
    if(dif>=0){
        if(dif<=2){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }else{
        if(abs(dif)<=3){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
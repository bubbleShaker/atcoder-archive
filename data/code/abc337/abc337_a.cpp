#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int sumT=0,sumA=0;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        sumT+=x;
        sumA+=y;
    }
    if(sumT>sumA){
        cout<<"Takahashi"<<endl;
    }else if(sumT<sumA){
        cout<<"Aoki"<<endl;
    }else{
        cout<<"Draw"<<endl;
    }
    return 0;
}
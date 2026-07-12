#include <bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin>>x;
    if(x<100){
        cout<<"No"<<endl;
    }else if(x%100!=0){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
    return 0;
}
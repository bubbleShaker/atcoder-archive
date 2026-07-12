#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> u(3),v;
    for(int i=0;i<3;i++){
        cin>>u[i];
    }
    v=u;
    sort(u.begin(),u.end());
    if(u[1]==v[1]){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}
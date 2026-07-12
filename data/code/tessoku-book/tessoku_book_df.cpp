#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,h,w;
    cin>>n>>h>>w;
    int ret=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        ret=ret^a^b;
    }
    if(ret==0){
        cout<<"Second"<<endl;
    }else{
        cout<<"First"<<endl;
    }
    return 0;
}
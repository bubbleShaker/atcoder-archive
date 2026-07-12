#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    int ret=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ret^=a[i];
    }
    if(ret==0){
        cout<<"Second"<<endl;
    }else{
        cout<<"First"<<endl;
    }
    return 0;
}
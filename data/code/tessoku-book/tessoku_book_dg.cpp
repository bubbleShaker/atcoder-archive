#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> grundy(100100);
    for(int i=0;i<=100000;i++){
        set<int> st;
        if(i-x>=0){
            st.insert(grundy[i-x]);
        }
        if(i-y>=0){
            st.insert(grundy[i-y]);
        }
        int gval=0;
        while(1){
            if(st.count(gval)==false){
                break;
            }else{
                gval++;
            }
        }
        grundy[i]=gval;
    }
    int ret=0;
    for(int i=0;i<n;i++){
        ret^=grundy[a[i]%5];
    }
    if(ret==0){
        cout<<"Second"<<endl;
    }else{
        cout<<"First"<<endl;
    }
    return 0;
}
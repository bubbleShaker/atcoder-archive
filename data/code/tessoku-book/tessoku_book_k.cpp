#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ok=0,ng=n;
    while(ng-ok>1){
        int mid=(ok+ng)/2;
        if(a[mid]<=x){
            ok=mid;
        }else{
            ng=mid;
        }
    }
    cout<<ok+1<<endl;
    return 0;
}
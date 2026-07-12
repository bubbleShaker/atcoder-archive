#include <bits/stdc++.h>
using namespace std;
int main(){
    int h,w;cin>>h>>w;
    int count=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w-1;j++){
            count++;
        }
    }
    for(int i=0;i<h-1;i++){
        for(int j=0;j<w;j++){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
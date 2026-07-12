#include <bits/stdc++.h>
using namespace std;
int main(){
    string base="wbwbwwbwbwbw";
    int w,b;
    cin>>w>>b;
    for(int i=0;i<100;i++){
        base+="wbwbwwbwbwbw";
    }
    int n=base.size();
    for(int i=0;i<12;i++){
        int wc=0,bc=0;
        int ind=i;
        while(ind<n){
            if(wc==w&&bc==b){
                break;
            }
            if(base[ind]=='w'){
                wc++;
            }else{
                bc++;
            }
            ind++;
        }
        if(wc==w&&bc==b){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> b(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>b[i][j];
            b[i][j]--;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            if(b[i][j]+1!=b[i][j+1]){
                cout<<"No"<<endl;
                return 0;
            }
            if(b[i][j]%7+1!=b[i][j+1]%7){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    for(int j=0;j<m;j++){
        for(int i=0;i<n-1;i++){
            if(b[i][j]+7!=b[i+1][j]){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector a(n,vector<char>(n));
    vector b(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>b[i][j];
            if(a[i][j]!=b[i][j]){
                cout<<i+1<<" "<<j+1<<endl;
                return 0;
            }
        }
    }
    return 0;
}
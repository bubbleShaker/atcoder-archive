#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> count(n);
    for(int i=1;i<n;i++){
        int a;cin>>a;a--;
        count[a]++;
    }
    for(int i=0;i<n;i++){
        cout<<count[i]<<endl;
    }
    return 0;
}
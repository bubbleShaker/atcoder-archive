#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a(3);
    for(int i=0;i<3;i++)cin>>a[i];
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<3;j++){
            if(i==j)continue;
            sum+=a[j];
        }
        if(a[i]==sum){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
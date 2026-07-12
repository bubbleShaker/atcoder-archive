#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string ans;
    for(int i=1;i<=n;i++){
        if(i%3==0){
            ans+="x";
        }else{
            ans+="o";
        }
    }
    cout<<ans<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    int ans;
    while(1){
        if(a>b){
            a=a%b;
            if(a==0){
                ans=b;
                break;
            }
        }else if(b>a){
            b=b%a;
            if(b==0){
                ans=a;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a,b;
    cin>>a>>b;
    long long ta=a,tb=b;
    long long ans;
    while(1){
        if(a>b){
            a=a%b;
            if(a==0){
                ans=b;
                break;
            }
        }else{
            b=b%a;
            if(b==0){
                ans=a;
                break;
            }
        }
    }
    a=ta;
    b=tb;
    cout<<(a*b)/ans<<endl;
    return 0;
}
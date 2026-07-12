#include <bits/stdc++.h>
using namespace std;
int main(){
    const int MOD=10000;
    int n;
    cin>>n;
    int ret=0;
    while(n--){
        char t;
        int a;
        cin>>t>>a;
        if(t=='+'){
            ret+=a;
        }else if(t=='-'){
            ret-=a;
        }else{
            ret*=a;
        }
        ret=(ret+MOD)%MOD;
        cout<<ret<<endl;
    }
    return 0;
}
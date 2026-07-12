#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        long long n;cin>>n;
        long long p,q;
        for(long long i=2;;i++){
            if(n%i==0){
                if((n/i)%i==0){
                    p=i;
                    q=(n/i)/i;
                }else{
                    p=(long long)sqrt((double)(n/i));
                    q=i;
                }
                break;
            }
        }
        cout<<p<<" "<<q<<endl;
    }
    return 0;
}
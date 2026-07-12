#include <bits/stdc++.h>
using namespace std;
int main() {
    int as=0,bs=0;
    for(int i=0;i<9;i++){
        int a;
        cin>>a;
        as+=a;
    }
    for(int i=0;i<8;i++){
        int b;
        cin>>b;
        bs+=b;
    }
    cout<<as-bs+1<<endl;
    return 0;
}
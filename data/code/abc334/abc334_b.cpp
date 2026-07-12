#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a,m,l,r;
    cin>>a>>m>>l>>r;
    long long li=(l-a)/m,ri=(r-a)/m;
    if((l-a)%m!=0&&li>=0)li++;
    if((r-a)%m!=0&&ri<0)ri--;
    cout<<ri-li+1<<endl;
    return 0;
}
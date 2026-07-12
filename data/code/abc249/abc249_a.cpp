#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,e,f,x;cin>>a>>b>>c>>d>>e>>f>>x;
    int p1=x/(a+c),q1=x%(a+c);
    int p2=x/(d+f),q2=x%(d+f);
    if(q1>=a){
        p1++;
        q1=0;
    }
    if(q2>=d){
        p2++;
        q2=0;
    }
    int lenT=(a*p1+q1)*b,lenA=(d*p2+q2)*e;
    if(lenT>lenA){
        cout<<"Takahashi"<<endl;
    }else if(lenT<lenA){
        cout<<"Aoki"<<endl;
    }else{
        cout<<"Draw"<<endl;
    }
    return 0;
}
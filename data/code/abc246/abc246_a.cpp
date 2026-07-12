#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> x(3),y(3);
    map<int,int> mpX,mpY;
    for(int i=0;i<3;i++){
        cin>>x[i]>>y[i];
        mpX[x[i]]++;
        mpY[y[i]]++;
    }
    int ansX,ansY;
    for(auto [X,cnt]:mpX){
        if(cnt==1){
            ansX=X;
        }
    }
    for(auto [Y,cnt]:mpY){
        if(cnt==1){
            ansY=Y;
        }
    }
    cout<<ansX<<" "<<ansY<<endl;
    return 0;
}
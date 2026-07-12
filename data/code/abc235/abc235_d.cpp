#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,n;cin>>a>>n;
    int ans=(int)1e9;
    map<int,int> xMap;
    auto rotateInt=[&](int x){
        string strX=to_string(x);
        string newX;
        int m=strX.size();
        int i=m-1;
        for(int j=0;j<m;j++){
            newX+=strX[i];
            i++;
            i%=m;
        }
        int res=stoi(newX);
        return res;
    };
    auto keta=[&](int x){
        int res=0;
        while(x>0){
            res++;
            x/=10;
        }
        return res;
    };
    auto dfs=[&](auto dfs,int x,int count)->void{
        xMap[x]=count;
        if(x==n){
            ans=count;
            return;
        }
        if(keta(x)>=7){
            return;
        }
        if(x%10!=0){
            int rotatedX=rotateInt(x);
            if(!xMap.count(rotatedX)||(xMap.count(rotatedX)&&xMap[rotatedX]>count+1)){
                dfs(dfs,rotatedX,count+1);
            }
        }
        if(!xMap.count(a*x)||(xMap.count(a*x)&&xMap[a*x]>count+1)){
            dfs(dfs,a*x,count+1);
        }
    };
    dfs(dfs,1,0);
    if(ans!=(int)1e9){
        cout<<ans<<endl;
    }else{
        cout<<-1<<endl;
    }
    return 0;
}
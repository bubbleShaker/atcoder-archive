#include <bits/stdc++.h>
using namespace std;
int main(){
  long long a,b,c,d;
  cin>>a>>b>>c>>d;
  
  //各パーツの面積の2倍
  map<long long,long long> allKiyo;
  allKiyo[0]=3;
  allKiyo[1]=3;
  allKiyo[2]=1;
  allKiyo[3]=1;
  
  //各パーツ上半分の面積の2倍
  map<long long,long long> ueKiyo;
  ueKiyo[0]=1;
  ueKiyo[1]=2;
  ueKiyo[2]=1;
  ueKiyo[3]=0;
  
  //各パーツ下半分の面積の2倍
  map<long long,long long> sitaKiyo;
  sitaKiyo[0]=2;
  sitaKiyo[1]=1;
  sitaKiyo[2]=0;
  sitaKiyo[3]=1;
  
  long long tateLength=d-b;
  long long yokoLength=c-a;
  long long tateCnt=tateLength/2;
  long long yokoCnt=yokoLength/4;
  long long ans=0;
  
  //2*4で繰り返される部分の寄与
  ans+=tateCnt*yokoCnt*4*2;//最後に2倍
  
  //横にはみ出た部分の寄与
  if(a<0){
    a=-a;
    a%=4;
    a=(4-a);
  }else{
    a%=4;
  }
  long long yokoAmari=yokoLength%4;
  for(int i=a;i<(a+yokoAmari);i++){
    ans+=tateCnt*allKiyo[i%4];//MODを取る
  }
  
  //縦にはみ出た部分の寄与
  if(b<0){
    b=-b;
  }
  b%=2;
  if(tateLength%2){//縦に余りが発生しているかどうか
    ans+=yokoCnt*4;//縦の長さ1、横の長さ4ならば、
    //パーツの面積の2倍はどの場合も4
  }
  
  //右下にはみ出た部分の寄与
  if(tateLength%2){//縦に余りが発生しているかどうか
    if(b==0){
      for(int i=a;i<(a+yokoAmari);i++){
        ans+=sitaKiyo[i%4];
      }
    }else{
      for(int i=a;i<(a+yokoAmari);i++){
        ans+=ueKiyo[i%4];
      }
    }
  }
  
  cout<<ans<<endl;
  
  return 0;
}
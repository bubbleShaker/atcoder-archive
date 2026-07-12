#include <bits/stdc++.h>
using namespace std;

int main(){
  double Deg,Dis;
  cin>>Deg>>Dis;
  int num;
  if(Deg<112.5||3487.5<=Deg){
    num=0;
  }else{
    num=ceil((Deg-112.5)/225.0);
  }
  map<int,string> num_houi;
  num_houi[0]="N";
  num_houi[1]="NNE";
  num_houi[2]="NE";
  num_houi[3]="ENE";
  num_houi[4]="E";
  num_houi[5]="ESE";
  num_houi[6]="SE";
  num_houi[7]="SSE";
  num_houi[8]="S";
  num_houi[9]="SSW";
  num_houi[10]="SW";
  num_houi[11]="WSW";
  num_houi[12]="W";
  num_houi[13]="WNW";
  num_houi[14]="NW";
  num_houi[15]="NNW";
  
  double husoku=(Dis*10)/60;
  // cout<<husoku<<endl;
  husoku=round(husoku);
  husoku/=10;
  // cout<<husoku<<endl;
  int huryoku;
  if(0.0<=husoku&&husoku<=0.2)huryoku=0;
  if(0.3<=husoku&&husoku<=1.5)huryoku=1;
  if(1.6<=husoku&&husoku<=3.3)huryoku=2;
  if(3.4<=husoku&&husoku<=5.4)huryoku=3;
  if(5.5<=husoku&&husoku<=7.9)huryoku=4;
  if(8.0<=husoku&&husoku<=10.7)huryoku=5;
  if(10.8<=husoku&&husoku<=13.8)huryoku=6;
  if(13.9<=husoku&&husoku<=17.1)huryoku=7;
  if(17.2<=husoku&&husoku<=20.7)huryoku=8;
  if(20.8<=husoku&&husoku<=24.4)huryoku=9;
  if(24.5<=husoku&&husoku<=28.4)huryoku=10;
  if(28.5<=husoku&&husoku<=32.6)huryoku=11;
  if(32.7<=husoku)huryoku=12;
  
  if(huryoku==0){
    cout<<"C 0"<<endl;
  }else{
    cout<<num_houi[num]<<" "<<huryoku<<endl;
  }
  return 0;
}
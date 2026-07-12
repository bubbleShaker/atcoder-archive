#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    auto f=[&](double mid){
        return mid*mid*mid+mid;
    };
    double left=0,right=100;
    while(right-left>0.000001){
        double mid=(left+right)/2;
        if(f(mid)>=n){
            right=mid;
        }else{
            left=mid;
        }
    }
    cout<<setprecision(10);
    cout<<right<<endl;
    return 0;
}
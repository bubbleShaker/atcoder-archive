#include <bits/stdc++.h>
using namespace std;

int main(){
    double h,bmi;
    cin>>h>>bmi;
    h/=100;
    cout<<fixed<<setprecision(10);
    cout<<bmi*h*h<<endl;
    return 0;
}
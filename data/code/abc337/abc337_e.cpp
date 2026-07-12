#include <bits/stdc++.h>
using namespace std;

int n;
int m;
string s;
vector<set<int>> personSet;
vector<set<int>> wineSet;

int searchM(int n){
    int res=0;
    int val=1;
    while(val<n){
        val*=2;
        res++;
    }
    return res;
}

set<int> searchBit(int n){
    set<int> resSet;
    int ind=1;
    while(n>0){
        if(n%2==1){
            resSet.insert(ind);
        }
        n/=2;
        ind++;
    }
    return resSet;
}

int toInt(string s){
    int res=0;
    int addVal=1;
    int k=s.size();
    for(int i=0;i<k;i++){
        int val=s[i]-'0';
        if(val==1){
            res+=addVal;
        }
        addVal*=2;
    }
    return res;
}

int main(){
    cin>>n;
    m=searchM(n);
    personSet.resize(n);
    wineSet.resize(m+1);
    for(int i=0;i<n;i++){
        personSet[i]=searchBit(i);
    }
    for(int wine=0;wine<n;wine++){
        for(int person:personSet[wine]){
            wineSet[person].insert(wine);
        }
    }
    cout<<m<<endl;
    for(int person=1;person<=m;person++){
        int k=wineSet[person].size();
        int ind=0;
        cout<<k<<" ";
        for(int wine:wineSet[person]){
            cout<<wine+1<<" \n"[ind+1==k];
            ind++;
        }
    }
    cin>>s;
    cout<<toInt(s)+1<<endl;
    return 0;
}
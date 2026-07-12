#include <bits/stdc++.h>
using namespace std;
int main(){
    int r,c;cin>>r>>c;r--;c--;
    vector<string> grid={
        "ooooooooooooooo",
        "oxxxxxxxxxxxxxo",
        "oxoooooooooooxo",
        "oxoxxxxxxxxxoxo",
        "oxoxoooooooxoxo",
        "oxoxoxxxxxoxoxo",
        "oxoxoxoooxoxoxo",
        "oxoxoxoxoxoxoxo",
        "oxoxoxoooxoxoxo",
        "oxoxoxxxxxoxoxo",
        "oxoxoooooooxoxo",
        "oxoxxxxxxxxxoxo",
        "oxoooooooooooxo",
        "oxxxxxxxxxxxxxo",
        "ooooooooooooooo"
    };
    if(grid[r][c]=='o'){
        cout<<"black"<<endl;
    }else{
        cout<<"white"<<endl;
    }
    return 0;
}
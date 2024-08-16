#include <bits/stdc++.h>
using namespace std;
#define ll long long

int H, W, idx=1;
vector<string> Tree;

ll solve(int y, int x){
    if('0'<=Tree[y][x] && Tree[y][x]<='9') return (ll)(Tree[y][x]-'0');
    int right, left;
    for(int nx=x-1;nx>=0;nx--)
        if(Tree[y+1][nx]!='.')
            {left = nx; break;}
    for(int nx=x+1;nx<Tree[y].size();nx++)
        if(Tree[y+1][nx]!='.')
            {right = nx; break;}
    if(Tree[y][x]=='+') return solve(y+1,left)+solve(y+1,right);
    if(Tree[y][x]=='-') return solve(y+1,left)-solve(y+1,right);
    if(Tree[y][x]=='*') return solve(y+1,left)*solve(y+1,right);
}

int main(){
    cin>>H>>W;
    for(int i=0;i<H;i++){
        string x; cin>>x;
        Tree.push_back(x);
    }
    for(int i=0;i<Tree[0].size();i++){
        if(Tree[0][i]!='.'){
            cout<<solve(0,i);
            break;
        }
    }
    return 0;
}

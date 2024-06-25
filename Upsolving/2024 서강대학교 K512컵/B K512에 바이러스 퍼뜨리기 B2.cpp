//간단한 쿼리를 구현하는 문제입니다.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> Pll;
#define X first
#define Y second

ll N,Q;
ll cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>N>>Q;
    vector<bool> arr(N+1,false); //감염(true) 치유됨(false)
    cnt=N;
    while(Q--){
        int x; cin>>x;
        if(x==3) cout<<cnt<<'\n';
        if(x==1){
            int y; cin>>y;
            if(!arr[y]) {arr[y]=true; cnt--;}
        }
        if(x==2){
            int y; cin>>y;
            if(arr[y]) {arr[y]=false; cnt++;}
        }       
    }
    return 0;
}

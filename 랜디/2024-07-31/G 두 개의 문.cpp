//https://wasd222.blogspot.com/2020/03/17453.html
//Map을 쓰면 시간초과가 나므로 year에 100을 더해 인덱스를 0보다 크거나 같게 맞춰줍니다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N, M;
string S;
bitset<101> door;
bitset<101> sw[23];
bool vis[1101010];
vector<vector<int>> Mp(300);

//현재 문 상태, 탐색깊이, 누른 스위치들 (누르면 1, int형으로 저장)
void Brute(bitset<101> cur, int depth, int swBit){
    if(depth>M) return;
    if(vis[swBit]) return;
    vis[swBit] = true;
    for(int i=0; i<M; i++){
        int bit = 1<<i;
        Brute(cur ^ sw[i], depth+1, swBit | bit);
    }
    int year = 100 - N + cur.count()*2;
    Mp[year].push_back(depth);
    Mp[year].push_back(swBit);
}

int main(){
    fastio;
    cin>>N>>M>>S;

    //String으로 입력된 문 초기 상태를 bitset으로 변환
    for(int i=0;i<S.size();i++){
        if(S[i]=='1') door.set(100-i, true);
    }

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            char x; cin>>x;
            if(x=='1') sw[i].set(100-j, true);
        }
    }

    Brute(door, 0, 0);

    for(int i=-1*N + 100; i<=N+100; i++){
        if(Mp[i].empty()) {cout<<-1<<'\n'; continue;}
        cout<<Mp[i][0]<<' ';
        int num = Mp[i][1];
        int idx = 1;
        while(num>0){
            if(num&1) cout<<idx<<' ';
            num >>= 1;
            idx++;
        }
        cout<<'\n';
    }
    return 0;
}

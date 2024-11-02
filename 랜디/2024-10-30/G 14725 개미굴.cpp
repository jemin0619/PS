//트라이 문제가 처음이라 해당 풀이를 참고했습니다.
//https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x1F/solutions/14725.cpp

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N;
map<string, int> nxt[15003];
int unused = 2;

void insert(vector<string>&V){
    int cur = 1;
    for(auto S : V){
        if(!nxt[cur][S]) nxt[cur][S] = unused++;
        cur = nxt[cur][S]; //cout<<cur<<' ';
    }
}

void DFS(int cur, int depth){
    for(auto next : nxt[cur]){
        for(int i=0; i<2*depth; i++) cout<<"-";
        cout<<next.first<<'\n';
        DFS(next.second, depth+1);
    }
}

int main(){
    fastio;
    cin>>N;
    for(int i=0; i<N; i++){
        int M; cin>>M;
        vector<string> V(M);
        for(int i=0; i<M; i++) cin>>V[i];
        insert(V);
        //cout<<"삽입이 끝났습니다\n";
    }
    DFS(1, 0);
    return 0;
}

//Stack을 RL로 Monotone하게 유지시키면서 처리했다.

//로봇에 가상의 지점 0에서 시작한다고 생각하면 문자열 앞에 R을 붙여서 생각할 수 있다.
//Ls는 S = RRLLLLLRR일 때 LLLLL을 의미한다.
//일단 S = RRLs일때 R RLs로 나눠볼 수 있다.
//순서가 가장 빠른 답을 출력해야 하기에 뒤에 단일 R은 idx를 1씩 더해가고, RLs인 경우엔 오른쪽으로 쭉 갔다가 R+1로 돌아가야 한다.
//단일 R은 idx+1을, RLs는 마지막 L부터 역순으로 idx를 매기는게 최적해다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);

int N,idx;
string S;
vector<int> ans;
stack<pair<char,int>> St;

int main(){
    fastio;
    cin>>N>>S;
    S = "R"+S;
    ans.resize(N+1);
    for(int i=0;i<N;i++){
        if(S[i]=='R'){
            while(!St.empty()){
                auto cur = St.top(); St.pop();
                ans[cur.second] = ++idx;
            }
        }
        St.push({S[i],i});
    }
    while(!St.empty()){
        auto cur = St.top(); St.pop();
        ans[cur.second] = ++idx;
    }
    for(int i=0;i<N;i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}

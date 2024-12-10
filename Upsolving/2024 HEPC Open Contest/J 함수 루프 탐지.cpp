//https://github.com/dlalsrn/Baekjoon/blob/main/백준/Gold/31875. 함수 루프 탐지/함수 루프 탐지.cc

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

void solve(){
    int N; cin>>N;
    map<string, int> P;
    int mx_cnt=1, cnt=1;
    vector<string> A(N+1), ans, pre;
    for(int i=1; i<=N; i++) cin>>A[i];
    
    for(int i=1; i<=N; i++){
        if(P.find(A[i])==P.end()) {P[A[i]] = i; continue;}
        int diff = i - P[A[i]];
        bool check = true;
        int jump = 0;
        for(int j=0; j<diff; j++){
            if(i+j>N) {check=false; break;} //OOB
            if((i+j)-P[A[i+j]] != diff) {check=false; break;} //루프가 아닌 것이 판별됨
            jump++;
            P[A[i+j]] = i+j;
        }
        if(check){
            vector<string> tmp(diff);
            for(int j=0; j<diff; j++) tmp[j] = A[i+j]; //루프 구간 추출
            if((int)pre.size()>0 && pre==tmp){ //이전 루프와 같은 루프이면
                cnt++;
                if(mx_cnt<cnt){
                    ans = tmp;
                    mx_cnt = cnt;
                }
            }
            else{ //이전의 루프와 다른 루프이면
                cnt = 2;
                if(mx_cnt<cnt){
                    ans = tmp;
                    mx_cnt = cnt;
                }
            }
            pre = tmp;
        }
        else pre.clear();
        i += jump-1; //탐색한 부분까지 i를 이동시킴
    }

    if(mx_cnt==1) {cout<<-1; return;}
    cout<<(int)ans.size()<<' '<<mx_cnt<<'\n';
    for(int i=0; i<(int)ans.size(); i++) cout<<ans[i]<<' ';
}

int main(){
    fastio;
    solve();
    return 0;
}

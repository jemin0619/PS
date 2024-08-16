//그리디 + 많조분 + 시뮬레이션인데 너무 힘들었다.
//레이저로 나올 수 있는 6가지 경우를 모두 생각해 코드를 제출했는데 85%에서 계속 실패해서 코드를 새로 짰다.

//로봇은 레이저를 무시하고 쫓아오기에 0,0에서 Flood Fill을 하며 온다고 생각할 수 있다.
//그렇기에 플레이어가 한 번이라도 x나 y좌표가 감소하는 방향으로 이동한다면 로봇에게 잡힌다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define st first 
#define en second 

ll N,M;
ll Px=1; //플레이어의 x좌표

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N-1;i++){
        int x; cin>>x;
        char c,d; ll a,b;
        vector<pair<int,int>> V; //레이저의 시작과 끝 저장
        if(x==0) continue;
        if(x==1){
            cin>>a>>c;
            if(c=='R') V.push_back({a,M}); //Case 1
            if(c=='L') V.push_back({1,a}); //Case 2
        }
        if(x==2){
            cin>>a>>c>>b>>d;
            if(c=='R' && d=='L') V.push_back({a,b}); //Case 3
            if(c=='R' && d=='R') V.push_back({a,M}); //Case 5
            if(c=='L' && d=='L') V.push_back({1,b}); //Case 6
            if(c=='L' && d=='R'){ //Case 4
                V.push_back({1,a});
                V.push_back({b,M});
            }
        }

        if(V.size()==1){ //Case 12356
            if(Px<V[0].st || V[0].en<Px) continue; //레이저 밖의 영역으로 바로 내려가는 경우
            else if(V[0].st<=Px && Px<=V[0].en && V[0].en+1<=M) {Px=V[0].en+1; continue;} //레이저 위에 있고 오른쪽에 길이 있는 경우
            else {cout<<"NO"; return 0;} //그 밖엔 길이 없음
        }
        else if(V.size()==2){ //Case 4
            if(V[0].en<Px && Px<V[1].st) continue; //두 레이저 사이로 바로 내려가는 경우
            else if(Px<=V[0].en && V[0].en+1<V[1].st) {Px=V[0].en+1; continue;}
            else {cout<<"NO"; return 0;} //그 밖엔 길이 없음
        }
    }
    cout<<"YES";
    return 0;
}

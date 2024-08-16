//https://koosaga.com/64
//https://blog.myungwoo.kr/91

//라운드 수가 증가함에 따라 정렬이 무조건 가능하므로 parametric search로 접근해야 한다.
//시작부터 배열이 정렬되어있는 경우, 에르맥이 swap하니 정렬된 경우에 예외처리를 해줘야 한다.
//R라운드만에 정렬이 가능한지 판별하기 위해 정렬된 배열을 만들어두고, 쿼리를 역순으로 시행하며 배열을 R라운드 전의 상태로 구성한다.
//기존 배열 S와 R라운드 전의 상태로 구성된 배열 X가 있을 때, 두 배열을 1 ~ R라운드까지 swap을 진행시키고, 에르맥이 swap한 후 두 배열의 상태를 보고 S와 R이 같아질 수 있게 swap시켜준다.
//S가 X를 따라가야 정렬되기 때문이다.

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ff first
#define ss second
#define vi vector<int>
#define vpii vector<pii>

int N, M;
vi _S;
vpii Q;
vpii Ans;

bool check(int mid){
    vi goal(N), goal_Pos(N);
    vi S(_S), S_Pos(N);
    for(int i=0; i<N; i++) goal[i]=i; //정렬된 배열 생성

    for(int i=mid-1; i>=0; i--){ //에르맥이 m번 swap했을 때 정렬된 배열이 나오는 배열을 goal에 저장
        swap(goal[Q[i].ff], goal[Q[i].ss]);
    }

    for(int i=0; i<N; i++){ //goal과 S 배열에서 각 수의 위치 저장
        S_Pos[S[i]] = i;
        goal_Pos[goal[i]] = i;
    }

    int to_sort_num = 0; //정렬해야 할 숫자

    for(int i=0; i<mid; i++){
        //에르맥이 먼저 두 수를 swap함
        swap(goal[Q[i].ff], goal[Q[i].ss]);
        swap(S[Q[i].ff], S[Q[i].ss]);

        //Position도 swap (swap되었으므로 ff면 ff, ss면 ss)
        goal_Pos[goal[Q[i].ff]] = Q[i].ff;
        goal_Pos[goal[Q[i].ss]] = Q[i].ss;
        S_Pos[S[Q[i].ff]] = Q[i].ff;
        S_Pos[S[Q[i].ss]] = Q[i].ss;

        //0 ~ N-1까지 돌면서 정렬이 안된 숫자를 찾음
        while(to_sort_num<N && goal_Pos[to_sort_num]==S_Pos[to_sort_num]) to_sort_num++;

        //에르맥이 swap하니 정렬되어있을 경우, 아이잔은 아무 같은 수를 swap하고 게임을 종료시킴
        if(to_sort_num==N){
            Ans[i] = {0,0};
            return true; 
        }

        //배열 S가 goal과 같아져야 mid 라운드 이내에 정렬시킬 수 있음
        int pos1 = goal_Pos[to_sort_num];
        int pos2 = S_Pos[to_sort_num];    
        swap(S[pos1], S[pos2]);
        S_Pos[S[pos1]] = pos1;
        S_Pos[S[pos2]] = pos2;

        //P, Q에 기록
        Ans[i] = {pos1, pos2};
    }
    while(to_sort_num<N && goal_Pos[to_sort_num]==S_Pos[to_sort_num]) to_sort_num++;
    if(to_sort_num==N) return true; 
    else return false;
}

int solve(){
    //시작부터 정렬되어있으면 0 반환
    int sortedCnt = 0;
    while(sortedCnt<N && sortedCnt==_S[sortedCnt]) sortedCnt++;
    if(sortedCnt==N) return 0;

    int st=0, en=N;
    while(st+1<en){
        int mid = (st+en)/2;
        if(check(mid)) en=mid;
        else st=mid;
    }
    check(en);
    return en;
}

int main(){
    fastio;
    cin>>N; _S.resize(N);
    for(int i=0; i<N; i++) cin>>_S[i];

    cin>>M; Q.resize(M); Ans.resize(M);
    for(int i=0; i<M; i++) cin>>Q[i].ff>>Q[i].ss;

    int R = solve();
    cout<<R<<'\n';
    for(int i=0; i<R; i++){
        cout<<Ans[i].ff<<' '<<Ans[i].ss<<'\n';
    }
    return 0;
}

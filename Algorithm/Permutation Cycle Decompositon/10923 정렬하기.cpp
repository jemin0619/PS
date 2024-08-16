//순열 사이클 분할보다는 그리디 + 해 구성하기 문제라고 느껴졌다.
//아마 매개변수탐색을 써야 하는 정렬하기 2가 순열 사이클 분할을 써야하는 것 같다.

//최적의 해를 구하지 않아도 되므로 연산 중 정렬이 끝났어도 {0,0} 을 대입해주었다.
//함수 구현 문제인줄 알았는데 아니었다.

//에르맥은 수열을 주어진 순서대로 swap하고, 아이잔은 수열을 정렬되게 swap시키려고 한다.
//일단 swap을 [아이잔이 swap하기로 결정된 순서쌍의 갯수]+1번 시행해준다. (에르맥이 swap을 마치고 아이잔의 swap을 기다리는 상태가 됨)
//그 상태에서 각 수의 위치를 배열에 저장시킨다.
//에르맥이 모든 swap을 마칠 때까지 기다리고 마지막 결과를 확인한다.
//결과를 확인했는데, 배열 S의 i번째 인덱스에 있는 값이 i가 아닐 경우, stPos[S[i]]와 stPos[i]를 교환해야 한다.
//이것이 바로 x번째에 교환해야 할 두 수의 인덱스이다.
//이 수들을 Ans에 넣고, 만약 모든 수가 정렬되어있을 경우엔 0,0을 넣어준다.
//코드를 보면 이해가 잘 될 것이다.

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ff first
#define ss second
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N; cin>>N;
    vector<int> V(N);
    for(int i=0;i<N;i++) cin>>V[i];

    int M; cin>>M;
    vector<pii> Query(M);
    vector<pii> Ans(M, {-1,-1});
    for(int i=0;i<M;i++) cin>>Query[i].ff>>Query[i].ss;
    
    for(int i=0;i<M;i++){
        vector<int> S(V); //기존 수열을 복사해옴
        
        //i번 쿼리까지만 수행
        for(int j=0;j<=i;j++){
            swap(S[Query[j].ff], S[Query[j].ss]);
            if(Ans[j].ff == -1 && Ans[j].ss == -1) continue;
            swap(S[Ans[j].ff], S[Ans[j].ss]);
        }

        //i번 쿼리까지 수행한 상태에서 각 수의 위치 저장
        //stPos[num]: S에서 num의 idx
        vector<int> stPos(N);
        for(int j=0;j<N;j++){
            stPos[S[j]] = j;
        }

        //나머지 쿼리를 수행
        for(int j=i+1;j<M;j++){
            swap(S[Query[j].ff], S[Query[j].ss]);
        }
        
        bool changed = false;
        
        for(int j=0;j<N;j++){
            if(S[j]!=j){
                Ans[i].ff = stPos[S[j]];
                Ans[i].ss = stPos[j];
                changed = true;
            }
        }

        if(!changed){
            Ans[i].ff = 0;
            Ans[i].ss = 0;
        }
    }
    
    cout<<Ans.size()<<'\n';
    for(int i=0;i<M;i++) cout<<Ans[i].ff<<' '<<Ans[i].ss<<'\n';

    return 0;
}

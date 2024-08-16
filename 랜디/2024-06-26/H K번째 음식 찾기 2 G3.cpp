//https://pill27211.tistory.com/115
//위 글에서 도움을 받았다.

//Parametric Search + Binary Search 문제이다.
//Func(vector<int>&V, X) : 배열 V에서 X번째 요소가 답이 될 수 있는가?

//추가로 쿼리에서의 입력은 1-indexed이므로 범위 설정에 주의한다.
//Func == true인 상황은 {X + V이외의 배열에서 V[X]보다 작은 원소의 개수}가 K인 경우이다.
//이때 X는 0-indexed이고 K은 1-indexed이므로 X+1을 해주었다.

//Binary Search가 끝난 이후의 lo엔 cnt<=K 일 때의 인덱스가 들어가 있으므로 X에 lo를 대입했을 때 true인지 확인한다.
//true라면 type과 lo+1을 출력하고 false라면 V를 다른 배열로 바꿔서 탐색을 시작한다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N,Q;
vector<int> V[3];

bool solve(vector<int>&X, vector<int>&Y, vector<int>&Z, int type, int k, int x, int y, int z){
    int lo = -1, hi = x;
    while(lo+1<hi){
        int mid = (lo+hi)/2;
        int cnt = mid+1;
        cnt += lower_bound(Y.begin(),Y.begin()+y,X[mid]) - Y.begin();
        cnt += lower_bound(Z.begin(),Z.begin()+z,X[mid]) - Z.begin();
        if(cnt>k) hi = mid;
        else lo = mid;
    }

    bool flag = (k == lo+1+lower_bound(Y.begin(),Y.begin()+y,X[lo])-Y.begin()+lower_bound(Z.begin(),Z.begin()+z,X[lo])-Z.begin()); 

    if(flag){
        cout<<type<<' '<<lo+1<<'\n';
        return true;
    }

    return false;
}

int main(){
    fastio;
    cin>>N;

    for(int i=0;i<3;i++){
        for(int j=0;j<N;j++){
            int x; cin>>x;
            V[i].push_back(x);
        }
    }

    cin>>Q;
    while(Q--){
        int x,y,z,k; cin>>x>>y>>z>>k;
        if(solve(V[0],V[1],V[2],1,k,x,y,z));
        else if(solve(V[1],V[0],V[2],2,k,y,x,z));
        else solve(V[2],V[0],V[1],3,k,z,x,y);
    }
    return 0;
}

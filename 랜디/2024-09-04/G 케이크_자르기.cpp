#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N,M,L; //자르는횟수, 지점개수, 롤케이크길이
vector<int> V;
int x;

//가장 작은 조각의 길이가 x보다 크거나 같게 N번 이상 자를 수 있는가?
bool check(int mid){
    int cnt = 0;
    int pre = V[0];
    for(int i=1; i<=M; i++){
        if(V[i]-pre>=mid){
            pre=V[i];
            cnt++;
        }
    }
    //마지막 부분을 잘라야만 하는데, 그렇게 되어서 길이가 x미만인 조각이 나오면 false
    if(L-pre < mid && cnt==x) return false;
    return cnt>=x;
}

int main(){
    fastio;
    cin>>N>>M>>L;
    V.resize(M+3);
    V[0] = 0;
    for(int i=1; i<=M; i++) cin>>V[i];
    while(N--){
        cin>>x;
        int lo=-1; int hi=400'0003;
        while(lo+1<hi){
            int mid = (lo+hi)/2;
            if(check(mid)) lo=mid;
            else hi=mid;
        }
        cout<<lo<<'\n';
    }
    return 0;
}

//태그는 DP인데 저걸 DP라고 해버리면 대부분의 구현 문제도 DP가 되버린다...
//그냥 점프 없이 이동할 수 있는 블럭끼리 묶어서 그 길이를 벡터에 저장했다.
//그 후 벡터를 돌면서 case work로 ans를 갱신하면서 풀었다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int N, M; cin>>N>>M;
    vector<int> V(N);
    for(int i=0; i<N; i++) cin>>V[i];
    vector<int> arr;
    for(int i=0; i<N-1; i++){
        if(V[i]<=M){
            if(!arr.empty() && arr.back()!=-1) arr.back()++;
            else arr.push_back(1);
        }
        else arr.push_back(-1);
    }

    //X -1 Y : X+1 + Y+1
    //X -1 : X+1 + 1
    //-1 X : X+1 + 1
    //X : X+1
    int ans = 1;
    for(int i=0; i<arr.size(); i++){
        if(i>=2 && arr[i]!=-1 && arr[i-1]==-1 && arr[i-2]!=-1) ans = max(ans, arr[i]+arr[i-2]+2);
        if(i>=1 && arr[i]==-1 && arr[i-1]!=-1) ans = max(ans, arr[i-1]+2);
        if(i>=1 && arr[i]!=-1 && arr[i-1]==-1) ans = max(ans, arr[i]+2);
        if(arr[i]!=-1) ans = max(ans, arr[i]+1);
    }
    cout<<ans;
    return 0;
}

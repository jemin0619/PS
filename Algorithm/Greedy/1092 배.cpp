//한 달 전에 Priority Queue로 풀었는데 알고리즘상 다시 삽입하는 과정이 있어 TLE가 발생했었다.
//이번엔 각 크레인이 처리할 수 있는 박스들을 각각 보관해서 O(NM)에 처리해보려고 한다.
//문득 풀이가 떠올라서 시도해봤는데 AC를 받았다.

//---풀이
//가장 무거운 크레인부터 무거운 박스를 배정해주고, 이를 반복해주면 된다. (그리디)

//---구현
//크레인은 들 수 있는 무게에 따라 내림차순으로 정렬해준다.
//무거운 박스를 들 수 있는 크레인부터 물건을 들어주어야 그리디 풀이가 성립하기 때문이다.
//박스는 오름차순으로 정렬해준다. 벡터를 써서 그런데, 덱을 쓰면 내림차순으로 해도 된다.
//시간복잡도는 정렬 과정을 제외하면 O(NM)이 된다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define xx first 
#define yy second

int main(){
    fastio;
    int N; cin>>N;
    vector<int> Crane(N);
    vector<vector<pair<int,int>>> Box(N);

    for(int i=0; i<N; i++) cin>>Crane[i];
    sort(Crane.rbegin(), Crane.rend());

    int mxVal = -1;
    int M; cin>>M;
    for(int i=0; i<M; i++){
        int x; cin>>x;
        mxVal = max(mxVal, x);
        for(int j=0; j<N; j++) {if(Crane[j]>=x) Box[j].push_back({x, i});}
    }

    //크레인으로 들 수 없는 박스가 있다면 -1을 출력
    if(Crane[0]<mxVal) {cout<<-1; return 0;}

    for(int i=0; i<N; i++){
        sort(Box[i].begin(), Box[i].end());
    }

    vector<bool> isused(M, false);
    int ans = 0;
    while(true){
        int flag = 0;
        for(int i=0; i<N; i++){
            while(!Box[i].empty() && isused[Box[i].back().yy]) Box[i].pop_back();
            if(Box[i].empty()) continue;
            isused[Box[i].back().yy] = true;
            Box[i].pop_back();
            flag++;
        }
        if(flag==0) break;
        ans++;
    }
    cout<<ans;
    return 0;
}

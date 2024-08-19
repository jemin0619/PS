#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ff first 
#define ss second

int main(){
    fastio;
    int N; cin>>N;
    vector<int> V1(N);
    for(int i=0; i<N; i++) cin>>V1[i];

    vector<int> sorted(V1);
    sort(sorted.begin(), sorted.end());

    vector<int> V2(V1);
    reverse(V2.begin(), V2.end());

    int ans1 = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N-1; j++){
            if(V1[j]>V1[j+1]) {swap(V1[j+1], V1[j]); ans1++;}
            if(V1 == sorted) break;
        }
    }

    int ans2 = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N-1; j++){
            if(V2[j]>V2[j+1]) {swap(V2[j+1], V2[j]); ans2++;}
            if(V2 == sorted) break;
        }
    }

    cout<<min(ans1, ans2+1);
    return 0;   
}

/*
인접한 두 원소끼리의 교환이므로 순열 사이클 분할로 해결할 수 없음. 
(순열 사이클 분할은 임의의 두 원소 교환)

이걸 순간 햇갈려서 뻘짓함
*/

//01:00 AC

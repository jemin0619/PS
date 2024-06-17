//1 <= {A[i], B[i], N} <= 100
//수가 다 작음.

//Aidx=0, Bidx=0
//A[Aidx:n]과 B[Bidx:m]에서 각각 1~100의 수가 언제 최초로 등장했는지를 배열에 저장합니다.
//최초로 등장한 위치를 저장하는 이유는 마지막 수열을 출력해야하기에 가장 긴 수열이 나와야 하므로 
//최대한 앞의 요소를 골라야 더 긴 수열이 만들어지기 때문입니다.

//100부터 1까지 for문을 순회하며 A와 B에서 해당 수가 등장했었다면 ans에 그 수를 추가하고 Aidx와 Bidx를 갱신하고 이를 반복합니다.

#include <bits/stdc++.h>
#define fastio cin.tie(NULL)->sync_with_stdio(false)
using namespace std;

vector<int> A, B, ans;
int Aidx, Bidx;

int main() {
    fastio;
    int n, m;
    cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        A.push_back(x);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int x; cin>>x;
        B.push_back(x);
    }

    while(Aidx<n && Bidx<m){
        vector<int> Achk(101,-1);
        vector<int> Bchk(101,-1);
        for(int i=Aidx;i<n;i++){
            if(Achk[A[i]]==-1) Achk[A[i]]=i;
        }
        for(int i=Bidx;i<m;i++){
            if(Bchk[B[i]]==-1) Bchk[B[i]]=i;
        }
        bool found = false;
        for(int i=100;i>=1;i--){
            if(Achk[i]==-1 || Bchk[i]==-1) continue;
            ans.push_back(i);
            Aidx = Achk[i]+1;
            Bidx = Bchk[i]+1;
            found = true;
            break;
        }
        if(!found) break;
    }

    cout<<ans.size()<<'\n';
    for(int val : ans) cout<<val<<' ';
    return 0;
}

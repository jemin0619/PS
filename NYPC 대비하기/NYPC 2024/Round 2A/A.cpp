//Tag: 많은 조건 분기, 그리디, 누적합
//00:30 WA
//00:35 AC

//문제 이해가 잘 안되서 시간을 좀 많이 썼다.
//+, 0, -순이므로 가능하면 +를 써주어야 한다.
//빚이라는 개념을 사용해서 접근하니 깔끔하게 풀렸다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

template <typename T>
struct SegTree{
    int N;
    vector<T> Tree;
    SegTree(int N):N(N){Tree.resize(N*4);}
    T merge(T left, T right){
        return left + right;
    }
    T update(int idx, T val, int node, int leftNode, int rightNode){
        if(idx<leftNode || rightNode<idx) return Tree[node];
        if(leftNode==rightNode) return Tree[node]=val;
        ll mid = (leftNode + rightNode) / 2;
        T leftVal = update(idx, val, node*2, leftNode, mid);
        T rightVal = update(idx, val, node*2+1, mid+1, rightNode);
        return Tree[node] = merge(leftVal, rightVal);
    }
    T query(int left, int right, int node, int leftNode, int rightNode){
        if(rightNode<left || right<leftNode) return 0;
        if(left<=leftNode && rightNode<=right) return Tree[node];
        ll mid = (leftNode + rightNode) / 2;
        T leftVal = query(left, right, node*2, leftNode, mid);
        T rightVal = query(left, right, node*2+1, mid+1, rightNode);
        return merge(leftVal, rightVal);
    }
};

int main(){
    fastio;
    int N; cin>>N;
    SegTree<ll> Seg(N);

    vector<ll> U(N), D(N);
    for(int i=0; i<N; i++) cin>>U[i];
    for(int i=0; i<N; i++){
        cin>>D[i];
        if(D[i]!=-1) Seg.update(i, D[i], 1, 0, N-1); 
    }

    vector<char> Ans(N);
    ll debt = 0;

    for(int i=0; i<N; i++){
        ll sum = Seg.query(i+1, N-1, 1, 0, N-1); 
        if(U[i]==-1 && D[i]==-1) {Ans[i] = '0'; continue;}
        if(U[i]!=-1){ //업그레이드 가능
            if(U[i]+debt<=sum){ //빚을 감당할 수 있는 경우
                Ans[i] = '+';
                debt += U[i];
            }
            else if(debt<=sum || D[i]==-1){ //팔지 않아도 빚 감당이 되는 경우
                Ans[i] = '0';
            }
            else{ //팔지 않았을 때 빚 감당이 안되는 경우
                Ans[i] = '-';
                debt -= D[i];
            }
        }
        else{ //업그레이드 불가능
            if(sum >= debt) Ans[i] = '0';
            else{
                Ans[i] = '-';
                debt -= D[i];
            }
        }
    }
    for(char c : Ans) cout<<c;
    return 0;
}

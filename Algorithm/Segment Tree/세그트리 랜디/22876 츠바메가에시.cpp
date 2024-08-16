//3 4번의 경우에서 업데이트가 시간초과를 낼 것 같았는데, 조금 생각해보면 절대 그럴 일이 없다는 것을 알 수 있다.
//최대 모든 점을 돌게 되므로 O(30만)이 되기 때문이다.
//(이것 때문에 다른 풀이와 힌트를 확인했는데 좀 아쉽다...)

//세 번의 참격을 해야 하므로 총 4개의 경우의 수가 나온다는 것을 알 수 있다.
//1. 가로로 세 번 참격
//2. 세로로 세 번 참격
//3. 가로로 한 번, 세로로 두 번 참격
//4. 세로로 한 번, 가로로 두 번 참격

//1의 경우는 가로를 담당하는 세그먼트 트리를 만들고, 그 중 가장 큰 세 값의 합을 답으로 취하면 된다.
//2의 경우도 마찬가지로 세로를 담당하는 세그먼트 트리로 해결한다.
//두 경우에서 두 번 이하의 참격으로 모든 제비를 베는 경우는 예외처리를 해줘야 한다.

//3의 경우는 겹치는 경우가 있을 수 있으므로 가로 참격을 고정시킨 채로, 세로 참격에서 가장 큰 두 값을 고르고 그 값들을 답으로 취해야 한다.
//이때 각 y축에 있는 x좌표의 위치와 값, 그리고 각 x축에 있는 y좌표의 위치와 값을 저장시켜놓고, 고정시킨 참격과 연관된 참격들을 업데이트한다.
//그 후 전체 범위에서 가장 큰 두 값을 가장 큰 값과 그 다음으로 큰 값을 저장하는 세그먼트 트리를 써서 답을 구한다.
//그 후 업데이트했던 값들을 되돌려놓는다.
//4도 마찬가지로 할 수 있다.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define tlll tuple<ll,ll,ll>
#define ff first 
#define ss second

int mxX, mxY;

struct SegTree{
    int N;
    vector<pll> Tree;
    SegTree(int N):N(N){Tree.resize(4*N);}
    pll merge(pll left, pll right){
        vector<ll> V = {left.ff, left.ss, right.ff, right.ss};
        sort(V.begin(), V.end());
        return {V[3], V[2]};
    }
    pll update(int idx, ll val, int node, int leftNode, int rightNode){
        if(idx<leftNode || rightNode<idx) return Tree[node];
        if(leftNode==rightNode) return Tree[node] = {Tree[node].ff+val, 0};
        ll mid = leftNode+rightNode; mid/=2;
        pll leftVal = update(idx, val, node*2, leftNode, mid);
        pll rightVal = update(idx, val, node*2+1, mid+1, rightNode);
        return Tree[node] = merge(leftVal, rightVal);
    }
    pll query(int left, int right, int node, int leftNode, int rightNode){
        if(rightNode<left || right<leftNode) return {0,0};
        if(left<=leftNode && rightNode<=right) return Tree[node];
        ll mid = leftNode+rightNode; mid/=2;
        pll leftVal = query(left, right, node*2, leftNode, mid);
        pll rightVal = query(left, right, node*2+1, mid+1, rightNode);
        return merge(leftVal, rightVal);
    }
};

void compress(vector<tlll>&V){
    vector<ll> X, Y;
    for(int i=0; i<V.size(); i++){
        auto&[a,b,c] = V[i];
        X.push_back(a);
        Y.push_back(b);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());
    for(auto&[a,b,c] : V){
        a = lower_bound(X.begin(), X.end(), a) - X.begin();
        b = lower_bound(Y.begin(), Y.end(), b) - Y.begin();
    }

    mxY = Y.size();
    mxX = X.size();
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int N; cin>>N;
    vector<tlll> V(N);
    for(int i=0; i<N; i++){
        ll a,b,c; cin>>a>>b>>c;
        V[i] = {a,b,c};
    }

    compress(V);

    SegTree SegY(mxY);
    SegTree SegX(mxX);

    vector<pll> fixedY[mxY+3]; //특정 y좌표에 있는 x값들
    vector<pll> fixedX[mxX+3]; //특정 x좌표에 있는 y값들

    for(auto&[x,y,w] : V){
        SegY.update(y, w, 1, 0, mxY-1);
        SegX.update(x, w, 1, 0, mxX-1);
        fixedY[y].push_back({x,w});
        fixedX[x].push_back({y,w});
    }
    
    ll Ans = 0;

    //세로축에 대해 참격 세 번
    vector<ll> tmp1; ll sum1 = 0;
    for(int i=0; i<mxX; i++){
        ll X = SegX.query(i, i, 1, 0, mxX-1).ff;
        tmp1.push_back(X);
    } sort(tmp1.begin(), tmp1.end(), greater<ll>());
    for(int i=0; i<min((int)tmp1.size(), 3); i++) sum1 += tmp1[i];
    Ans = max(Ans, sum1);
    
    //가로축에 대해 참격 세 번
    vector<ll> tmp2; ll sum2 = 0;
    for(int i=0; i<mxY; i++){
        ll X = SegY.query(i, i, 1, 0, mxY-1).ff;
        tmp2.push_back(X);
    } sort(tmp2.begin(), tmp2.end(), greater<ll>());
    for(int i=0; i<min((int)tmp2.size(), 3); i++) sum2 += tmp2[i];
    Ans = max(Ans, sum2);

    //세로축에 대해 참격 한 번, 가로축에 대해 참격 두 번
    for(int i=0; i<mxX; i++){
        ll X = SegX.query(i, i, 1, 0, mxX-1).ff;
        for(auto&[y, val] : fixedX[i]){
            SegY.update(y, -val, 1, 0, mxY-1);
        }

        pll MX = SegY.query(0, mxY-1, 1, 0, mxY-1);
        X += (MX.ff + MX.ss);
        Ans = max(Ans, X);

        for(auto&[y, val] : fixedX[i]){
            SegY.update(y, +val, 1, 0, mxY-1);
        }
    }

    //가로축에 대해 참격 한 번, 세로축에 대해 참격 두 번
    for(int i=0; i<mxY; i++){
        ll X = SegY.query(i, i, 1, 0, mxY-1).ff;
        for(auto&[x, val] : fixedY[i]){
            SegX.update(x, -val, 1, 0, mxX-1);
        }

        pll MX = SegX.query(0, mxX-1, 1, 0, mxX-1);
        X += (MX.ff + MX.ss);
        Ans = max(Ans, X);

        for(auto&[x, val] : fixedY[i]){
            SegX.update(x, +val, 1, 0, mxX-1);
        }
    }

    cout<<Ans;
    return 0;
}

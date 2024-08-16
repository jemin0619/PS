## Fenwick Tree
- [펜윅트리 1](https://ps.mjstudio.net/fenwick-tree)
- [펜윅트리 2](https://nahwasa.com/entry/%ED%8E%9C%EC%9C%85-%ED%8A%B8%EB%A6%ACFenwick-tree-BIT-%EA%B8%B0%EB%B3%B8-2D-lazy-propagationrange-update-point-query-range-update-range-query#%EC%9D%91%EC%9A%A9_3_:_%EA%B5%AC%EA%B0%84_%EC%97%85%EB%8D%B0%EC%9D%B4%ED%8A%B8,_%EA%B5%AC%EA%B0%84_%EA%B0%92_%ED%9A%8D%EB%93%9D)
- Binary Indexed Tree라고도 불립니다.
- update, range sum을 수행할 수 있으며 Segment Tree에 비해 공간복잡도가 작습니다.
- bit operation을 사용한다는 특징이 있습니다.

### 1차원 펜윅트리 구현체
``` cpp
//1-based indexing으로 해줘야 한다.
//sum은 -, add는 + 연산을 한다.
//add에서 기존 배열을 사용하기에 매번 갱신, 저장을 해줘야 한다. (세그먼트 트리와의 차이점)

template <typename T>
struct fenwick{
    int N;
    vector<T> Tree;
    fenwick(int N):N(N){Tree.resize(N+1);}
    void update(int i, T x){
        for(;i<=N;i+=i&-i) Tree[i] += x;
    }
    T sum(int i){
        T ret = 0;
        for(;i;i-=i&-i) ret += Tree[i];
        return ret;
    }
};
```

### [1차원 구간 업데이트, 점 쿼리](https://www.acmicpc.net/problem/16975)
``` cpp
//imos법을 사용해 Lazy Propagation 없이 구간 업데이트를 할 수 있다. (sum 쿼리 한정)

int main(){
    fastio;
    int N; cin>>N;
    vector<ll> V(N+1);
    fenwick<ll> fw(N);
    for(int i=1;i<=N;i++){
        cin>>V[i];
        fw.update(i, V[i]);
        fw.update(i+1, -V[i]);
    }
    int M; cin>>M;
    while(M--){
        int Q; cin>>Q;
        if(Q==1){
            int i,j; ll k;
            cin>>i>>j>>k;
            fw.update(i, k);
            fw.update(j+1,-k);
        }
        else{
            int i; cin>>i;
            cout<<fw.sum(i)<<'\n';
        }
    }
    return 0;
}
```

### 2차원 펜윅트리 구현체
``` cpp
//x를 복사해서 사용해야 한다.
//1차원과 마찬가지로 1-based indexing을 쓴다.

template <typename T>
struct fenwick2D{
    int Y, X;
    vector<vector<T>> Tree;
    fenwick2D(int Y, int X): Y(Y), X(X) {Tree.resize(Y+1, vector<T>(X+1));}
    void update(int _y, int _x, T val){
        for(int y=_y; y<=Y; y+=y&-y)
            for(int x=_x; x<=X; x+=x&-x)
                Tree[y][x] += val;
    }
    T sum(int _y, int _x){
        if(_y<=0 || _x<=0) return 0;
        T ret = 0;
        for(int y=_y; y; y-=y&-y)
            for(int x=_x; x; x-=x&-x)
                ret += Tree[y][x];
        return ret;
    }
    T query(int y1, int x1, int y2, int x2){
        return sum(y2, x2) - sum(y1-1, x2) - sum(y2, x1-1) + sum(y1-1, x1-1);
    }
};
```

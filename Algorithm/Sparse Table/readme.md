## Sparse Table (희소배열)

### [추천 글 1](https://ps.mjstudio.net/sparse-table)
### [추천 글 2](https://namnamseo.tistory.com/entry/Sparse-Table)
### [[Range Query] Sparse Table](https://youtu.be/toBt6dHcvdA?si=viwGMszQd7TzaW9U)
### [[Range Query] Disjoint Sparse Table](https://youtu.be/XyKRc71z9Pk?si=X4FyQPBmamqY84M6)

- Sparse Table은 구간이 겹쳐도 되는 연산은 O(1), 겹치면 안되는 연산은 O(log N)에 처리된다.
- Disjoint Sparse Table은 모든 연산을 O(1)에 해결할 수 있다.
- 그치만 Segment Tree로 다 해결되기에 굳이 사용할 일은 많지 않다.
- Range Query보다는 LCA 등을 구할 때 쓰이는 것 같다.

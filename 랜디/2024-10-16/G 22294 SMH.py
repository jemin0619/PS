# 문제가 언어 제한 + 함수구현이라 하기 싫었지만 도전했다.
# 처음엔 기울기만으로 될 것 같았는데 그냥 확실하게 선분교차로 풀었다.
# 정해는 CCW였던 것 같다.

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def __le__(self, P):
        if self.x == P.x: return self.y <= P.y
        return self.x <= P.x

class Line:
    def __init__(self, P1, P2):
        self.P1 = P1
        self.P2 = P2

def CCW(P1, P2, P3):
    ret = P1.x*P2.y + P2.x*P3.y + P3.x*P1.y - P1.y*P2.x - P2.y*P3.x - P3.y*P1.x
    if ret>0: return 1
    elif ret<0: return -1
    else: return 0

def cross(L1, L2):
    D1 = CCW(L1.P1, L1.P2, L2.P1) * CCW(L1.P1, L1.P2, L2.P2)
    D2 = CCW(L2.P1, L2.P2, L1.P1) * CCW(L2.P1, L2.P2, L1.P2)
    if D1 <= 0 and D2 <= 0:
        if D1 == 0 and D2 == 0:
            if L1.P2 <= L1.P1:
                L1.P1, L1.P2 = L1.P2, L1.P1
            if L2.P2 <= L2.P1:
                L2.P1, L2.P2 = L2.P2, L2.P1
            return L1.P1 <= L2.P2 and L2.P1 <= L1.P2
        return True
    return False

def P5(A):
    L = list()
    for i in range(len(A)):
        L.append(Point(i, A[i]))
    ret = 0
    for k in range(len(L)): #점 k가 감시할 수 있는 최대 사람 수 구하기
        tmp = 0
        for r in range(len(L)):
            if k==r : continue
            L1 = Line(L[k], L[r])
            mn = min(r, k)
            mx = max(r, k)
            flag = False
            for i in range(mn+1, mx):
                L2 = Line(L[i], Point(L[i].x, 0))
                if cross(L1, L2) : flag = True
            if not flag : tmp += 1
        ret = max(ret, tmp)
    return ret

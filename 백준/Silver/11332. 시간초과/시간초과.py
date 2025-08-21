T = int(input())
for i in range(T):
    S,N,T,L = input().split()
    N = int(N)
    T = int(T)
    L = int(L)
    L *= pow(10,8)
    flag = True
    if S == "O(N)":
        T *= N
    elif S == "O(2^N)":
        for i in range(N):
            if L < T:
                break
            T *= 2
    elif S == "O(N!)":
        for i in range(1,N+1):
            if L < T:
                break
            T *= i
    elif S == "O(N^3)":
        T *= N * N * N
    else:
        T *= N * N
    if L < T:
        flag = False
    if flag:
        print("May Pass.")
    else:
        print("TLE!")
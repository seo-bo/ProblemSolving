import sys,math
input = sys.stdin.readline
MOD = 1000000000
a = int(input().strip())
A = list(map(int,input().strip().split()))
b = int(input().strip())
B = list(map(int,input().strip().split()))
ans = math.gcd(math.prod(A),math.prod(B))
if ans >= MOD:
    ans %= MOD
    siz = len(str(ans))
    cnt = 0
    while siz + cnt < 9:
        print(0, end="")
        cnt += 1
    print(ans)
    sys.exit(0)
print(ans)
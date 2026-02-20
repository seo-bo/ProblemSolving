import sys
input = sys.stdin.readline
n,m = map(int,input().strip().split())
v = list(map(int,input().strip().split()))
v.sort()
ans = []
def dfs(depth):
    if depth == m:
        print(' '.join(map(str,ans)))
        return
    for i in v:
        ans.append(i)
        dfs(depth+1)
        ans.pop()
dfs(0)
#include <bits/stdc++.h>

using namespace std;

extern int excavate(int);

int solution(vector<int> depth, int money) {
    int n = depth.size();
    vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
    function<int(int,int)> dfs = [&] (int left, int right)
    {
        if(left > right)
        {
            return 0;
        }
        if(dp[left][right] != -1)
        {
            return dp[left][right];
        }
        int res = (1<<25);
        for(int i = left; i<=right;++i)
        {
            res = min(res, max(dfs(left,i-1), dfs(i+1,right)) + depth[i-1]);
        }
        return dp[left][right] = res;
    };
    dfs(1,n);
    int l = 1, r = n;
    while(l<=r)
    {
        int p = -1;
        for(int i =l; i<=r;++i)
        {
            if(max({0,dp[l][i-1], dp[i+1][r]}) + depth[i-1] == dp[l][r])
            {
                p = i;
                break;
            }
        }
        int ans = excavate(p);
        if(!ans)
        {
            return p;
        }
        else if(ans == -1)
        {
            r = p - 1;
        }
        else
        {
            l = p + 1;
        }
    }
    return 0;
}
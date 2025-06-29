#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
int main(void)
{
    cin.tie(0)->sync_with_stdio(0);
    int n = 0, k = 0;
    cin >> n >> k;
    int cnt = n;
    if (n <= 4 && k == n - 1)
    {
        cout << -1;
        return 0;
    }
    vector<int>ans(n, -1);
    vector<bool>visited(n + 1);
    if (k < n - 1)
    {
        ans[0] = k + 1, ans[1] = k, ans[n - 1] = k + 2;
        visited[k] = visited[k + 1] = visited[k + 2] = true;
    }
    else if (k == n - 1)
    {
        ans[0] = 1, ans[n - 1] = n;
        visited[1] = visited[n] = true;
    }
    for (int i = 0; i < n; ++i)
    {
        if (ans[i] == -1)
        {
            while (visited[cnt])
            {
                cnt--;
            }
            ans[i] = cnt--;
        }
        cout << ans[i] << ' ';
    }
    return 0;
}
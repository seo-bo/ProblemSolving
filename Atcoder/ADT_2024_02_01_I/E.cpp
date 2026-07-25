#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	ll n = 0;
	cin >> n;
	vector<ll>temp;
	for (ll i = 61; i >= 0; --i)
	{
		if (n & (1LL << i))
		{
			temp.push_back(i);
		}
	}
	int len = temp.size();
	vector<ll>ans;
	function<void(int, ll)>dfs = [&](int depth, ll now)
		{
			if (depth == len)
			{
				ans.push_back(now);
				return;
			}
			dfs(depth + 1, now);
			dfs(depth + 1, now | (1LL << temp[depth]));
		};
	dfs(0, 0);
	sort(ans.begin(), ans.end());
	for (auto& i : ans)
	{
		cout << i << '\n';
	}
	return 0;
}

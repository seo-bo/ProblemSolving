#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int> ans, v(n + 1), pos(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		pos[v[i]] = i;
		ans.push_back(v[i]);
	}
	auto cal = [&](vector<int> &base, vector<int> &score, int cnt, int p)
	{
		vector<int> s;
		for (int i = 2; i <= n; ++i)
		{
			if (!base[i])
			{
				continue;
			}
			while (!s.empty() && s.back() > base[i] && score[s.back()] <= cnt)
			{
				cnt -= score[s.back()];
				s.pop_back();
			}
			s.push_back(base[i]);
		}
		vector<int> fin = {p};
		while (!s.empty() && score[s.back()] <= cnt)
		{
			cnt -= score[s.back()];
			s.pop_back();
		}
		for (auto &i : s)
		{
			fin.push_back(i);
		}
		return fin;
	};
	int flag1 = 0, flag2 = 0;
	for (int i = 1; i <= n && !(flag1 || flag2); ++i)
	{
		int left = pos[i] - 1, right = n - pos[i] + 1;
		flag1 |= (left <= k), flag2 |= (right <= k);
		if (flag1) // 앞에거 싹다 잘라먹기
		{
			int cnt = k - left;
			vector<int> base(n + 1), score(n + 1);
			for (int j = 2, idx = pos[i] + 1; idx <= n; ++idx, ++j)
			{
				score[v[idx]] = 1;
				base[j] = v[idx];
			}
			ans = min(ans, cal(base, score, cnt, i));
		}
		if (flag2) // 뒤에거 잘라 먹기
		{
			int cnt = k - right;
			vector<int> base(n + 1), score(n + 1);
			for (int j = 2, idx = pos[i] + 1; idx <= n; ++idx, ++j)
			{
				score[v[idx]] = 0;
				base[j] = v[idx];
			}
			for (int j = right + 1, idx = 1; idx < pos[i]; ++idx, ++j)
			{
				score[v[idx]] = 1;
				base[j] = v[idx];
			}
			ans = min(ans, cal(base, score, cnt, i));
		}
	}
	for (auto &i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}

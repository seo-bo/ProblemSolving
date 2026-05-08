#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tp;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, x = 0, y = 0, z = 0;
	cin >> n >> x >> y >> z;
	vector<tp> v(n);
	for (int i = 1; i <= n; ++i)
	{
		auto &[a, b, c] = v[i - 1];
		c = i;
		cin >> a;
	}
	for (auto &[_, a, __] : v)
	{
		cin >> a;
	}
	vector<int> ans;
	sort(v.begin(), v.end(), [&](const tp &a, const tp &b)
		 { 
			if(get<0>(a) == get<0>(b))
			{
				return get<2>(a) < get<2>(b);
			}
			return get<0>(a) > get<0>(b); });
	vector<int> visited(n + 1);
	for (int i = 0; x; ++i)
	{
		int p = get<2>(v[i]);
		if (visited[p])
		{
			continue;
		}
		visited[p] = 1;
		ans.push_back(p);
		x--;
	}
	sort(v.begin(), v.end(), [&](const tp &a, const tp &b)
		 { 
			if(get<1>(a) == get<1>(b))
			{
				return get<2>(a) < get<2>(b);
			}
			return get<1>(a) > get<1>(b); });
	for (int i = 0; y; ++i)
	{
		int p = get<2>(v[i]);
		if (visited[p])
		{
			continue;
		}
		visited[p] = 1;
		ans.push_back(p);
		y--;
	}
	sort(v.begin(), v.end(), [&](const tp &a, const tp &b)
		 { if(get<0>(a) + get<1>(a) == get<0>(b) + get<1>(b))
			{
				return get<2>(a) < get<2>(b);
			}
			return get<0>(a) + get<1>(a) > get<0>(b) + get<1>(b); });
	for (int i = 0; z; ++i)
	{
		int p = get<2>(v[i]);
		if (visited[p])
		{
			continue;
		}
		visited[p] = 1;
		ans.push_back(p);
		z--;
	}
	sort(ans.begin(), ans.end());
	for (auto &i : ans)
	{
		cout << i << '\n';
	}
	return 0;
}

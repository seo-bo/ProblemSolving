#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, k = 0;
	cin >> n;
	vector<int>v(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
	}
	cin >> k;
	string str;
	cin >> str;
	vector<int>per;
	for (int i = 0; i < k; ++i)
	{
		if (str[i] == 'J')
		{
			per.push_back(i);
		}
	}
	if (per.empty())
	{
		cout << "NO";
		return 0;
	}
	vector<int>nxt(k, INT_MAX);
	for (int i = 0; i < k; ++i)
	{
		auto it = lower_bound(per.begin(), per.end(), i);
		if (it != per.end())
		{
			nxt[i] = *it - i;
		}
		else
		{
			nxt[i] = per[0] + k - i;
		}
	}
	vector<int>prefix(2 * k + 1, 0);
	for (int i = 1; i <= 2 * k; ++i)
	{
		prefix[i] = prefix[i - 1] + (str[(i - 1) % k] == 'A');
	}
	int idx = 0;
	for (int i = 2; i <= n; ++i)
	{
		if (v[i] == -1)
		{
			if (str[idx] != 'D')
			{
				cout << "NO";
				return 0;
			}
			idx = (idx + 1) % k;
			int temp = nxt[idx];
			if (temp == INT_MAX)
			{
				cout << "NO";
				return 0;
			}
			idx = (idx + temp + 1) % k;
		}
		else if (!v[i])
		{
			int temp = nxt[idx];
			if (temp == INT_MAX)
			{
				cout << "NO";
				return 0;
			}
			idx = (idx + temp + 1) % k;
		}
		else
		{
			int temp = nxt[idx];
			if (temp == INT_MAX)
			{
				cout << "NO";
				return 0;
			}
			if (prefix[idx + temp] - prefix[idx] < v[i])
			{
				cout << "NO";
				return 0;
			}
			idx = (idx + temp + 1) % k;
		}
	}
	cout << "YES";
	return 0;
}
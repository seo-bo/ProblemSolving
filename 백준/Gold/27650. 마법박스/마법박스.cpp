#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<bool>visited(n + 5, true);
	vector<int>prime;
	visited[0] = visited[1] = false;
	for (ll i = 2; i <= n; ++i)
	{
		if (visited[i])
		{
			prime.push_back(i);
			for (ll j = i * i; j <= n; j += i)
			{
				visited[j] = false;
			}
		}
	}
	while (prime.back() > n)
	{
		prime.pop_back();
	}
	int left = 0, right = prime.size() - 1, ans = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		cout << format("? {}", prime[mid]) << endl;
		int temp = 0;
		cin >> temp;
		if (temp)
		{
			left = mid + 1;
		}
		else
		{
			ans = prime[mid];
			right = mid - 1;
		}
	}
	cout << format("! {}", ans) << endl;
	return 0;
}
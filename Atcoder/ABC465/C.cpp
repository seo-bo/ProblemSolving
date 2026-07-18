#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string str;
	cin >> str;
	int f = 1;
	deque<int>dq;
	for (int i = 1; i <= n; ++i)
	{
		if (!f)
		{
			dq.push_back(i);
		}
		else
		{
			dq.push_front(i);
		}
		int p = str[i - 1];
		if (p == 'o')
		{
			f ^= 1;
		}
	}
	if (!f)
	{
		for (auto& i : dq)
		{
			cout << i << ' ';
		}
		return 0;
	}
	for (int i = n - 1; i >= 0; --i)
	{
		cout << dq[i] << ' ';
	}
	return 0;
}

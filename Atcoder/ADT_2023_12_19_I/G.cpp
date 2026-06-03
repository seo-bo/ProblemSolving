#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	priority_queue<int, vector<int>, greater<int>> pq;
	int n = 0, k = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		int a = 0;
		cin >> a;
		pq.push(a);
		if (pq.size() > k)
		{
			pq.pop();
		}
		if (i >= k)
		{
			cout << pq.top() << '\n';
		}
	}
	return 0;
}

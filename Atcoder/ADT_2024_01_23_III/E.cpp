#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<pii>v(4);
	for (auto& [a, b] : v)
	{
		cin >> a >> b;
	}
	for (int i = 0; i < 4; ++i)
	{
		auto [ax, ay] = v[i];
		auto [bx, by] = v[(i + 1) % 4];
		auto [cx, cy] = v[(i + 2) % 4];
		int pivot = (bx - ax) * (cy - by) - (by - ay) * (cx - bx);
		if (pivot < 0)
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}

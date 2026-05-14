#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> A(n), C(m);
	vector<pii> choco, box;
	for (auto &i : A)
	{
		cin >> i;
	}
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		choco.push_back(make_pair(A[i], a));
	}
	for (auto &i : C)
	{
		cin >> i;
	}
	for (int i = 0; i < m; ++i)
	{
		int a = 0;
		cin >> a;
		box.push_back(make_pair(C[i], a));
	}
	map<int, int> mm;
	sort(choco.rbegin(), choco.rend());
	sort(box.rbegin(), box.rend());
	int idx = 0, blen = box.size();
	for (auto &[a, b] : choco)
	{
		while (idx < blen && box[idx].first >= a)
		{
			mm[box[idx++].second]++;
		}
		auto it = mm.lower_bound(b);
		if (it == mm.end())
		{
			cout << "No";
			return 0;
		}
		if (--it->second == 0)
		{
			mm.erase(it);
		}
	}
	cout << "Yes";
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<pii>v;
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		v.push_back(make_pair(a, 0));
	}
	for (int i = 0; i < m; ++i)
	{
		int a = 0;
		cin >> a;
		v.push_back(make_pair(a, 1));
	}
	sort(v.begin(), v.end());
	vector<int>A, B;
	for (int i = 0; i < n + m; ++i)
	{
		if (v[i].second == 0)
		{
			A.push_back(i + 1);
		}
		else
		{
			B.push_back(i + 1);
		}
	}
	for (auto& i : A)
	{
		cout << i << ' ';
	}
	cout << '\n';
	for (auto& i : B)
	{
		cout << i << ' ';
	}
	cout << '\n';
	return 0;
}

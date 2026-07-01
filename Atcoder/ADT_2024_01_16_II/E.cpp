#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string A, B;
	cin >> A >> B;
	if (A.size() > B.size())
	{
		cout << "No";
		return 0;
	}
	auto cal = [&](string str)
	{
		int pre = -1, cnt = 1;
		vector<pii> v;
		for (auto &i : str)
		{
			int now = i - 'a';
			if (pre != now)
			{
				v.push_back(make_pair(pre, cnt));
				pre = now, cnt = 1;
				continue;
			}
			cnt++;
		}
		v.push_back(make_pair(pre, cnt));
		return v;
	};
	vector<pii> a = cal(A), b = cal(B);
	if (a.size() != b.size())
	{
		cout << "No";
		return 0;
	}
	int len = a.size();
	for (int i = 0; i < len; ++i)
	{
		auto &[aa, ab] = a[i];
		auto &[ba, bb] = b[i];
		if (aa != ba || ab > bb || (ab < bb && ab == 1))
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}

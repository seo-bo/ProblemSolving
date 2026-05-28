#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<int> v(4);
	set<int> s;
	for (int i = 0; i < 4; ++i)
	{
		char a;
		cin >> a;
		v[i] = a - '0';
		s.insert(v[i]);
	}
	int flag = 0;
	for (int i = 0; i < 3; ++i)
	{
		int nxt = (v[i] + 1) % 10;
		if (v[i + 1] != nxt)
		{
			flag = 1;
			break;
		}
	}
	cout << ((!flag || s.size() == 1) ? "Weak" : "Strong");
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	string str, base = "RUX";
	cin >> n >> str;
	vector<int>v(3);
	for (auto& i : str)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (base[j] == i)
			{
				v[j]++;
				break;
			}
		}
	}
	int q = 0, ans = 0;
	cin >> q;
	while (q--)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		a--, b--;
		int mini = min(v[2], min(a, b));
		a -= mini, b -= mini;
		if (v[0] >= a && v[1] >= b)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}
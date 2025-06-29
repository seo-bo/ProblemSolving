#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string a, b, c = "aeiou";
	cin >> a >> b;
	auto cal = [&](string str)
		{
			string res;
			bool f1 = false, f2 = false;
			for (auto& i : str)
			{
				if (!f1 && c.find(i) != string::npos)
				{
					f1 = true;
				}
				else if (f1 && c.find(i) == string::npos)
				{
					f2 = true;
					break;
				}
				res += i;
			}
			if (!f1 || !f2)
			{
				res.clear();
			}
			return res;
		};
	string A = cal(a), B = cal(b);
	if (A.empty() || B.empty())
	{
		cout << "no such exercise";
		return 0;
	}
	cout << A << B;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	vector<int>b, k, r;
	int len = str.size();
	for (int i = 0; i < 8; ++i)
	{
		if (str[i] == 'B')
		{
			b.push_back(i);
		}
		else if (str[i] == 'K')
		{
			k.push_back(i);
		}
		else if (str[i] == 'R')
		{
			r.push_back(i);
		}
	}
	cout << (((b[0] + b[1]) % 2 == 1 && r[0] < k[0] && k[0] < r[1]) ? "Yes" : "No");
	return 0;
}

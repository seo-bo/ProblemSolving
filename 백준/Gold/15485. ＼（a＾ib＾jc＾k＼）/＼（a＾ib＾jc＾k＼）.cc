#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int main(void) // 1,3,7,15,31..
{
	cin.tie(0)->sync_with_stdio(0);
	string str, base = "-abc";
	cin >> str;
	vector<int>v(4);
	v[0] = 1;
	for (auto& i : str)
	{
		for (int j = 1; j <= 3; ++j)
		{
			if (i == base[j])
			{
				v[j] = ((ll)v[j] * 2 + v[j - 1]) % MOD;
				break;
			}
		}
	}
	cout << v[3];
	return 0;
}
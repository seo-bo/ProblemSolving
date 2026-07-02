##include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int> v(2005);
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		v[a]++;
	}
	for (int i = 0; i <= 2004; ++i)
	{
		if (!v[i])
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	vector<int> v(2005);
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		cin >> a;
		v[a]++;
	}
	for (int i = 0; i <= 2004; ++i)
	{
		if (!v[i])
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}

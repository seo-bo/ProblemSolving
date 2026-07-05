#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	string str;
	cin >> str;
	char pivot = str.front();
	for (int i = 1; i < n; ++i)
	{
		if (pivot == str[i])
		{
			cout << "No";
			return 0;
		}
		pivot = str[i];
	}
	cout << "Yes";
	return 0;
}

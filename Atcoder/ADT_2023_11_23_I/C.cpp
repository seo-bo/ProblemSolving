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
	for (int i = 0; i < n;)
	{
		if (i + 1 < n)
		{
			if (str[i] == 'n' && str[i + 1] == 'a')
			{
				cout << "nya";
				i += 2;
				continue;
			}
		}
		cout << str[i++];
	}
	return 0;
}

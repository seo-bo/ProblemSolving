#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int cnt = 0;
	sort(str.begin(), str.end());
	do
	{
		cnt++;
	} while (next_permutation(str.begin(), str.end()));
	cout << cnt;
	return 0;
}

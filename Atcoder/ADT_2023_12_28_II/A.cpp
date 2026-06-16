#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	string str;
	cin >> str;
	int a = 0, b = 0;
	cin >> a >> b;
	swap(str[a - 1], str[b - 1]);
	cout << str;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0;
	cin >> n;
	cout << ((n && n % 100 == 0) ? "Yes" : "No");
	return 0;
}

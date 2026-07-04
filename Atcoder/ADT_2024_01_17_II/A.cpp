#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int  n = 0;
	cin >> n;
	cout << ((n == 0 || n % 100) ? "No" : "Yes");
	return 0;
}

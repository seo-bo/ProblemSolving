#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	vector<vector<int>>dir = { {-1,0},{1,0},{0,-1},{0,1} };
	vector<int>visited((1 << 17), INT_MAX);
	auto in = [&]
		{
			int temp = 0;
			for (int i = 0; i < 4; ++i)
			{
				string str;
				cin >> str;
				for (int j = 0; j < 4; ++j)
				{
					if (str[j] == 'P')
					{
						temp |= (1 << (i * 4 + j));
					}
				}
			}
			return temp;
		};
	auto sv = [&](int& cur, int& ans, int& A, int& B)
		{
			if ((cur & (1 << A)))
			{
				ans |= (1 << B);
			}
			else
			{
				ans &= ~(1 << B);
			}
		};
	int base = in(), res = in();
	visited[base] = 0;
	queue<int>q;
	q.push(base);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		if (cur == res)
		{
			cout << visited[cur];
			break;
		}
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				int A = i * 4 + j;
				for (int k = 0; k < 4; ++k)
				{
					int nx = i + dir[k][0];
					int ny = j + dir[k][1];
					if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4)
					{
						int B = nx * 4 + ny;
						int temp = cur;
						sv(cur, temp, A, B);
						sv(cur, temp, B, A);
						if (visited[temp] > visited[cur] + 1)
						{
							visited[temp] = visited[cur] + 1;
							q.push(temp);
						}
					}
				}
			}
		}
	}
	return 0;
}
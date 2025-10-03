#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
	short data;
	struct Node* nxt;
}Node;

char name[3000][32];
short status[3000][3];
Node* graph[3000];
short degree[3000], ans[3010], q[3010];
short a_head = 0, q_head = 0, q_now = 0;

void psh(int idx, int num)
{
	Node* now = (Node*)malloc(sizeof(Node));
	now->data = num, now->nxt = NULL;
	if (graph[idx] != NULL)
	{
		now->nxt = graph[idx];
	}
	graph[idx] = now;
}

int compare(const void* a, const void* b)
{
	return strcmp(name[*(short*)a], name[*(short*)b]);
}

int main(void)
{
	memset(ans, -1, sizeof(ans));
	memset(q, -1, sizeof(q));
	short n = 0;
	scanf("%hd", &n);
	for (short i = 0; i < n; ++i)
	{
		scanf("%s", name[i]);
		for (short j = 0; j < 3; ++j)
		{
			scanf("%hd", &status[i][j]);
		}
		for (short j = 0; j < i; ++j)
		{
			short a = 0, b = 0;
			for (short k = 0; k < 3; ++k)
			{
				if (status[i][k] > status[j][k])
				{
					a++;
				}
				else if (status[i][k] < status[j][k])
				{
					b++;
				}
			}
			if (a > b)
			{
				psh(i, j);
				degree[j]++;
			}
			else if (a < b)
			{
				psh(j, i);
				degree[i]++;
			}
		}
	}
	short p = n;
	for (short i = 0; i < n; ++i)
	{
		if (!degree[i])
		{
			q[q_head++] = i;
			ans[a_head++] = i;
			p--;
		}
	}
	while (1)
	{
		short cur = q[q_now++];
		if (cur == -1)
		{
			break;
		}
		for (Node* i = graph[cur]; i != NULL; i = i->nxt)
		{
			if (--degree[i->data] == 0)
			{
				p--;
				q[q_head++] = i->data;
			}
		}
	}
	if (p)
	{
		printf("Paradoxe Absurdo");
		return 0;
	}
	qsort(ans, a_head, sizeof(short), compare);
	for (short i = 0; i < a_head; ++i)
	{
		printf("%s\n", name[ans[i]]);
	}
	return 0;
}
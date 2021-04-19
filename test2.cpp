#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

char G[251][251];
int M = 0, N = 0;

void dfs(int x, int y, char now, char c)
{
	if (y < 1 || y > N || x < 1 || x > M || G[y][x] != now) return;

	G[y][x] = c;
	dfs(x + 1, y, now, c);
	dfs(x - 1, y, now, c);
	dfs(x, y + 1, now, c);
	dfs(x, y - 1, now, c);
}

int main()
{
	char cmd, C, Now;	
	int x1, x2, y1, y2;
	string Name, str;
	
	memset(G, 'O', sizeof(G));
	while (cin >> cmd, cmd != 'X')
	{
		switch (cmd)
		{
		case 'I':
			cin >> M >> N;
			memset(G, 'O', sizeof(G));
			break;

		case 'C':
			memset(G, 'O', sizeof(G));
			break;

		case 'L':
			cin >> x1 >> y1 >> C;
			G[y1][x1] = C;
			break;

		case 'V':
			cin >> x1 >> y1 >> y2 >> C;
			if (y1 > y2) swap(y1, y2);
			for (int i = y1; i <= y2; ++i) G[i][x1] = C;
			break;

		case 'H':
			cin >> x1 >> x2 >> y1 >> C;
			if (x1 > x2) swap(x1, x2);
			for (int i = x1; i <= x2; ++i) G[y1][i] = C;
			break;

		case 'K':
			cin >> x1 >> y1 >> x2 >> y2 >> C;
			if (y1 > y2) swap(y1, y2);
			if (x1 > x2) swap(x1, x2);
			for (int i = y1; i <= y2; ++i)
				for (int j = x1; j <= x2; ++j) G[i][j] = C;
			break;

		case 'F':
			cin >> x1 >> y1 >> C;
			if (G[y1][x1] != C) dfs(x1, y1, G[y1][x1], C);
			break;

		case 'S':
			cin >> Name;
			cout << Name << "\n";
			for (int i = 1; i <= N; ++i)
			{
				for (int j = 1; j <= M; ++j) cout << G[i][j];
				cout << "\n";
			}
			break;

		default:
			getline(cin, str);
			break;
		}
	}

	return 0;
}
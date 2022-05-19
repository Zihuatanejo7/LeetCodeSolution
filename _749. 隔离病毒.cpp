
# include <vector>
# include <queue>
# include <iostream>
using namespace std;

struct Pos
{
	int x, y;
	Pos(int _x, int _y) :x(_x), y(_y) {}
};

class Solution
{
public:
	// BFS  
	int process(vector<vector<int>>& vec)
	{
		int row = vec.size();
		int col = vec[0].size();
		int sum = 0;
		int curlevel = 0;
		queue<Pos>que;

		for (int i = 0; i < col; ++i)
		{
			for (int j = 0; j < row; ++j)
			{
				if (1 == vec[i][j])
				{
					que.push(Pos(i, j));
					sum++;
				}
				else
				{
					continue;
				}
			}
		}

		if (sum == row * col || !sum)
			return -1;


		while (true)
		{
			int size = que.size();

			for (int i = 0; i < size; ++i)
			{
				Pos temp = que.front();
				que.pop();

				int x = temp.x;
				int y = temp.y;

				// left
				if ((x - 1) >= 0 && !vec[x - 1][y])
				{
					que.push(Pos(x - 1, y));
					vec[x - 1][y] = 1;
					sum++;
				}

				// right
				if ((x + 1) < col && !vec[x + 1][y])
				{
					que.push(Pos(x + 1, y));
					vec[x + 1][y] = 1;
					sum++;
				}

				// bottom
				if ((y - 1) >= 0 && !vec[x][y - 1])
				{
					que.push(Pos(x, y - 1));
					vec[x][y - 1] = 1;
					sum++;
				}

				// down
				if ((y + 1) < row && !vec[x][y + 1])
				{
					que.push(Pos(x, y + 1));
					vec[x][y + 1] = 1;
					sum++;
				}
			}
			curlevel++;
			if (sum == row * col)
				return curlevel;
		}
		return -1;
	}
};

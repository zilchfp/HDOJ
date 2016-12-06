//knight moves

#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct pos {
	int x = 0, y = 0;
	int step = 0;
};

int hdoj1372() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // LOCAL

	string start, end;
	bool visited[8 + 2][8 + 2];
	
	while (cin >> start >> end)
	{
		memset(visited, false, sizeof(visited));
		int movex[8] = { -2,-2,-1,-1, 1,1, 2,2 };
		int movey[8] = { -1, 1,-2, 2,-2,2,-1,1 };
		queue<pos> q;
		bool isok = false;

		pos dest,begin;
		//注意，这里的字符串中的数字需要减去‘0’才能得到阿拉伯数字
		//否则会被当做对应的ASCII码处理
		//除此之外，还要注意y的坐标不是减去‘0’，因为这样的话y方向就成了从1开始，
		//但x方向却是从0开始
		//PS： 'a' 的ASCII码为97     ‘A'的ASCII码为65      ‘0’的ASCII码为48
		begin.x = start[0] - 'a';	begin.y = start[1] - '1' ;
		dest.x = end[0] - 'a';		dest.y = end[1] - '1';
		visited[begin.x][begin.y] = true;
		q.push(begin);

		while (!q.empty())
		{
			pos nowpos = q.front();
			q.pop();
			if (nowpos.x == dest.x && nowpos.y == dest.y) {
				isok = true;
				cout << "To get from " << start << " to " << end << " takes " << nowpos.step << " knight moves." << endl;
				break;
			}
			
			for (int i = 0; i < 8; i++) {
				int tempx = nowpos.x + movex[i], tempy = nowpos.y + movey[i];
				if ((tempx >= 0) && (tempx < 8) 
				 && (tempy >= 0) && (tempy < 8) &&(!visited[tempx][tempy])) {
					visited[tempx][tempy] = true;
					pos temppos;
					temppos.x = tempx; temppos.y = tempy;
					temppos.step = nowpos.step + 1;
					q.push(temppos);
				}
			}


			
			
		}
	}
	return 0;
}
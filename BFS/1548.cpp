// a strange lift


#include <iostream>
#include <queue>
using namespace std;

int hdoj1548() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // LOCAL


	int lift[200 + 10];
	int times[200 + 10];
	bool visited[200 + 10];
	int n = 1, a = 1 , b = 1;

	while (scanf("%d%d%d",&n,&a,&b) == 3 && n  ){
		memset(visited, 0, sizeof(visited));
		memset(times, 0, sizeof(times));
		memset(lift, 0, sizeof(lift));
		for (int i = 1; i <= n; i++) 
			cin >> lift[i];

		queue<int> q;
		visited[a] = true;
		times[a] = 0;
		q.push(a);
		bool isok = false;
		while (!q.empty())
		{
			int now = q.front();
			int ki = lift[q.front()];
			q.pop();
			if (now == b) {
				isok = true;
				cout << times[now] << endl; break;
			}
			if ((now + ki <= n) && !visited[now + ki]  ) {
				q.push(now + ki);
				times[now + ki] = times[now] + 1;
				visited[now + ki] = true;
			}
			if ((now - ki > 0) && !visited[now - ki]) {
				times[now - ki] = times[now] + 1;
				q.push(now - ki);
				visited[now - ki] = true;
			}
		}
		if (!isok) cout << "-1" << endl;
		
	}


	return 0;
}
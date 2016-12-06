#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct balloon {
	int time = 0;
	string color;
};

int hdoj1004() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // LOCAL
	string s;
	balloon b[2000];

	int n = 0;
	while (scanf("%d",&n) == 1 && n)
	{

		if (n == 1) {
			cin >> s;
			cout << s << endl;
			continue;
		}
		int type = 0;
		for (int i = 0; i < n; i++) {
			bool isinsert = false;
			cin >> s;
			for (int k = 0; k <= type; k++) {
				balloon *p = &b[k];
				if (p->color == s) {
					p->time++; break;
				}
			}
			if (!isinsert) {
				balloon *p = &b[++type];
				p->color = s;
				p->time = 1;
			}
		}
		string ans;
		int maxtime = -1;
		for (int i = 0; i < type; i++) {
			balloon *p = &b[i];
			if (p->time > maxtime) {
				ans = p->color;
				maxtime = p->time;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
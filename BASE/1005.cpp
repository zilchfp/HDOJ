#include <iostream>

using namespace std;


int f[60];
int hdoj1005() {
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // LOCAL
	f[1] = 1;
	f[2] = 1;
	int A = 0, B = 0, n = 0;
	while (scanf("%d %d %d",&A,&B,&n) == 3 && (A || B || n) )
	{
		if (n == 1 || n == 2) {
			printf("1\n");break;
		}

		for (int i = 3; i <= 49; i++) {
			f[i] = (A*f[i - 1] + B*f[i - 2]) % 7;
		}
		printf("%d\n", f[n%49]);
	}


	return 0;
}
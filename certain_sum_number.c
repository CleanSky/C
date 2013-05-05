#include <stdio.h>
#include <stdlib.h>

/*
给定一个数t，以及n个整数，在这n个数中找到相加和为t的所有组合。
例如t=4，n=6，这6个数为[4,3,2,2,1,1]，这样输出就有4个不同的组合相加为4: 4, 3+1, 2+2, and 2+1+1。
*/

int ok;//是否存在这样的组合
int total, n, data[12];//数据存储
int count, ans[12];//结果存储

void dfs(int i, int sum) {
	int j;
	if (sum == total) {
		ok = 1;
		for(j = 1, printf("%d",ans[0]); j < count; j++) {
            printf("+%d",ans[j]);
        }

		printf("\n");
		return;
	}

	if (i >= n || sum > total)
        return;

	for (j = i; j < n; j++) {
		//以下的处理避免了重复的情况
		if(j == i || data[j] != data[j - 1]) {
			ans[count++] = data[j];
			dfs(j + 1, sum + data[j]);
			count--;
		}
	}
}

int main() {
	int i;
	while (scanf("%d%d",&total,&n)!=EOF && n) {
		for (i=0;i<n;i++) {
			scanf("%d",&data[i]);
		}

		printf("Sums of %d:\n", total);
		ok = count = 0;
		dfs(0, 0);
		if (ok == 0) {
            printf("NONE\n");
		}
	}

	return 0;
}

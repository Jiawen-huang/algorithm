/*连号区间数
问题描述
小明这些天一直在思考这样一个奇怪而有趣的问题：

在1~N的某个全排列中有多少个连号区间呢？这里所说的连号区间的定义是：

如果区间[L, R] 里的所有元素（即此排列的第L个到第R个元素）递增排序后能得到一个长度为R-L+1的“连续”数列，则称这个区间连号区间。

当N很小的时候，小明可以很快地算出答案，但是当N变大的时候，问题就不是那么简单了，现在小明需要你的帮助。

输入格式
第一行是一个正整数N (1 <= N <= 50000), 表示全排列的规模。

第二行是N个不同的数字Pi(1 <= Pi <= N)， 表示这N个数字的某一全排列。

输出格式
输出一个整数，表示不同连号区间的数目。

样例输入1
4
3 2 4 1
样例输出1
7
样例输入2
5
3 4 2 5 1
样例输出2
9
解释：
第一个用例中，有7个连号区间分别是：[1,1], [1,2], [1,3], [1,4], [2,2], [3,3], [4,4]
第二个用例中，有9个连号区间分别是：[1,1], [1,2], [1,3], [1,4], [1,5], [2,2], [3,3], [4,4], [5,5]
*/

#include<iostream>
#include<algorithm>
using namespace std;
#define Num 5000
int ans = 0;

int main()
{
	int a[Num];
	int n;
	cin >> n;
	for(int i = 0;i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0;i < n;i++)
	{
		int mini = n;
		int maxi = 1; 
		for(int j = i;j < n;j++)
		{
			mini = min(mini,a[j]);
			maxi = max(maxi,a[j]);
			if(maxi - mini == j - i)
			ans++;
		}
	}
	cout <<ans;
	return 0;
} 
/*
#include <stdio.h>  
#define Max_len 5005  
  
int main(){  
      
    int n, count = 0;  
    int a[Max_len], i, j, min, max;  
  
    scanf("%d", &n);  
    for(i = 0; i < n; i++) {  
        scanf("%d", &a[i]);  
    }  
  
    for(i = 0; i < n; i++) {  
        min = n;  
        max = 1;  
        for(j = i; j < n; j++) {  
            if(min > a[j]) {  
                min = a[j];  
            }  
            if(max < a[j]) {  
                max = a[j];  
            }  
            if(max - min == j - i) {  
                count++;  
            }  
        }  
    }  
  
    printf("%d\n", count);  
    return 0;  
}  */

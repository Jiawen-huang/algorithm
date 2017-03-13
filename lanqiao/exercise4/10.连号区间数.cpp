/*����������
��������
С����Щ��һֱ��˼������һ����ֶ���Ȥ�����⣺

��1~N��ĳ��ȫ�������ж��ٸ����������أ�������˵����������Ķ����ǣ�

�������[L, R] �������Ԫ�أ��������еĵ�L������R��Ԫ�أ�����������ܵõ�һ������ΪR-L+1�ġ����������У������������������䡣

��N��С��ʱ��С�����Ժܿ������𰸣����ǵ�N����ʱ������Ͳ�����ô���ˣ�����С����Ҫ��İ�����

�����ʽ
��һ����һ��������N (1 <= N <= 50000), ��ʾȫ���еĹ�ģ��

�ڶ�����N����ͬ������Pi(1 <= Pi <= N)�� ��ʾ��N�����ֵ�ĳһȫ���С�

�����ʽ
���һ����������ʾ��ͬ�����������Ŀ��

��������1
4
3 2 4 1
�������1
7
��������2
5
3 4 2 5 1
�������2
9
���ͣ�
��һ�������У���7����������ֱ��ǣ�[1,1], [1,2], [1,3], [1,4], [2,2], [3,3], [4,4]
�ڶ��������У���9����������ֱ��ǣ�[1,1], [1,2], [1,3], [1,4], [1,5], [2,2], [3,3], [4,4], [5,5]
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

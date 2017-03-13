/*问题描述
100 可以表示为带分数的形式：100 = 3 + 69258 / 714。

还可以表示为：100 = 82 + 3546 / 197。

注意特征：带分数中，数字1~9分别出现且只出现一次（不包含0）。

类似这样的带分数，100 有 11 种表示法。

输入格式
从标准输入读入一个正整数N (N<1000*1000)

输出格式
程序输出该数字用数码1~9不重复不遗漏地组成带分数表示的全部种数。

注意：不要求输出每个表示，只统计有多少表示法！

样例输入1
100
样例输出1
11
样例输入2
105
样例输出2
6*/
//方法一：dfs
/* 
#include<iostream>
using namespace std;
int a[9];
int visit[9] = {0};
int ans = 0;
int N;
int num(int start,int end)//具体计算该数对应的十进制是多少  
{
	int number = 0;
	if(start == end)
	return a[start];
	for(int i = start;i <= end;i++)
	{
		number = number*10 + a[i];
	}
	return number;
}
void solve()
{
	int x1,x2,x3;
	for(int i = 0 ; i< 9;i++)//整数部分最少为一位数，最多为八位数  
	{
		x1 = num(0,i);
		if(x1>=N)  
            break;  
		for(int j = i+1;j < 9;j++)
		{//for(int j=i+(9-i)/2; j<=9; j++)
		//分母的位数不会比分子多，因此在剩下的(9-i)个数中，它最多得到(9-i)/2个，最少1个。再剩下的都给分子。  
			x3 = num(j+1,8);
			x2 = num(i+1,j);
			if((N - x1)*x3 == x2)
				ans++;
		}
		
	}
	
}
void dfs(int index)
{
	if(index == 9)
	{
		solve();
		return;
	}
	for(int i = 0;i < 9;i++)
	{
		if(!visit[i])
		{
			visit[i] = 1;
			a[index] = i+1;
			dfs(index + 1);
			visit[i] = 0;
		}
	}
}
int main()
{

	cin >> N;
	dfs(0);
	cout<<ans;
	return 0;
} */

//方法二：next_permutation()
#include<iostream>
#include<algorithm>
using namespace std;
int N;
int ans = 0;
int num(int start,int end,int a[])
{
	int number= 0;
	if(start == end)
		return a[start];
	for(int i = start;i <= end;i++)
	{
		number = number*10+a[i];
	}
	return number;
}
int main()
{
	cin >> N;
	int a[9] = {1,2,3,4,5,6,7,8,9};
	while(next_permutation(a,a+9))//全排列函数
	{
		int x1,x2,x3;
		for(int i = 0;i < 9;i++)
		{
			x1 = num(0,i,a);
			if(N < x1) break;
			for(int j = i+1;j< 9;j++)
			{
				x2 = num(i+1,j,a);
				x3 = num(j+1,8,a);
			//	cout << x1 <<"        "<<x2<<"          "<<x3<<endl;
				if((N - x1)*x3 == x2) ans++;
			}	
		}	
	} 
	cout << ans;
	return 0;
} 

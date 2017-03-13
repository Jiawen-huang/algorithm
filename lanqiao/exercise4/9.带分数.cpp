/*��������
100 ���Ա�ʾΪ����������ʽ��100 = 3 + 69258 / 714��

�����Ա�ʾΪ��100 = 82 + 3546 / 197��

ע���������������У�����1~9�ֱ������ֻ����һ�Σ�������0����

���������Ĵ�������100 �� 11 �ֱ�ʾ����

�����ʽ
�ӱ�׼�������һ��������N (N<1000*1000)

�����ʽ
�������������������1~9���ظ�����©����ɴ�������ʾ��ȫ��������

ע�⣺��Ҫ�����ÿ����ʾ��ֻͳ���ж��ٱ�ʾ����

��������1
100
�������1
11
��������2
105
�������2
6*/
//����һ��dfs
/* 
#include<iostream>
using namespace std;
int a[9];
int visit[9] = {0};
int ans = 0;
int N;
int num(int start,int end)//������������Ӧ��ʮ�����Ƕ���  
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
	for(int i = 0 ; i< 9;i++)//������������Ϊһλ�������Ϊ��λ��  
	{
		x1 = num(0,i);
		if(x1>=N)  
            break;  
		for(int j = i+1;j < 9;j++)
		{//for(int j=i+(9-i)/2; j<=9; j++)
		//��ĸ��λ������ȷ��Ӷ࣬�����ʣ�µ�(9-i)�����У������õ�(9-i)/2��������1������ʣ�µĶ������ӡ�  
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

//��������next_permutation()
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
	while(next_permutation(a,a+9))//ȫ���к���
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

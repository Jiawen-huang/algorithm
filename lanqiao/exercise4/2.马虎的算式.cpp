/*�ڶ���:

����: ������ʽ
    С���Ǹ������ӣ���Сѧ��ʱ�򾭳�����ʦд�ںڰ��ϵ���Ŀ�����ˡ�
    ��һ�Σ���ʦ������Ŀ�ǣ�36 x 495 = ?
    ��ȴ�������ˣ�396 x 45 = ?
    �����ȴ��Ϸ���ԣ����Ĵ𰸾�Ȼ�ǶԵģ���
    ��Ϊ 36 * 495 = 396 * 45 = 17820
    �����������ɺ�������ܻ��кܶ࣬���磺27 * 594 = 297 * 54
    ���� a b c d e ����1~9��ͬ��5�����֣�ע���Ǹ�����ͬ�����֣��Ҳ���0��
    ���������磺 ab * cde = adb * ce ��������ʽһ���ж������أ�
�������ü����������Ѱ�����еĿ��ܣ����ش�ͬ��ʽ����������
����˷������ɵ���ʽ��Ϊ��ͬ�����࣬���Դ𰸿϶��Ǹ�ż����
��ֱ��ͨ��������ύ��
ע�⣺ֻ�ύһ����ʾ����ͳ�������������֣���Ҫ�ύ�����̻�������������ݡ�*/
//����һ������ö�� 
/*
#include<iostream>
using namespace std;
int main()
{
	int ans =0;
	for(int a = 1;a<=9;a++)
	{
		for(int b = 1;b<=9;b++)
		{
			if(b == a) continue;
			for(int c = 1;c<=9;c++)
			{
				if(b ==a || b ==c) continue;
				for(int d = 1;d<=9;d++)
				{
					if(d==a || d ==b|| d==c ) continue;
					for(int e = 1;e<=9;e++)
					{
						if(e == a||e==b||e==c||e==d) continue;
						if((a*10+b )*(c*100+d*10+e) ==(a*100+d*10+b)*(c*10+e))
						ans++;
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}*/
//��������dfs
#include<iostream>
using namespace std;
int a[5];
int visit[10]={0};
int ans = 0;
void dfs(int index)
{
	if(index == 5)
	{
		if((a[0]*10+a[1])*(a[2]*100+a[3]*10+a[4]) == (a[0]*100+a[3]*10+a[1])*(a[2]*10+a[4]))
		ans++;
	}
	for(int i = 1;i<=9;i++)
	{
		if(!visit[i]){
		a[index] = i;
		visit[i] = 1;
		dfs(index + 1);
		visit[i] = 0;
		}
	}
}
int main()
{
	dfs(0);
	cout << ans;
	return 0;
} 

/*3.���⣺��״��


    ��˵��ʫ����ף�һ���������Һ����Ӳ�������


    һ�죬�����žƺ����Ӽ���������ƺ����о�2���������߱߳���


    ���½����ߣ����ȥ��ơ�
    ����һ����������һ����


    ��һ·�ϣ���һ��������5�Σ�������10�Σ���֪���һ���������ǻ��������ðѾƺȹ��ˡ� 


    ����������������ͻ��Ĵ��򣬿��԰������Ϊa��������Ϊb����babaabbabbabbbb ���Ǻ���Ĵ����������Ĵ�һ���ж����أ������������п��ܷ����ĸ�����������Ŀ�����ģ���
*/
#include<iostream>
using namespace std;
int ans = 0;
void dfs(int store,int flower,int col,int pre)
{//pre��1��ʾ����0��ʾ�� 
	if(store == 5 && flower == 10)
	{
		if(col == 0 && pre == 1)
		ans++; 
	}
	if(store < 5)
	{
		dfs(store+1,flower,col*2,0);		
	}
	if(flower < 10)
	{
		dfs(store,flower+1,col-1,1);	
	}
}

int main()
{
	dfs(0,0,2,-1);
	cout << ans;
	return 0;
} 

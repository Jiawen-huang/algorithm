/*9.���⣺�ع�ȡ��


    X ������һ���ع����⡣�� n x m �����ӵľ���ÿ�����ӷ�һ��������ÿ���������ż�ֵ��ǩ��


    �ع�����������Ͻǣ����������½ǡ�


    С���������ع�����ڣ�����Ҫ����ֻ�����һ��������ߡ�


    �߹�ĳ������ʱ������Ǹ������еı�����ֵ��С���������ⱦ����ֵ����С���Ϳ�������������Ȼ��Ҳ���Բ��ã���


    ��С���ߵ�����ʱ����������еı���ǡ����k��������Щ�����Ϳ����͸�С����


    �����С����һ�㣬�ڸ����ľ����£����ж����ֲ�ͬ���ж������ܻ����k��������


�����ݸ�ʽ��


    ����һ��3���������ÿո�ֿ���n m k (1<=n,m<=50, 1<=k<=12)


    �������� n �����ݣ�ÿ���� m ������ Ci (0<=Ci<=12)������������ϵı���ļ�ֵ


    Ҫ�����һ����������ʾ����ȡk���������ж��������������ֿ��ܴܺ�������� 1000000007 ȡģ�Ľ����


���磬���룺
2 2 2
1 2
2 1
����Ӧ�������
2


�����磬���룺
2 3 2
1 2 3
2 1 5
����Ӧ�������
14




��ԴԼ����
��ֵ�ڴ����� < 256M
CPU����  < 1000ms




���ϸ�Ҫ���������Ҫ��������ش�ӡ���ƣ�����������...�� �Ķ������ݡ�


���д������ͬһ��Դ�ļ��У�����ͨ���󣬿����ύ��Դ�롣


ע��: main������Ҫ����0
ע��: ֻʹ��ANSI C/ANSI C++ ��׼����Ҫ���������ڱ��뻷�������ϵͳ�����⺯����
ע��: ���������ĺ���������ȷ����Դ�ļ��� #include <xxx>�� ����ͨ���������ö�ʡ�Գ���ͷ�ļ���


�ύʱ��ע��ѡ���������ı��������͡�
*/
//����һ����ͨ��DFS������
/* 
#include<iostream>
using namespace std;
int a[51][51];
int n,m,k;
long long ans;
void dfs(int x,int y,int num,int max)
{
	if(num > k)
	return;
	if(x==n-1 && y ==m-1)//�ߵ���� 
	{
		if( k == num || (num==k-1&&max<a[x][y]))
			ans++;
		return;
	}
	if(x < n-1)//������ 
	{
		if(a[x][y]>max)
			dfs(x+1,y,num+1,a[x][y]);
		dfs(x+1,y,num,max);		
	}
	if(y < m-1)//������ 
	{
		if(a[x][y] > max)
			dfs(x,y+1,num+1,a[x][y]);
		dfs(x,y+1,num,max);
	}
}
int main()
{
	
	cin >> n >> m >> k;
	for(int i = 0;i < n;i++)
	for(int j =0;j < m;j++)
	{
		cin >> a[i][j];
	}
	dfs(0,0,0,-1);
	cout << ans%1000000007 << endl;
	return 0;
} */
//�����������仰����

#include<iostream>
using namespace std;
#include<cstring>    
int n,m,k;    
int a[55][55][13][14];    
int map[55][55];    
int dfs(int x,int y,int pre,int max)    
{    
	if(a[x][y][pre][max+1]>=0)
		return a[x][y][pre][max+1];
	int sum=0;  
	if(x==n-1&&y==m-1)
	{
		if(pre==k||(pre==k-1&&max<map[x][y]))    
        {    
            sum++;    
            sum%=1000000007;    
        }    
        a[x][y][pre][max+1]=sum;    
        return a[x][y][pre][max+1];
	}
	
	if(x < n-1)
	{
		if(max < map[x][y])
		   sum += dfs(x+1,y,pre+1,map[x][y]);
		sum += dfs(x+1,y,pre,max);	
		sum%=1000000007; 
	} 
   	if(y < m-1)
   	{
   		if(max < map[x][y])
		   sum += dfs(x,y+1,pre+1,map[x][y]);
		sum += dfs(x,y+1,pre,max);
		sum%=1000000007; 	
	}
	a[x][y][pre][max+1]=sum%1000000007;    
    return a[x][y][pre][max+1]; 
}    

int main()
{
	while(cin>>n>>m>>k)    
    {    
        memset(a,-1,sizeof(a));    
        for(int i=0; i<n; i++)    
            for(int j=0; j<m; j++)    
                cin>>map[i][j];    
        dfs(0,0,0,-1);    
        cout<<a[0][0][0][0]%1000000007;    
    } 
	return 0;
 }
 /*
#include <iostream>  
#include <cmath>  
#include <cstdio>  
#include <cstring>  
using namespace std;  
#define N 1000000007  
  
int ans;  
int d[51][51][13][14];  
int p[51][51];  
int n,m,k;  
  
int dfs(int x,int y,int num,int maxvalue){  
    if(d[x][y][num][maxvalue + 1] != -1){  
        return d[x][y][num][maxvalue + 1];  
    }  
    int t = 0;  
    if(x == n-1 && y == m-1){  
        if(p[x][y] > maxvalue){  
            if(num == k || num == k-1)t++;  
        }  
        else if(num == k){  
            t ++;  
        }  
        d[x][y][num][maxvalue + 1] = t;
        return d[x][y][num][maxvalue + 1];  
    }  
  
    if(x + 1 < n){  
        if(p[x][y] > maxvalue){  
            t += dfs(x+1,y,num+1,p[x][y]);  
            t %= N;  
            t += dfs(x+1,y,num,maxvalue);  
            t %= N;  
        }  
        else {  
            t += dfs(x+1,y,num,maxvalue);  
            t %= N;  
        }  
    }  
  
    if(y + 1 < m){  
        if(p[x][y] > maxvalue){  
            t += dfs(x,y+1,num+1,p[x][y]);  
            t %= N;  
            t += dfs(x,y+1,num,maxvalue);  
            t %= N;  
        }  
        else {  
            t += dfs(x,y+1,num,maxvalue);  
            t %= N;  
        }  
    }  
    d[x][y][num][maxvalue + 1] = t;  
    return d[x][y][num][maxvalue + 1];  
}  
  
int main(){  
    while(cin>>n>>m>>k){  
        for(int i = 0; i < n; ++i){  
            for(int j = 0; j < m; ++j)  
            cin>>p[i][j];  
        }  
        memset(d,-1,sizeof(d));  
        dfs(0,0,0,-1);  
        cout<<d[0][0][0][0]<<endl;  
    }  
    return 0;  
} */

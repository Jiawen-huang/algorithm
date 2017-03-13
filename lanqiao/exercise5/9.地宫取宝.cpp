/*9.标题：地宫取宝


    X 国王有一个地宫宝库。是 n x m 个格子的矩阵。每个格子放一件宝贝。每个宝贝贴着价值标签。


    地宫的入口在左上角，出口在右下角。


    小明被带到地宫的入口，国王要求他只能向右或向下行走。


    走过某个格子时，如果那个格子中的宝贝价值比小明手中任意宝贝价值都大，小明就可以拿起它（当然，也可以不拿）。


    当小明走到出口时，如果他手中的宝贝恰好是k件，则这些宝贝就可以送给小明。


    请你帮小明算一算，在给定的局面下，他有多少种不同的行动方案能获得这k件宝贝。


【数据格式】


    输入一行3个整数，用空格分开：n m k (1<=n,m<=50, 1<=k<=12)


    接下来有 n 行数据，每行有 m 个整数 Ci (0<=Ci<=12)代表这个格子上的宝物的价值


    要求输出一个整数，表示正好取k个宝贝的行动方案数。该数字可能很大，输出它对 1000000007 取模的结果。


例如，输入：
2 2 2
1 2
2 1
程序应该输出：
2


再例如，输入：
2 3 2
1 2 3
2 1 5
程序应该输出：
14




资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms




请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。


所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。


注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。


提交时，注意选择所期望的编译器类型。
*/
//方法一：普通的DFS搜索。
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
	if(x==n-1 && y ==m-1)//走到最后 
	{
		if( k == num || (num==k-1&&max<a[x][y]))
			ans++;
		return;
	}
	if(x < n-1)//向右走 
	{
		if(a[x][y]>max)
			dfs(x+1,y,num+1,a[x][y]);
		dfs(x+1,y,num,max);		
	}
	if(y < m-1)//向下走 
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
//方法二：记忆话搜索

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

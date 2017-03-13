/*
移动距离

X星球居民小区的楼房全是一样的，并且按矩阵样式排列。其楼房的编号为1,2,3...
当排满一行时，从下一行相邻的楼往反方向排号。
比如：当小区排号宽度为6时，开始情形如下：

1  2  3  4  5  6
12 11 10 9  8  7
13 14 15 .....

我们的问题是：已知了两个楼号m和n，需要求出它们之间的最短移动距离（不能斜线方向移动）

输入为3个整数w m n，空格分开，都在1到10000范围内
w为排号宽度，m,n为待计算的楼号。
要求输出一个整数，表示m n 两楼间最短移动距离。

例如：
用户输入：
6 8 2
则，程序应该输出：
4

再例如：
用户输入：
4 7 20
则，程序应该输出：
5

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

#include<iostream>
#include<cmath> 
using namespace std;
int main()
{
	int count = 1;
	int w,m,n;
	cout << "用户输入："<<endl;
	cin >> w >>m >>n;
	int x1,x2,y1,y2;
	x1 = m / w ;
	x2 = m % w;
	y1 = n / w;
	y2 = n % w;
	if(x2 == 0) x2 = w;
	if(y2 == 0) y2 = w; 
	if( x1%2 )
	x2 = w - x2 +1;
	if( y1%2 )
	y2 = w -x2 +1;
	cout << abs(x1 - y1 )+abs(x2 -y2); 
	
	return 0;	
} /*
#include<stdio.h>  
#include<cmath>  
using namespace std;  
int main()  
{  
    int w,m,n;  
    scanf("%d%d%d",&w,&m,&n);  
    int x1,x2,y1,y2;  
    x1=(m-1)/w;  
    y1=(m-1)%w;  
    x2=(n-1)/w;  
    y2=(n-1)%w;  
    if(x1%2)  
        y1=w-y1-1;  
    if(x2%2)  
        y2=w-y2-1;  
    printf("%d\n",abs(x1-x2)+abs(y1-y2));  
    return 0;  
}*/

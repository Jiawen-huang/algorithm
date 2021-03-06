/*
8.标题：蚂蚁感冒


    长100厘米的细长直杆子上有n只蚂蚁。它们的头有的朝左，有的朝右。 


    每只蚂蚁都只能沿着杆子向前爬，速度是1厘米/秒。


    当两只蚂蚁碰面时，它们会同时掉头往相反的方向爬行。


    这些蚂蚁中，有1只蚂蚁感冒了。并且在和其它蚂蚁碰面时，会把感冒传染给碰到的蚂蚁。


    请你计算，当所有蚂蚁都爬离杆子时，有多少只蚂蚁患上了感冒。




【数据格式】


    第一行输入一个整数n (1 < n < 50), 表示蚂蚁的总数。接着的一行是n个用空格分开的整数 Xi (-100 < Xi < 100), Xi的绝对值，
	表示蚂蚁离开杆子左边端点的距离。正值表示头朝右，负值表示头朝左，数据中不会出现0值，也不会出现两只蚂蚁占用同一位置。其中，第一个数据代表的蚂蚁感冒了。 
    要求输出1个整数，表示最后感冒蚂蚁的数目。


例如，输入：
3
5 -2 8
程序应输出：
1


再例如，输入：
5
-10 8 -20 12 25
程序应输出：
3


资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms




请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。
 

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。


注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。


提交时，注意选择所期望的编译器类型。*/
/*
  这个题乍一看脑袋里好像很乱，其实理清头绪后再敲出来就很容易了。首先一定要记住蚂蚁都具有相同的速度，所以他们的相对位置不会变!
  我们可以从第一只那只感冒的蚂蚁入手，实际上，如果第一只蚂蚁向右爬，则它出发的位置右边的蚂蚁中向左爬且离第一只蚂蚁最近的那只会被传染，
  然后双方会掉头爬行，接下来，第一只蚂蚁左边的蚂蚁中向右爬行且离第一只蚂蚁最近的那只会被传染，双方再掉头。而对于一开始第一只被
  传染的那只蚂蚁来说，它会传染给他右边向左爬且最近的蚂蚁……
  所以，将问题简化，实际上就是向右爬的第一只感冒蚂蚁会先传染它右边所有向左爬的蚂蚁，掉头向左爬时会传染给左边所有向右爬的蚂蚁。
  同理，若第一只蚂蚁开始时是向左爬，被传染的蚂蚁=左边所有向右爬的蚂蚁+右边所有向左爬的蚂蚁。
  注意这种思想需要有个第一只感冒的蚂蚁是否会掉头的判断，因为第一只蚂蚁向左(或右)爬的时候，若不会遇到一只迎面而来的蚂蚁使它掉头的话，
  则即使右边有向左爬的蚂蚁，也不会被其传染。*/
#include<iostream>
using namespace std;
#include<algorithm>
#define MAX 1000 
int ans = 1;

struct ants
{
	int pos;//离初始点的距离 
	int dir;//方向 
	//int cx;
}Node[55];
bool cmp(ants a,ants b)
{
	return a.pos < b.pos;
}
int main()
{
	int n,orign;
	cin >> n;
	for(int i = 0;i < n ;i++)
	{
		cin >> orign;
		if(orign > 0)
		{
			Node[i].pos = orign;
			Node[i].dir = 1;
		}
		else
		{
			Node[i].pos = orign*(-1);
			Node[i].dir = -1;
		}
	}
	ants key;
	key.pos = Node[0].pos;
	key.dir = Node[0].dir;
	sort(Node,Node+n,cmp);
	int i;
	for(i =0;key.pos == Node[i].pos;i++);
	if(key.pos < 0)
	{
		for(int j = i-1;j>=0;j--)
		{
			if(Node[j].dir > 0)
			ans++;
		}
		if(ans > 1)
		for(int j = i+1;j<n;j++)
		{
			
			if(Node[j].dir < 0)
			ans++;
		}
	}
	if(key.pos > 0)
	{
		for(int j = i +1;j<n;j++)
		{
			if(Node[j].dir < 0)
			{ans++;
			}
		}
		if(ans > 1)
		for(int j = i -1;j >= 0;j--)
		{
			if(Node[j].dir > 0)
			ans++;
		}
	}
	cout << ans <<endl; 
	return 0;	
} 

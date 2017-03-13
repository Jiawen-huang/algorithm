/*题目标题: 第39级台阶


    小明刚刚看完电影《第39级台阶》，离开电影院的时候，他数了数礼堂前的台阶数，恰好是39级!


    站在台阶前，他突然又想着一个问题：


    如果我每一步只能迈上1个或2个台阶。先迈左脚，然后左右交替，最后一步是迈右脚，也就是说一共要走偶数步。
	那么，上完39级台阶，有多少种不同的上法呢？


    请你利用计算机的优势，帮助小明寻找答案。


要求提交的是一个整数。
注意：不要提交解答过程，或其它的辅助说明文字。
*/ 
#include<iostream>
using namespace std;
int ans = 0;
void dfs(int step,int once)
{
	if(step > 39) return;
	if(step == 39 && once%2 ==0)
		ans++;
	if(step < 39)
	{
		dfs(step + 1,once +1);
		dfs(step + 2,once +1);
	}
	
}
int main()
{
	dfs(0,0);
	cout << ans; 
	return 0;
}

#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int w,m,n;
	cin >> w>>m >>n;
	int x1,y1,x2,y2;
	y1 = m/w;
	y2 = n/w;
	if(y1%2)
	{
		x1 =w - (m-1) % w;
	}
	else
	{
		x1 = (m-1) % w +1;
	}
	if(y2%2)
	{
		x2 = w - (n-1)%w;
	}
	else
	{
		x2 = (n-1)%w +1;
	}
	cout << abs(x2-x1)+abs(y2-y1)<<endl;
}

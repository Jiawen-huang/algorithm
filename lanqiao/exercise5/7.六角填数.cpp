/*7.���⣺��������


    ��ͼ��1.png����ʾ�������У�����1~12�����֡�


    ʹ��ÿ��ֱ���ϵ�����֮�Ͷ���ͬ��


    ͼ�У��Ѿ����������3�����֣���������Ǻ�λ��������������Ƕ��٣�


��ͨ��������ύ�𰸣���Ҫ��д��������ݡ�
*/


//����һ������ 
/* 
#include<iostream>
using namespace std;
int main()
{
	for(int a= 1; a<= 12; a++)
	for(int b= 1; b<= 12;b++)
	for(int c= 1; c<= 12; c++)
	for(int d= 1; d<= 12;d++)
	for(int e= 1; e<= 12; e++)
	for(int f= 1; f<= 12; f++)
	for(int g= 1; g<= 12; g++)
	for(int h= 1; h<= 12; h++)
	for(int i= 1; i<= 12; i++)
	{
		if(a==1|| a==3|| a==8|| b==1|| b==3|| b==8||
		c==1||c==3||c ==8||d==1||d==3||d==8||
		e==1||e==3||e==8||f==1||f==3||f==8||
		g==1||g==3||g==8||h==1||h==3||h==8||
		i==1||i==3||i==8)  
                                            continue;  
		if(a!=b && a!=c && a!=d && a!=e && a!=f && a!=g && a!=h && a!=i
		&& b!=c && b!=d && b!=e && b!=f && b!=g && b!=h && b!=i
		&& c!=d && c!=e && c!=f && c!=g && c!=h && c!=i
		&& d!=e && d!=f && d!=g && d!=h && d!=i
		&& e!=f && e!=g && e!=h && e!=i
		&& f!=g && f!=h && f!=i
		&& g!=h && g!=i
		&& h!=i 
		&& 8+a+b+c == 8+i+f+3 && 8+a+b+c == c+d+g+3 && 8+a+b+c == 1+a+i+e && 8+a+b+c ==e+f+g+h && 8+a+b+c ==1+b+d+h)
		{
			cout << i <<endl;
		}
	}
	return 0;
}*/

//������ �������Ż�
/*�ڶ��ݴ���ĺô����ڼ����ж������������ж�9������������ȵ�ʱ�򲻱�����8!������ʽ��Ҫ�жϣ�
ֻҪ��֤��ǰforѭ���еı�����֮ǰ�������ȼ��ɡ����ж����������ֺ����ʱ������д��5!����ʽ���жϣ�
ֻ��������������ȼ��ɡ�*/ 
/* 
#include<iostream>
using namespace std;
int main()
{
	for(int a= 1; a<= 12; a++)
	{
		if(a==1|| a==3|| a==8)
		continue;
		for(int b= 1; b<= 12;b++)
		{
			if(b == a|| b==1|| b==3|| b==8) 
			continue;
			for(int c= 1; c<= 12; c++)
			{
				if(c == a || c == b||c==1||c==3||c ==8) 
				continue;
				for(int d= 1; d<= 12;d++)
				{
					if(d == a || d == c || d== b||d==1||d==3||d==8) 
					continue;
					for(int e= 1; e<= 12; e++)
					{
						if(e == a || e == c || e==d|| e== b||e==1||e==3||e==8) 
						continue;
						for(int f= 1; f<= 12; f++)
						{
							if(f == a || f == c || f==d|| f == e|| f == b||f==1||f==3||f==8) 
							continue;
							for(int g= 1; g<= 12; g++)
							{
								if(g == a || g == c || g==d|| g == e|| g==f||g == b||g==1||g==3||g==8) 
								continue;
								for(int h= 1; h<= 12; h++)
								{
									if(h == a || h == c || h==d||h == e|| h==f|| h==g||h == b||h==1||h==3||h==8) 
									continue;
									for(int i= 1; i<= 12; i++)
									{
										if(i == a || i == c || i==d||i == e|| i==f|| i==g|| i==h||i == b||i==1||i==3||i==8) 
										continue;
											if(	8+a+b+c == 8+i+f+3 && 8+a+b+c == c+d+g+3 && 8+a+b+c == 1+a+i+e 
												&& 8+a+b+c ==e+f+g+h && 8+a+b+c ==1+b+d+h)
											{
												cout << i <<endl;
											}
									}				
								}
							}
						}
					}
				}	
			}
		}
	}

	return 0;
}*/
//����������stl��next_permutation ����
#include "cstdio"  
#include "cstring"  
#include "iostream"  
#include <algorithm>  
using namespace std;  
  
int main (){  
    int a[13];  
    for(int i=0;i<12;++i)  
        a[i]=i+1;  
    while(next_permutation(a,a+12)){  
        int t=a[1]+a[2]+a[3]+a[4];  
        if(a[0]==1 && a[1]==8 && a[11]==3 && t==a[0]+a[2]+a[5]+a[7] && t==a[0]+a[3]+a[6]+a[10] && t==a[7]+a[8]+a[9]+a[10] &&  
           (a[1]+a[5]+a[8]+a[11])==(a[4]+a[6]+a[9]+a[11]))  
            printf("%d\n",a[5]);  
    }  
    return 0;  
}  

 
//�����ģ�dfs
//ע��i=0,i=1; 
/*
#include<iostream>
using namespace std;
int ans = 0;
int num[9] = {2,4,5,6,7,9,10,11,12};//��ʣ����Ÿ���  
int a[9];
int visit[9] = {0};
void solve()
{
	int t1 = 8+a[1]+a[2]+a[3],
	t2 = 8+ a[9]+a[6]+3,
	t3 = a[3]+a[4]+a[7]+3,
	t4 = 1+a[1]+a[9]+a[5],
	t5 = 1+ a[2] +a[4]+a[8],
	t6 = a[5]+a[6]+a[7]+a[8];
	if(t1 == t2 && t2 == t3 && t3 == t4 && t4 == t5 &&t5 == t6)
	{
			cout << a[9]<<endl;
	}
}
void dfs(int index)
{
	if(index == 10)
	{
		solve();
		return;
	}
	for(int i = 0;i <9;i++)
	{
		if(!visit[i])
		{
			visit[i] = 1;
			a[index] = num[i];
			dfs(index + 1);
			visit[i] = 0; 
		}
	}
}
int main()
{
	dfs(1);
	return 0;
 } */

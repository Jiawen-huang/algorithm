#include<stdio.h>  
int main()  
{  
    int a,s,d,f,g,h,j,k;  
    for(a=1; a<=9; a++)  
        for(s=0; s<=9; s++)  
            for(d=0; d<=9; d++)  
                for(f=1; f<=9; f++)  
                    for(g=0; g<=9; g++)  
                        for(h=0; h<=9; h++)  
                            for(j=0; j<=9; j++)  
                                for(k=0; k<=9; k++)  
                                    if((1000*g+100*f+10*h+j+1000*a+100*s+10*d+f==10000*a+
									1000*s+100*h+10*f+k)&&(a!=s)&&(a!=d)&&(a!=f)&&(a!=g)
									&&(a!=h)&&(a!=j)&&(a!=k)&&(s!=d)&&(s!=f)&&(s!=g)&&(s!=h)
									&&(s!=j)&&(s!=k)&&(d!=f)&&(d!=g)&&(d!=h)&&(d!=j)&&(d!=k)
									&&(f!=g)&&(f!=h)&&(f!=j)&&(f!=k)&&(g!=h)&&(g!=j)&&(g!=k)
									&&(h!=j)&&(h!=k)&&(j!=k)&&(h!=j)&&(h!=k)&&(j!=k))  
                                        printf("%d %d %d %d\n",a,s,d,f);  
    return 0;  
}  

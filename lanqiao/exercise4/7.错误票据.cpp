/*��������
ĳ���ܵ�λ�·���ĳ��Ʊ�ݣ���Ҫ������ȫ���ջء�

ÿ��Ʊ����Ψһ��ID�š�ȫ������Ʊ�ݵ�ID���������ģ���ID�Ŀ�ʼ���������ѡ���ġ�

��Ϊ������Ա�������¼��ID�ŵ�ʱ������һ�����������ĳ��ID�Ϻţ�����һ��ID�غš�

���������ͨ����̣��ҳ��Ϻŵ�ID���غŵ�ID��

����ϺŲ����ܷ�����������С�š�

�����ʽ
Ҫ�������������һ������N(N<100)��ʾ��������������

���Ŷ���N�����ݡ�

ÿ�����ݳ��Ȳ��ȣ����ÿո�ֿ������ɸ���������100������������������100000����
��ע�����ں���ĩ�����ж���Ŀո���ĳ�����Ҫ�ܴ�����Щ�ո�

ÿ����������һ��ID�š�

�����ʽ
Ҫ��������1�У�����������m n���ÿո�ָ���

���У�m��ʾ�Ϻ�ID��n��ʾ�غ�ID

��������1
2
5 6 8 11 9 
10 12 9
�������1
7 9
��������2
6
164 178 108 109 180 155 141 159 104 182 179 118 137 184 115 124 125 129 168 196
172 189 127 107 112 192 103 131 133 169 158 
128 102 110 148 139 157 140 195 197
185 152 135 106 123 173 122 136 174 191 145 116 151 143 175 120 161 134 162 190
149 138 142 146 199 126 165 156 153 193 144 166 170 121 171 132 101 194 187 188
113 130 176 154 177 120 117 150 114 183 186 181 100 163 160 167 147 198 111 119
�������2
105 120*/
#include<iostream>
using namespace std;
#include<algorithm>
int main()
{
	int a[100000];
	int n,num = 0;
	int first,second;
	cin >> n;
	while(cin >> a[num])
	{
		num ++;
	}
	sort(a,a+num);
	for(int i = 0;i<num;i++)
	{
	//	cout<<a[i];
		if(a[i+1] - a[i] == 2)
		second = a[i + 1]-1;
		if(a[i+1] - a[i] == 0)
		first = a[i];
	}
	cout << second<<" "<<first;
	return 0;
} 
/*#include <iostream>  
#include <cstdio>  
#include <vector>  
#include <algorithm>  
using namespace std;  
void print(int x) {  
    cout << x << " ";  
}  
int main(void) {  
    vector<int> v;  
    getchar();  
    int tmp;  
    //while(scanf("%d", &tmp) == 1) {  
    while(cin >> tmp) {  
        v.push_back(tmp);  
    }  
    sort(v.begin(), v.end());  
    int m = 0;  
    int n = 0;  
    for(vector<int>::iterator iv = v.begin(); iv != v.end(); iv++) {  
        int tmp = *(iv + 1) - *iv;  
        if(tmp == 2) {  
            //duanhao  
            m = *iv + 1;  
        }  
        if(tmp == 0) {  
            //chonghao  
            n = *iv;  
        }  
        if(m != 0 && n != 0) {  
            break;  
        }  
    }  
    cout << m << " " << n << endl;  
    return 0;  
}  */

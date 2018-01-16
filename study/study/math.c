#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
int main(){
	system("color bf");
	//1.设置随机种子，一般跟时间联用，因为时间每时每刻都是不同的
	srand(123);
	//srand(time(NULL));
	//2.取随机数
	int num=rand();
	printf("%d\n",num);
	
	/*
	printf("%d\n",isupper('a'));
	printf("%d\n",islower('a'));
	printf("%d\n",isalpha(97));
	//如果传入的是数字，表示的是ascii码
	printf("%d\n",isdigit(50));
	printf("50对应的字符：%c\n",50);
	//打印所有的ascii码对应的字符
	
	int i;
	for(i=0;i<127;i++){
	printf("%c ",i);
	}
	printf("大写,%c\n",toupper('b'));
	*/
	printf("%.2lf\n",ceil(5.2));
	printf("%.2lf\n",floor(5.9));
}

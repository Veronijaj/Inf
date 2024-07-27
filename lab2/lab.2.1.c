#include <stdio.h>
#include <math.h>
float solve(float x,int n){
	int i=0;
	float k=x;
	float summ=0;
	while (i<n){
		summ+=x;
		x=k*(2*i+1)*(2*i+1)*(2*i+2)*k*x/(4*(i+1)*(i+1)*(2*i+3));
		i++;
	}
	return summ;
}

int main(){
	float x;
	int n;
	float summ;
	printf("Введите значение x:");
	while ((scanf("%f",&x)!=1)||(x<-1)||(x>1)){
		scanf("%*c");
		printf("Ошибка. Неверное значение X\n");
	}
	printf("Введите значение n:");
	while ((scanf("%d",&n)!=1)||(n<1)){
		scanf("%*c");
		printf("Ошибка. Неверное значение n");
	}
	summ=solve(x,n);
	float pi=3.1415926;
	summ=pi/2-summ;
	printf("arccos(x)=%15f",summ);
	return 0;
}


#include <math.h>
#include <stdio.h>
float solve(float x,float e){
	int i=0;
	float t=10;
	float k=x;
	float summ=0;
	while (fabs(t-x)>=e){
		t=x;
		summ+=x;
		x=k*(2*i+1)*(2*i+1)*(2*i+2)*k*x/(4*(i+1)*(i+1)*(2*i+3));
		i++;
	}
	printf("%d\n",i+1);
	return summ;
}

int main(){
	float x;
	float e;
	float summ;
	printf("Введите значение x:");
	while ((scanf("%f",&x)!=1)||(x<-1)||(x>1)){
		scanf("%*c");
		printf("Ошибка. Неверное значение X\n");
	}
	printf("Введите точность:");
	while ((scanf("%f",&e)!=1)||(e>=1)){
		scanf("%*c");
		printf("Ошибка. Неверное значение n\n");
	}
//	printf("%f\n",acos(x));
	summ=solve(x,e);
	float pi=3.1415926;
	summ=pi/2-summ;
	printf("arccos(x)=%15f\n",summ);
	return 0;
}


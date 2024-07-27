#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab.h"
int main(){
    char* string;
    char* newstring;
    int len=0, a, k=1;
    while(k==1){
    	double time_total=0;
    	clock_t begin=clock();
		string=getstr(&len,&k);
		if(k==0)break;
		if(k==1){
			printf("%s\n",string);
			newstring=mystr(string,&len);
			printf("%s\n",newstring);}
		clock_t end=clock();
		time_total+=(double)(end-begin)/CLOCKS_PER_SEC;
		printf("За %f секунд совершается программа\n", time_total);
		free(string);
		free(newstring);
		fflush(stdin);
		scanf("%*c");}
    return 0;} 

#include <stdio.h>
int main(){
	int n=0,flag=0;
	scanf("%d",&n);
	for (int i=1;i<(n+1);i++){
		for(int k=2;k<i;k++){
			if (i%k==0){
				flag++;				
			}
		}
		if (flag==0){
			printf("%d\n",i);
		}
		flag=0;
	}	
	return 0;	
}

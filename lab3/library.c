#include "laba.h"
int *arr_input(int *len){ //инициализация массива
	int *arr;
	arr=(int*)malloc(*len * sizeof(int*));
	printf("Введите значения элементов массива:\n");
	for(int k=0;k<*len;k++){
		printf("arr[%d]=",k);
		while((scanf("%d",(arr+k)))!=1||(*(arr+k)<=MIN)){
			scanf("%*c");
			printf("Некорректно введено значение элемента\n");
		};
	}
	return arr;
}

int* memory(int* new_arr, int *n, int i){
		if (i+1==*n){
			*n*=2;	
			new_arr=(int*)realloc(new_arr,*n*sizeof(int*));
		}	 
		if (i+1<(*n/2)){
			*n/=2;
			new_arr=(int*)realloc(new_arr,*n*sizeof(int*));
		}	 
		return new_arr;
}

int* delete_number(int* arr, int* len, int j){ //удаление элемента по индексу
	int q=0;
	*len=*len-1;
	for(int i=0;i<=*len;i++){          
		if (i==j)i++;                 
		arr[q]=arr[i];
		q++;
		arr=memory(arr, len, q);                
	}
	return arr;
}

int* add_number(int* arr, int* len){ //вставка элемента по индексу
	int k,j;
	printf("Укажите индекс элемента, куда хотите вставить число: ");
						scanf("%d",&j);
	printf("Напишите, пожалуйста, число, которое хотите вставить по указанному индексу: ");
	while((scanf("%d",&k)!=1)||(k<=MIN)){
		scanf("%*c");
		printf("Некоррекктно введён индекс элемента\n");
	}
	int q=*len;
	*len=*len+1;
	if (j>=(*len-1)) arr[*len-1]=k;
	else{
		while (q>j){
			*(arr+q)=*(arr+q-1);
			q--;
		}
		arr[j]=k;
	}
	return arr;
}



int *create_arr(int* len, int* arr){
	printf("Введите количество элементов в массиве: ");
	while ((scanf("%d",len)!=1)||(*len<=MIN)){
		scanf("%*c");
		printf("Некоррекктно введено значение количества элементов, повторите, пожалуйста\n");
	}
	arr=arr_input(len);
	return arr;
}

int *print_arr(int* len, int* arr){
	printf("arr={");
	for (int i=0; i<*len; i++) printf("%d, ",arr[i]);
	printf("}\n");
}

int* find_increasing_numbers(int** arr, int* n, int* len){
	*n=*len;
	int* pump=(int*)malloc(*len*sizeof(int));
	int* new_arr=(int*)malloc(*n*sizeof(int));
	int i=0, y=0,s=*n,l=*n;
	for(int k=0;k<s;k++){
		int enumeration=(*arr)[k];
		int t=0;
		while(enumeration>9){
			int psl1=enumeration%10;
			enumeration/=10;
			int psl2=enumeration%10;
			if(psl1<=psl2)t=1;
		}
		if (t==0){
			new_arr[i]=(*arr)[k];
			new_arr=memory(new_arr,n,i);
			i++;
		
		}
		if (t==1 ){
			pump[y]=(*arr)[k];
			pump=memory(pump,&l,y);
			y++;
		}
	}
	(*arr)=pump;
	*len=y;
	(*arr)=realloc((*arr),*len*sizeof(int));
	printf("new_arr=[");
	for (int k=0; k<i; k++) printf("%d, ",new_arr[k]);
	printf("]\n");
	return new_arr;		
}

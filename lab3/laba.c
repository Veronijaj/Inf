#include "laba.h"

int main(){
	int len, f=1, a,j, b, n=5;
	int* arr;
	int* new_arr;
	while (f==1){
		printf("Выберите команду:\n");
		printf("0 - Завершить работу программы\n");
		printf("1 - Создать и инициализировать массив\n");
		printf("2 - Вывести текущее состояние массива\n");
		printf("3 - Вставить новый элементв в массив по индексу\n");
		printf("4 - Удалить элемент массива по индексу\n");
		printf("5 - Сформировать массив из чисел первоначального массива, цифры в записи которых расположенный строго по возрастанию при чтении слева направо и отчистить первоначальный массив\n");	
		b=scanf("%d",&a);
		if (b==1){
			switch (a){
				case 1:
				arr=create_arr(&len,arr);
				break;
				
				case 0:
				f=0;
				break;
				
				case 5:
				new_arr=find_increasing_numbers(&arr,&n,&len);
				break;
				
				case 2:
				arr=print_arr(&len, arr);
				break;

				case 3:
				add_number(arr,&len);

				break;

				case 4:
				printf("Укажите индекс элемента, который хотите удалить: ");
				scanf("%d",&j);
				arr=delete_number(arr,&len,j);
				break;			
			}			
		}
	} 

	return 0;
}

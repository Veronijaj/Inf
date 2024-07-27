#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lists{
    char data;
    struct lists* next; 
} lists;

lists* create(char k){
    lists* arr =(lists*)malloc(sizeof(lists));
    arr->data= k;
    arr->next=NULL;
    return arr;
    }

lists* push(lists* arr,char k){
    lists* tmp= arr;
    lists* new_el = create(k);
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=new_el;
    //*arr=new_el;
}
lists* del_vowels(lists* arr){
    for (lists* p = arr; p != NULL; p=p->next) {
        if (p->data == 'a' || p->data == 'e' || p->data == 'i' || p->data == 'o' ||p->data == 'u' ||p->data == 'y') {
            if (p == arr){
                //free(p);
                arr=arr->next;
            } 
            else{
            lists *temp = arr;
            while (temp->next != p) temp = temp->next;
            temp->next = p->next; }
           // free(temp); 
        }
    }
    /*while((*arr)!=NULL){
        printf("%c", (*arr)->data);
        *arr=(*arr)->next;
    }*/
    return arr;
}
int main(){
    int t=1;
    while(t=1){
    	printf("Enter a string\n");
        char a=getchar();
        if(a==-1){
            t=0;
            break;}
       // fflush(stdin);
        lists* listochek =create(a);
        a=getchar();
        if(a==-1){
            t=0;
            break;}
        while(a!='\n'&& a!=-1){
            listochek=push(listochek,a);
            a=getchar();
            if(a==-1){
                t=0;
                break;}
            //fflush(stdin);

        }
        listochek=del_vowels(listochek);
        printf("\"");
        while(listochek!=NULL){
            printf("%c", listochek->data);
            listochek=listochek->next;
        }
        printf("\"\n");
        fflush(stdin);
    }
//    listok=clean_memory(&listok);
    return 0;
}

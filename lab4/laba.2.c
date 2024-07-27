#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
char* getstr();
char* mystr(const char* str, int* len);
char* delete_rubbish(char* stroka, int* dlina);

char* delete_rubbish(char* stroka, int* dlina){
        int k=*dlina;
        for(int i=0;i<*dlina;i++){
                if((stroka[i]==' ')&&(stroka[i+1]==' ')){
                        k--;
                        for(int p=i;p<k;p++){
                                stroka[p]=stroka[p+1];
                                i--;}
                }
        }
        *dlina=k;
        return stroka;}

char* getstr(int*len,int* k){
    char* str=NULL;
    str=readline("Введите строку:\n");
    *len=0;
    if(str==NULL){
        scanf("%*c");
        *k=0;
    }if (str>0){
        add_history(str);
        *len += strlen(str);
	    str=delete_rubbish(str,len);
	    if(*len>0)str[*len]='\0';}
	fflush(stdin);
    return str;}

char* mystr(const char* str, int* len){
    char* newstr=calloc(*len,sizeof(char));
    int n, m, k=0, newlen=*len,count=0, f=1;
    printf("Введите номер слова, которое хотите удалить: ");
    scanf("%d",&n);
    printf("Введите номер слова которое хотите продублировать: ");
    scanf("%d",&m);
    int y=m,u=n;
    for (int i=0;i<*len;i++){
                int p=i;
                if ((str[i]==' ')&&(i<*len)){
                        count++;
                        f=1;}
                if (((count+1)==m)&&(m!=n)&&(f==1)){
                        newstr[k]=str[p];
                        p++;
                        k++;
                        while((str[p]!=' ')&&(p<*len)){
                                newlen++;
                                newstr=(char*)realloc(newstr,newlen);
                                newstr[k]=str[p];
                                k++;
                                p++;}
                        f=0;}
                if((count+1)!=n){
                        newstr[k]=str[i];
                        k++;}
                if(((count+1)==n)&&(str[i+1]==' '))n+=u;
                if(((count+1)==m)&&(str[i+1]==' '))m+=y;}
    newstr=(char*)realloc(newstr,(k+1)*sizeof(char));
    if(k>0)newstr[k]='\0';
    return newstr;}

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

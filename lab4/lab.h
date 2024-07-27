#include <stdio.h>
#include <stdlib.h>
int find_len(const char* hahaha);
char* getstr();
char* mystr(const char* str, int* len);
char* mcp(char* base, char* temporary, int* base_len);
char* delete_rubbish(char* stroka, int* dlina);
int find_len(const char* hahaha){
    int k=hahaha[0];
    int i=0;
    while(k!=0){
        k=hahaha[i];
        i++;}
    return i-1;}

char* delete_rubbish(char* stroka, int* dlina){
        int k=*dlina;
        for(int i=0;i<*dlina;i++){
        		if(stroka[i]=='\t')stroka[i]=' ';
                if((stroka[i]==' ')&&(stroka[i+1]==' ')){
                        k--;
                        for(int p=i;p<k;p++){
                                stroka[p]=stroka[p+1];
                                i--;}
                       // stroka=(char*)realloc(stroka,k+1);
                }
        }
        stroka=(char*)realloc(stroka,k+2);
        *dlina=k+2;
        stroka[*dlina-2]=' ';
        stroka[*dlina-1]='\0';
        return stroka;}

char* getstr(int*len,int* k){
    char* str=NULL;
    char buf[81]={0};
    int n;
    *len=0;
    printf("Введите строку\n");
    do{
        n=scanf("%80[^\n]",buf);
        if(n<0){
                *k=0;
            free(str);
            str=NULL;
            continue;
        }if(n==0){
            scanf("%*c");
        }if (n>0){
			int buf_len=find_len(buf);
            int str_len=*len+buf_len;
            str=(char*)realloc(str,str_len+1);
            str=mcp(str,buf,len);
            *len=str_len;}
    }while(n>0);
    if(*len>0){
    	str[*len]='\0';
        str=delete_rubbish(str,len);}
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
                        while((str[p]!=' ')&&(p<*len)||(p==*len)){
                                newlen++;
                               newstr=(char*)realloc(newstr,newlen);
                                newstr[k]=str[p];
                                k++;
                                p++;}
                        newstr[k]=str[p];
                        k++;
                        f=0;}
                if((count+1)!=n){
                        newstr[k]=str[i];
                        k++;}
                if(((count+1)==n)&&(str[i+1]==' '))n+=u;
                if(((count+1)==m)&&(str[i+1]==' '))m+=y;}
    newstr=delete_rubbish(newstr,&k);
    newstr=(char*)realloc(newstr,(k+1)*sizeof(char));
    if(k>0)newstr[k]='\0';
    fflush(stdin);
    return newstr;}

char* mcp(char* base, char* temporary, int* base_len){
    int i=1;
    base[*base_len]=*temporary;
    while(*temporary!='\0'){
        base[*base_len+i]=*(++temporary);
        i++;}
    return base;}
 

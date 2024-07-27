#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
typedef struct {
  char name[100];
  char number[12];
  long long int time;
}data;
int  getopt(int  argc, char* const  argv[], const  char* optstring);
extern char *optarg;
extern int optind, opterr, optopt;
int save(char* fn, data* people, int k);
data* load(char* fn, data* people, int* k);
data* gnomisort(data* people, int count,int a,int c);
data* pairsort(data* people, int count, int a, int c);
int compikname1(const void *p, const void *q);
int compiknumber1(const void *p, const void *q);
int compiktime1(const void *p, const void *q);
int compikname2(const void *p, const void *q);
int compiknumber2(const void *p, const void *q);
int compiktime2(const void *p, const void *q);

int save(char* fn, data* people, int k){
    FILE *file2 = fopen(fn, "w"); 
    if (file2 == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    int write, i=0;
    do {
        write = fprintf(file2,
                  "%s,%s,%lld\n",
                  people[i].name, 
                  people[i].number,
                  &people[i].time); 
        i++;
        if (write <=0) {
            printf("File format incorrect.\n");
            return 1;
        }
        if (ferror(file2)) {
            printf("Error reading file.\n");
            return 1;
        }
    } while (i<k);
    fclose(file2);
}

data* load(char* fn, data* people, int* k){//загружает информацию с файла в структурный массив
    FILE *file;
    file = fopen(fn, "r"); 
    if (file == NULL) {
        printf("Error opening file.\n");
        return people;
    }
    int read, count= 0;
    do {
        read = fscanf(file,
                  "%99[^,],%24[^,],%lld\n",
                  people[count].name, 
                  people[count].number,
                  &people[count].time); 
        if (read == 3) count++;
        if (read != 3 && !feof(file)) {
            printf("File format incorrect.\n");
            return people;
        }
        if (ferror(file)) {
            printf("Error reading file.\n");
            return people;
        }
    } while (!feof(file));
    fclose(file);
    printf("%d people counted.\n", count);
    for (int i = 0; i<count; i++)printf("%s %s %lld\n", people[i].name, people[i].number, people[i].time);
    printf("\n");
    *k=count;
    return people;
}

data* gnomisort(data* people, int count, int a, int c){
    int i = 1,j=2; // счётчик
    data tmp;
    while (i < count){
        if (((strcmp(people[i-1].name, people[i].name)<=0 && c==2 || strcmp(people[i-1].name, people[i].name)>0 && c==1) && a==1)||
           ((strcmp(people[i-1].number, people[i].number)>=0 && c==2 || strcmp(people[i].number, people[i-1].number)>0 && c==1 ) && a==2)||
           (((people[i-1].time>people[i].time && c==2) || (people[i-1].time<people[i].time && c==1)) && a==3)) {
            i=j;
            j++; 
        }
        else {
            tmp = people[i];
            people[i] = people[i-1];
            people[i-1] = tmp;
            i--;
            if(i==0){
                i=j;
                j++;
            }
        }
	}
    for (int i = 0; i<count; i++) printf("%s %s %lld\n", people[i].name, people[i].number, people[i].time);
    return people;
}  

data* pairsort(data* people, int count, int a, int c){
    int location;
    data newElement;
    for (int i = 1; i < count; i++){
        newElement = people[i];
        location = i - 1;
        while(location >= 0 && 
             (((strcmp(people[location].name, newElement.name)>0 && c==2 || strcmp(people[location].name, newElement.name)<=0 && c==1) && a==1)||
             (((strcmp(people[location].number, newElement.number)<0 && c==2 || strcmp(people[location].number, newElement.number)>=0 && c==1) && a==2))||
             (((people[location].time<newElement.time && c==2 || people[location].time>newElement.time && c==1) && a==3)))) {
            people[location+1] = people[location];
            location = location - 1;
        }
        people[location+1] = newElement;
    }
    for (int i = 0; i<count; i++) printf("%s %s %lld\n", people[i].name, people[i].number, people[i].time);
    return people;
}

int compikname1(const void *p, const void *q) {
    int l = strcmp(((data* )p)->name,((data* )q)->name); 
    return l;
}
int compiknumber1(const void *p, const void *q) {
    int l = strcmp(((data* )q)->number,((data* )p)->number); 
    return l;
}
int compiktime1(const void *p, const void *q) {
    int l = ((data* )q)->time > ((data* )p)->time - (((data* )q)->time < ((data* )p)->time) ; 
    return l;
}
int compikname2(const void *p, const void *q) {
    int l = (-1)*strcmp(((data* )p)->name,((data* )q)->name); 
    return l;
}
int compiknumber2(const void *p, const void *q) {
    int l = (-1)*strcmp(((data* )q)->number,((data* )p)->number); 
    return l;
}
int compiktime2(const void *p, const void *q) {
    int l = (-1)*(((data* )q)->time > ((data* )p)->time - (((data* )q)->time < ((data* )p)->time)) ; 
    return l;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
typedef struct {
  char name[21];
  char number[12];
  long long int time;
}data;
int  getopt(int  argc, char* const  argv[], const  char* optstring);
extern char *optarg;
extern int optind, opterr, optopt;
data* fill_in(data* people, int t);
data* gnomisort(data* people, int count,int a,int c);
data* pairsort(data* people, int count, int a, int c);
int comparator1(const void *p, const void *q);
int comparator2(const void *p, const void *q);
int comparator3(const void *p, const void *q);
int comparator4(const void *p, const void *q);
int comparator5(const void *p, const void *q);
int comparator6(const void *p, const void *q);
int main(int argc,char** argv){
    int a, b, c, opt=0;
    char* k=NULL;
    char* m=NULL;
    while((opt = getopt(argc, argv, "o:h:")) != -1){
        switch(opt){
            case 'o':
                k=optarg;
                break;
            case 'h':
                m=optarg;
                break;
            case '?':
                printf("unknown option: %c\n", optopt);
                break;
        }
    }
    int t=(int)k[0]-48;
    int r=(int)m[0]-48;
    data people[t+1];
    data * ludi = (data*)malloc (t*sizeof(int));
    printf("Choose the kind of sort:\n 1 - Gnome sort\n 2 - Pair insertion sort\n 3 - Function qsort\n");
    while(scanf("%d",&b)<=0 || b<0 || b>3){
        printf("Try entering option again\n");
        scanf("%*c");
    }
    fflush(stdin);
    printf("Choose the parametr of sort:\n 1 - Sort by name\n 2 - Sort by number\n 3 - Sort by time of last call\n");
    while(scanf("%d",&a)<=0 || a<0 || a>3){
        printf("Try entering option again\n");
        scanf("%*c");
    }
    fflush(stdin);
    printf("Choose the direction of sort:\n 1 - Ascending\n 2 - Descending\n");
    while(scanf("%d",&c)<=0 || c<0 || c>2){
        printf("Try entering option again\n");
        scanf("%*c");
    }
    double time_total=0;
    clock_t begin=0;
    clock_t end=0;
    int q=r;
    while(r){
        ludi=fill_in(people,t);
        switch (b){
        case 1:
        	begin=clock();
            ludi=gnomisort(ludi,t,a,c);
	        end=clock();
            break;
        case 2:
        	begin=clock();
            ludi=pairsort(ludi,t,a,c);
            end=clock();
            break;
        case 3:
            printf(" Final list:\n");
            begin=clock();
            if(a==1 && c==2)qsort ( ludi, t, sizeof(data) , comparator1 );
            if(a==1 && c==1)qsort ( ludi, t, sizeof(data) , comparator4 );
            if(a==2 && c==2)qsort ( ludi, t, sizeof(data) , comparator2 );
            if(a==2 && c==1)qsort ( ludi, t, sizeof(data) , comparator5 );
            if(a==3 && c==2)qsort ( ludi, t, sizeof(data) , comparator3 );
            if(a==3 && c==1)qsort ( ludi, t, sizeof(data) , comparator3 );
            end=clock();
            for (int i = 0; i<t; i++) printf("%s %s %lld\n", ludi[i].name, ludi[i].number, ludi[i].time);
            break;
    
        }
        r--;
        time_total+=(double)(end-begin)/CLOCKS_PER_SEC;
 
    }
   // printf("%d",r);
    time_total/=q;
    printf(" %lf second program was in process\n", time_total);
    return 0;
}
data* fill_in(data* people, int t){
    for(int j=0;j<t;j++){
        for(int i=0;i<20;i++) people[j].name[i]=rand()%26 + 'a';
        people[j].name[20]='\0';
        for(int l=0;l<11;l++) people[j].number[l]=rand()%9 +'0';
        people[j].number[11]='\0';
        people[j].time=rand()%9999999999;
    }
    printf(" Initial list:\n");
    for (int i = 0; i<t; i++) printf("%s %s %lld\n", people[i].name, people[i].number, people[i].time);
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
    printf(" Final list:\n");
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
    printf(" Final list:\n");
    for (int i = 0; i<count; i++) printf("%s %s %lld\n", people[i].name, people[i].number, people[i].time);
    return people;
}

int comparator1(const void *p, const void *q) {
    int l = strcmp(((data* )p)->name,((data* )q)->name); 
    return l;
}
int comparator2(const void *p, const void *q) {
    int l = strcmp(((data* )q)->number,((data* )p)->number); 
    return l;
}
int comparator3(const void *p, const void *q) {
    int l = ((data* )q)->time > ((data* )p)->time - (((data* )q)->time < ((data* )p)->time) ; 
    return l;
}
int comparator4(const void *p, const void *q) {
    int l = (-1)*strcmp(((data* )p)->name,((data* )q)->name); 
    return l;
}
int comparator5(const void *p, const void *q) {
    int l = (-1)*strcmp(((data* )q)->number,((data* )p)->number); 
    return l;
}
int comparator6(const void *p, const void *q) {
    int l = (-1)*(((data* )q)->time > ((data* )p)->time - (((data* )q)->time < ((data* )p)->time)) ; 
    return l;
}


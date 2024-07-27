
#include "mybiba.h"
int main(int argc,char** argv){
    int a, b, c, count=0, opt=0;
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
    data people[150];
    data* ludi=(data*)malloc(30*sizeof(data));
    char* filename=k;
    ludi=load(filename, people, &count);
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
    //fflush(stdin);
    switch (b){
    case 1:
        ludi=gnomisort(ludi,count,a,c);
        break;
    case 2:
        ludi=pairsort(ludi,count,a,c);
        break;
    case 3:
        if(a==1 && c==2)qsort ( ludi, count, sizeof(data) , compikname1 );
        if(a==1 && c==1)qsort ( ludi, count, sizeof(data) , compiknumber1 );
        if(a==2 && c==2)qsort ( ludi, count, sizeof(data) , compiktime1 );
        if(a==2 && c==1)qsort ( ludi, count, sizeof(data) , compikname2 );
        if(a==3 && c==2)qsort ( ludi, count, sizeof(data) , compiknumber2 );
        if(a==3 && c==1)qsort ( ludi, count, sizeof(data) , compiktime2 );
        for (int i = 0; i<count; i++) printf("%s %s %lld\n", people[i].name, people[i].number, people[i].time);
        break;
    }
    char* filename2=m;
    save(filename2, ludi, count);
    return 0;
}


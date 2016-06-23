#include<stdio.h>
#include<stdlib.h>


typedef struct Student student;


struct Student{
    char name[15];
    int score;
    int seq;
};

student A[10000000];

int cmp(const void *c,const void *d){
    student *a =(student*)c;
    student *b =(student*)d;
    if(a->score>b->score){
        return 1;
    }else if(a->score<b->score){
        return -1;
    }else{
        if(a->seq>b->seq){
            return 1;
        }else{
            return -1;
        }
    }

}

int main(){

int N,i;
char tmp;
while(scanf("%d",&N)!=EOF){
tmp =getchar();

for(i=0;i<N;i++){
    scanf("%s %d",&A[i].name,&A[i].score);
    A[i].seq=i;
    tmp =getchar();
}
qsort(A,N,sizeof(student),cmp);
for(i=0;i<N;i++){

    printf("%s %d\n",A[i].name,A[i].score);
}
}

return 0;
}

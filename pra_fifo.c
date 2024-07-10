/*PAGE REPLACEMENT ALGORITHM*/
/*FIFO*/

#include<stdio.h>
#include<stdlib.h>
#define MAX_FRAME 3
#define MAX_PAGE 20
int frames[MAX_FRAME];
int rear = -1;

void initialize(){
    for(int i=0;i<MAX_FRAME;i++){
        frames[i]=-1;
    }
}

void display(){
    for(int i = 0 ;i<MAX_FRAME;i++){
        if(frames[i]!=-1){
            printf("%d  ",frames[i]);
        }
        else{
            printf("-  ");
        }
        
    }
    printf("\n");
}

void fifo(int pages[],int n){
    int pagefault=0;
    for(int i=0;i<n;i++){
        int found = 0;
        int page = pages[i];
        for(int j = 0;j<MAX_FRAME;j++){
            if(frames[j]==page){
                found = 1;
                break;
            }
        }
        
        if (found == 0){
            pagefault++;
            if(rear<MAX_FRAME-1){
                rear++;
            }else{
                rear=0;
            }
            
            frames[rear]=page;
            display();
        }
    }
    printf("Total page faults :%d\n",pagefault);
}

int main(){
    int pages[MAX_PAGE];
    int n;
    printf("Enter the number of pages:\n");
    scanf("%d",&n);
    printf("Enter the paging sequence:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    initialize();
    fifo(pages,n);
    return 0;   
}

/*
SAMPLE OUTPUT
Enter the number of pages:
8
Enter the paging sequence:
1 3 0 3 5 6 3 0
1  -  -  
1  3  -  
1  3  0  
5  3  0  
5  6  0  
5  6  3  
0  6  3  
Total page faults :7*/

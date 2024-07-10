/*PAGE REPLACEMENT ALGORITHM*/
/*LRU*/

#include<stdio.h>
#include<stdlib.h>
#define MAX_FRAME 4
#define MAX_PAGE 20
int frames[MAX_FRAME];
int counter[MAX_FRAME];

void initialize(){
    for(int i=0;i<MAX_FRAME;i++){
        frames[i]=-1;
        counter[i]=0;
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

int findLRU(){
    int max=counter[0];
    int pframe=0;
    for(int i=1;i<MAX_FRAME;i++){
        if(counter[i]>max){
            max=counter[i];
            pframe=i;
        }
    }
    return pframe;
}

void lru(int pages[],int n){
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
            int lru_frame = findLRU();
            frames[lru_frame]=page;
            counter[lru_frame]=0;
        }
        for(int i =0;i<MAX_FRAME;i++){
            counter[i]++;
        }
        for(int j = 0;j<MAX_FRAME;j++){
            if(frames[j]==page){
                counter[j]=0;
                break;
            }
        }
        display();
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
    lru(pages,n);
    return 0;
    
    
}

/*
SAMPLE OUTPUT
Enter the number of pages:
14
Enter the paging sequence:
7 0 1 2 0 3 0 4 2 3 0 3 2 3
7  -  -  -  
7  0  -  -  
7  0  1  -  
7  0  1  2  
7  0  1  2  
3  0  1  2  
3  0  1  2  
3  0  4  2  
3  0  4  2  
3  0  4  2  
3  0  4  2  
3  0  4  2  
3  0  4  2  
3  0  4  2  
Total page faults :6
*/

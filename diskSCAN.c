#include<stdio.h>
#include<stdlib.h>

#define MAX_REQ 100

int rnum , head , dir , MAX_TRACK;

int scan(int req[]){
    int totalTime=0;
    int index=0;
    //SORT THE REQUESTS
    for(int i=0;i<rnum;i++){
        for(int j=0;j<rnum-i-1;j++){
            if(req[j]>req[j+1]){
                int temp = req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }
        }
    }
    //FIND THE index
    for(int i=0;i<rnum;i++){
        if(req[i]>=head){
            index=i;
            break;
        }
    }
    
    //going in right direction
    
    if(dir == 1){
        for(int i=index;i<rnum;i++){
            totalTime+=abs(head-req[i]);
            head=req[i];
        }
        
        if(head!=MAX_TRACK-1){
            totalTime+=abs(MAX_TRACK-1-req[rnum-1]);
            head = MAX_TRACK-1;
            for(int i=index-1;i>=0;i--){
                totalTime+=abs(head-req[i]);
                head=req[i];
            }
        }
    }
    
    else{
        for(int i=index-1;i>=0;i--){
            totalTime+=abs(head-req[i]);
            head=req[i];
        }
        if(head!=0){
            totalTime+=abs(req[0]-0);
            head=0;
            for(int i=index;i<rnum;i++){
                totalTime+=abs(head-req[i]);
                head=req[i];
            }
        }
    }
    
    return totalTime;
    
}
int main(){
    int requests[MAX_REQ];
    printf("Enter the number of requests:\n");
    scanf("%d",&rnum);
    printf("Enter the requests:\n");
    for(int i=0;i<rnum;i++){
        scanf("%d",&requests[i]);
    }
    printf("Enter the head:\n");
    scanf("%d",&head);
    printf("Enter the direction:\n");
    scanf("%d",&dir);
    
    printf("Enter the MAX_TRACK\n");
    scanf("%d",&MAX_TRACK);
    
    int seekTime = scan(requests);
    printf("The total seekTime using scan is:%d",seekTime);
}

/*SAMPLE OUTPUT
Enter the number of requests:
7
Enter the requests:
52
42
2
56
73
44
97
Enter the head:
47
Enter the direction:
1
Enter the MAX_TRACK
200
The total seekTime using scan is:349
*/

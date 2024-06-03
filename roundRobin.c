#include<stdio.h>

typedef struct{
    int name;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
}Process;

int q[100];
int front=-1;
int rear=-1;

void enqueue(int item){
    if(front == -1 && rear == -1){
        front=rear=0;
    }
    else{
        rear++;
    }
    q[rear]=item;
}

int dequeue(){
    int item;
    if(front == -1){
        return -1;
    }
    if(front == rear){
        item=q[front];
        front=rear=-1;
    }
    else{
        item = q[front];
        front++;
    }
    return item;
}

int main(){
    int noOfProcess;
    int timeQuantum;
    printf("Enter number of process:\n");
    scanf("%d",&noOfProcess);
    printf("Enter the timeQuantum:\n");
    scanf("%d",&timeQuantum);
    
    Process processes[noOfProcess];
    
    printf("Enter the name and burst time of the processes:\n");
    for(int i=0;i<noOfProcess;i++){
        scanf("%d %d",&processes[i].name,&processes[i].bt);
        processes[i].rt = processes[i].bt;
        enqueue(i);
        
    }
    int currentTime=0;
    
    while(front != -1){
        int i=dequeue();
        if(processes[i].rt<=timeQuantum){
            currentTime+=processes[i].rt;
            processes[i].rt=0;
            processes[i].ct=currentTime;
        }
        else{
            currentTime+=timeQuantum;
            processes[i].rt-=timeQuantum;
            enqueue(i);
        }
    }
    
     for(int i=0;i<noOfProcess;i++){
        processes[i].tat = processes[i].ct;
        processes[i].wt = processes[i].tat - processes[i].bt;
    }
    
    //finding average tat and wt of the processes
    int totalWT = 0,totalTT = 0;
    float avgWaitingTime,avgTurnaroundTime;
    
    for(int i=0;i<noOfProcess;i++){
        totalWT+=processes[i].wt;
        totalTT+=processes[i].tat;
    }
    
    avgWaitingTime = (float)totalWT/noOfProcess;
    avgTurnaroundTime = (float)totalTT/noOfProcess;
    
    printf("NAME \t BT \t CT \t TAT \t WT \n");
    for(int i=0;i<noOfProcess;i++){
        printf("%d \t %d \t %d \t %d \t %d \n",processes[i].name,processes[i].bt,processes[i].ct,processes[i].tat,processes[i].wt);
    }
    
    printf("Average Waiting Time : %f\n",avgWaitingTime);
    printf("Average TurnAroundTime : %f\n",avgTurnaroundTime);
    
    return 0;
}

/*SAMPLE OUTPUT

Enter number of process:
3
Enter the timeQuantum:
2
Enter the name and burst time of the processes:
1 4
2 3
3 5
NAME     BT      CT      TAT     WT 
1        4       8       8       4 
2        3       9       9       6 
3        5       12      12      7 
Average Waiting Time : 5.666667
Average TurnAroundTime : 9.666667

*/

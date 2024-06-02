#include<stdio.h>

typedef struct{
    int name;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
}Process;

int main(){
    int noOfProcess;
    int i;
    printf("Enter number of process:\n");
    scanf("%d",&noOfProcess);
    
    Process processes[noOfProcess];
    
    printf("Enter the name , arrival time and burst time of the processes:\n");
    for(i=0;i<noOfProcess;i++){
        scanf("%d %d %d",&processes[i].name,&processes[i].at,&processes[i].bt);
        
    }
    //finding completion time of processes
    
    processes[0].ct=processes[0].bt;
    for(i=1;i<noOfProcess;i++){
        processes[i].ct=processes[i-1].ct + processes[i].bt;
    }
    
    //finding turnaroundtime and waitingtime of processes
    
    for(i=0;i<noOfProcess;i++){
        processes[i].tat = processes[i].ct - processes[i].at;
        processes[i].wt = processes[i].tat - processes[i].bt;
    }
    
    //finding average tat and wt of the processes
    int totalWT = 0,totalTT = 0;
    float avgWaitingTime,avgTurnaroundTime;
    
    for(i=0;i<noOfProcess;i++){
        totalWT+=processes[i].wt;
        totalTT+=processes[i].tat;
    }
    
    avgWaitingTime = (float)totalWT/noOfProcess;
    avgTurnaroundTime = (float)totalTT/noOfProcess;
    
    printf("NAME \t AT \t BT \t CT \t TAT \t WT \n");
    for(i=0;i<noOfProcess;i++){
        printf("%d \t %d \t %d \t %d \t %d \t %d \n",processes[i].name,processes[i].at,processes[i].bt,processes[i].ct,processes[i].tat,processes[i].wt);
    }
    
    printf("Average Waiting Time : %f\n",avgWaitingTime);
    printf("Average TurnAroundTime : %f\n",avgTurnaroundTime);
    
    return 0;
}


//SAMPLE OUTPUT
Enter number of process:
5
Enter the name , arrival time and burst time of the processes:
1 0 8
2 1 1
3 2 3
4 3 2
5 4 6
NAME     AT      BT      CT      TAT     WT 
1        0       8       8       8       0 
2        1       1       9       8       7 
3        2       3       12      10      7 
4        3       2       14      11      9 
5        4       6       20      16      10 
Average Waiting Time : 6.600000
Average TurnAroundTime : 10.600000

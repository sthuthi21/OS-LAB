//this code is for shortest job first algorithm (without preemption) with the arrival time of every process as 0

#include<stdio.h>

typedef struct{
    int name;
    int bt;
    int ct;
    int tat;
    int wt;
}Process;

void sortProcesses(Process processes[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(processes[j].bt>processes[j+1].bt){
                Process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
}

int main(){
    int noOfProcess;
    int i;
    printf("Enter number of process:\n");
    scanf("%d",&noOfProcess);
    
    Process processes[noOfProcess];
    
    printf("Enter the name and burst time of the processes:\n");
    for(i=0;i<noOfProcess;i++){
        scanf("%d %d",&processes[i].name,&processes[i].bt);
        
    }
    
    sortProcesses(processes,noOfProcess);
    //finding completion time of processes
    
    processes[0].ct=processes[0].bt;
    for(i=1;i<noOfProcess;i++){
        processes[i].ct=processes[i-1].ct + processes[i].bt;
    }
    
    //finding turnaroundtime and waitingtime of processes
    
    for(i=0;i<noOfProcess;i++){
        processes[i].tat = processes[i].ct;
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
    
    printf("NAME \t BT \t CT \t TAT \t WT \n");
    for(i=0;i<noOfProcess;i++){
        printf("%d \t %d \t %d \t %d \t %d \n",processes[i].name,processes[i].bt,processes[i].ct,processes[i].tat,processes[i].wt);
    }
    
    printf("Average Waiting Time : %f\n",avgWaitingTime);
    printf("Average TurnAroundTime : %f\n",avgTurnaroundTime);
    
    return 0;
    
    
}

/*SAMPLE OUTPUT

Enter number of process:
5
Enter the name and burst time of the processes:
1 8
2 1
3 3
4 2
5 6
NAME     BT      CT      TAT     WT 
2        1       1       1       0 
4        2       3       3       1 
3        3       6       6       3 
5        6       12      12      6 
1        8       20      20      12 
Average Waiting Time : 4.400000
Average TurnAroundTime : 8.400000

*/

//this is the code for shortest remaining time first algorithm 
#include<stdio.h>
#include<limits.h>

typedef struct{
    int name;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
}Process;

int findShortestJob(Process processes[],int n , int currentTime , int rt[]){
    int shortestJob = -1;
    int minBurstTime = INT_MAX;
    for(int i =0;i<n;i++){
        if(processes[i].at<=currentTime&& rt[i]<=minBurstTime && rt[i]>0){
            minBurstTime = rt[i];
            shortestJob = i;
        }
    }
    return shortestJob;
}

void calculateTime(Process processes[],int n){
    int remainingTime[n];
    int completed = 0 , shortestJob;
    int currentTime = 0;
    int shortestJobs[50];
    
    for(int i=0;i<n;i++){
        remainingTime[i]=processes[i].bt;
    }
    
    int i=0; 
    
    while(completed<n){
        shortestJob = findShortestJob(processes, n , currentTime , remainingTime);
        printf("Executing P%d\n",shortestJob);
        shortestJobs[i++] = shortestJob;
        
        if(shortestJob==-1){
        currentTime++;
        continue;
        }
    
        remainingTime[shortestJob]--;
        currentTime++;
        
        if(remainingTime[shortestJob]==0){
            processes[shortestJob].ct = currentTime;
            processes[shortestJob].tat = processes[shortestJob].ct - processes[shortestJob].at;
            processes[shortestJob].wt = processes[shortestJob].tat - processes[shortestJob].bt;
            completed++;
        }
    }
    
}

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
    
    calculateTime(processes,noOfProcess);
    
    
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

/*SAMPLE OUTPUT
Enter number of process:
5
Enter the name , arrival time and burst time of the processes:
1 0 8
2 1 1 
3 2 3
4 3 2
5 4 6
Executing P0
Executing P1
Executing P2
Executing P3
Executing P3
Executing P2
Executing P2
Executing P4
Executing P4
Executing P4
Executing P4
Executing P4
Executing P4
Executing P0
Executing P0
Executing P0
Executing P0
Executing P0
Executing P0
Executing P0
NAME     AT      BT      CT      TAT     WT 
1        0       8       20      20      12 
2        1       1       2       1       0 
3        2       3       7       5       2 
4        3       2       5       2       0 
5        4       6       13      9       3 
Average Waiting Time : 3.400000
Average TurnAroundTime : 7.400000
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_REQUESTS 100

int calculateTotalSeekTime(int *processes , int n){
    int totalseektime=0; 
    int currentTrack=0;
    
    for(int i=0;i<n;i++){
        int seekTime = abs(currentTrack-processes[i]);
        
        currentTrack=processes[i];
        totalseektime+=seekTime;
    }
    
    return totalseektime;
}

int main(){
    int requests[MAX_REQUESTS];
    int numRequests;
    printf("Enter the number of disk requests: ");
    scanf("%d", &numRequests);

    if (numRequests <= 0 || numRequests > MAX_REQUESTS) {
        printf("Invalid number of requests.\n");
        return 1;
    }

    // Input disk requests
    printf("Enter the disk requests (track numbers):\n");
    for (int i = 0; i < numRequests; i++) {
        scanf("%d", &requests[i]);
    }

    // Calculate and print total seek time
    int totalSeekTime = calculateTotalSeekTime(requests, numRequests);
    printf("Total seek time using FCFS: %d\n", totalSeekTime);

    return 0;
}

/*SAMPLE OUTPUT
Enter the number of disk requests: 7
Enter the disk requests (track numbers):
82
170
43
140
24
16
190
Total seek time using FCFS: 692

*/



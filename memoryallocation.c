#include<stdio.h>

void firstFit(int blockSize[],int m,int processSize[],int n){
    int allocation[n];
    for(int i=0;i<n;i++){
        allocation[i]=-1;
    }
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            if(processSize[i]<=blockSize[j]){
                allocation[i]=j;
                blockSize[j]-=processSize[i];
                break;
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(allocation[i]!=-1){
            printf("Process %d is allocated to block %d.\n",i+1,allocation[i]+1);
        }
        else{
            printf("Process %d is not allocated.\n",i+1);
        }
    }
    
    printf("Memory left in the blocks:\n");
    for(int i=0;i<m;i++){
        printf("Block %d : %d kB\n",i+1,blockSize[i]);
    }
}

void worseFit(int blockSize[],int m , int processSize[] , int n){
    int allocation[n];
    for(int i=0;i<n;i++){
        allocation[i]=-1;
    }
    
    for(int i=0;i<n;i++){
        int lsb = -1;
        for(int j=0;j<m;j++){
            if(blockSize[j]>=processSize[i]){
                if(lsb==-1||blockSize[lsb]<blockSize[j]){
                    lsb = j;
                }
            }
        }
        if(lsb!=-1){
            allocation[i]=lsb;
            blockSize[lsb]-=processSize[i];
        }
        
    }
    
    for(int i=0;i<n;i++){
        if(allocation[i]!=-1){
            printf("Process %d is allocated to block %d.\n",i+1,allocation[i]+1);
        }
        else{
            printf("Process %d is not allocated.\n",i+1);
        }
    }
    
    printf("Memory left in the blocks:\n");
    for(int i=0;i<m;i++){
        printf("Block %d : %d kB\n",i+1,blockSize[i]);
    }
}

void bestFit(int blockSize[],int m , int processSize[] , int n){
    int allocation[n];
    for(int i=0;i<n;i++){
        allocation[i]=-1;
    }
    
    for(int i=0;i<n;i++){
        int ssb = -1;
        for(int j=0;j<m;j++){
            if(blockSize[j]>=processSize[i]){
                if(ssb==-1||blockSize[ssb]>blockSize[j]){
                    ssb = j;
                }
            }
        }
        if(ssb!=-1){
            allocation[i]=ssb;
            blockSize[ssb]-=processSize[i];
        }
        
    }
    
    for(int i=0;i<n;i++){
        if(allocation[i]!=-1){
            printf("Process %d is allocated to block %d.\n",i+1,allocation[i]+1);
        }
        else{
            printf("Process %d is not allocated.\n",i+1);
        }
    }
    
    printf("Memory left in the blocks:\n");
    for(int i=0;i<m;i++){
        printf("Block %d : %d kB\n",i+1,blockSize[i]);
    }
}

int main(){
    //since the blocksize value changes after every allocation , we use different arrays for all the 3 kinds of allocations.
    
    int blockSize1[]={100,500,200,300,600};
    int blockSize2[]={100,500,200,300,600};
    int blockSize3[]={100,500,200,300,600};
    int processSize[]={212,417,112,426};
    int m = sizeof(blockSize1)/sizeof(blockSize1[0]);
    int n = sizeof(processSize)/sizeof(processSize[0]);
    printf("FIRST FIT ALLOCATION\n");
    firstFit(blockSize1,m,processSize,n);
    printf("WORST FIT ALLOCATION:\n");
    worseFit(blockSize2,m,processSize,n);
    printf("BEST FIT ALLOCATION:\n");
    bestFit(blockSize3,m,processSize,n);
    return 0;
}

/*SAMPLE OUTPUT
FIRST FIT ALLOCATION
Process 1 is allocated to block 2.
Process 2 is allocated to block 5.
Process 3 is allocated to block 2.
Process 4 is not allocated.
Memory left in the blocks:
Block 1 : 100 kB
Block 2 : 176 kB
Block 3 : 200 kB
Block 4 : 300 kB
Block 5 : 183 kB
WORST FIT ALLOCATION:
Process 1 is allocated to block 5.
Process 2 is allocated to block 2.
Process 3 is allocated to block 5.
Process 4 is not allocated.
Memory left in the blocks:
Block 1 : 100 kB
Block 2 : 83 kB
Block 3 : 200 kB
Block 4 : 300 kB
Block 5 : 276 kB
BEST FIT ALLOCATION:
Process 1 is allocated to block 4.
Process 2 is allocated to block 2.
Process 3 is allocated to block 3.
Process 4 is allocated to block 5.
Memory left in the blocks:
Block 1 : 100 kB
Block 2 : 83 kB
Block 3 : 88 kB
Block 4 : 88 kB
Block 5 : 174 kB
*/

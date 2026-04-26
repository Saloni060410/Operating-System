#include <stdio.h>

int main() {
    int size[20]   = {100,300,40,50,150,240,200,400};
    int status[20] = {1,0,1,0,1,0,1,0}; // 1 = allocated, 0 = free
    int n = 8;

    printf("\nInitial Memory:\n");
    printf("No\tSize\tStatus\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%s\n", i+1, size[i],status[i]?"Allocated":"Free");
    }

    int m;
    printf("Enter number of processes: ");
    scanf("%d", &m);

    int req[20];
    for(int i=0;i<m;i++){
        printf("Enter size of process %d: ", i+1);
        scanf("%d",&req[i]);
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(status[j]==0 && size[j]>=req[i]){

                printf("\nProcess %d -> Block %d (%d KB)\n", i+1, j+1, size[j]);

                int rem = size[j] - req[i];

                status[j]=1;
                size[j]=req[i];

                if(rem>0){
                    for(int k=n;k>j+1;k--){
                        size[k]=size[k-1];
                        status[k]=status[k-1];
                    }
                    size[j+1]=rem;
                    status[j+1]=0;
                    n++;
                }
                break;
            }
        }
    }

    printf("\nFinal Memory:\n");
    printf("No\tSize\tStatus\n");

    int totalFree=0;
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%s\n", i+1, size[i],status[i]?"Allocated":"Free");

        if(status[i]==0)
            totalFree+=size[i];
    }

    printf("\nTotal Free Space = %d KB\n", totalFree);
}
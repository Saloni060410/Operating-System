#include <stdio.h>

int main() {
    int size[20]   = {100,300,40,50,150,240,200,400};
    int status[20] = {1,0,1,0,1,0,1,0};
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
        int worst=-1;

        for(int j=0;j<n;j++){
            if(status[j]==0 && size[j]>=req[i]){
                if(worst==-1 || size[j]>size[worst])
                    worst=j;
            }
        }

        if(worst!=-1){
            printf("\nProcess %d -> Block %d (%d KB)\n", i+1, worst+1, size[worst]);

            int rem = size[worst] - req[i];

            status[worst]=1;
            size[worst]=req[i];

            if(rem>0){
                for(int k=n;k>worst+1;k--){
                    size[k]=size[k-1];
                    status[k]=status[k-1];
                }
                size[worst+1]=rem;
                status[worst+1]=0;
                n++;
            }
        }
    }

    printf("\nFinal Memory:\n");
    printf("No\tSize\tStatus\n");

    int totalFree=0;
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%s\n", i+1, size[i],
               status[i]?"Allocated":"Free");

        if(status[i]==0) totalFree+=size[i];
    }

    printf("\nTotal Free Space = %d KB\n", totalFree);
}
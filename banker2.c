#include <stdio.h> 
#include<stdlib.h>
int main() {  
    int n, m, i, j, k; 
    printf("Enter no of processes"); 
    scanf("%d",&n);
    printf("Enter no of resources");
    scanf("%d",&m); 
    int alloc[n][m], max[n][m], avail[m];
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("Enter the allocation for process %d of resource %d : ",i,j);
            scanf("%d",&alloc[i][j]);                
        }    
    }
    for( i=0;i<n;i++){
        for( j=0;j<m;j++){
            printf("Enter the maximum for process %d of resource %d : ",i,j);
            scanf("%d",&max[i][j]);                
        }    
    }
    for( j=0;j<m;j++){
        printf("Enter the available resources vector for resource %d : ",j);        
        scanf("%d",&avail[j]);
    }
    int finish[n], ans[n], ind = 0; 
    for (k = 0; k < n; k++) { 
        finish[k] = 0; 
    } 
    int need[n][m]; 
    for (i = 0; i < n; i++) { 
        for (j = 0; j < m; j++) 
            need[i][j] = max[i][j] - alloc[i][j]; 
    }
    printf("Need matrix is: \n");
    for (i = 0; i < n; i++) { 
        for (j = 0; j < m; j++){ 
            printf("%d\t",need[i][j]);
        }
        printf("\n"); 
    }
    int y = 0; 
    for (k = 0; k < n; k++) { 
        for (i = 0; i < n; i++) { 
            if (finish[i] == 0) { 
  
                int flag = 0; 
                for (j = 0; j < m; j++) { 
                    if (need[i][j] > avail[j]){ 
                        flag = 1; 
                         break; 
                    } 
                } 
  
                if (flag == 0) { 
                    ans[ind++] = i; 
                    for (y = 0; y < m; y++) 
                        avail[y] += alloc[i][y]; 
                    finish[i] = 1; 
                } 
            } 
        } 
    } 
    printf("Following is the SAFE Sequence\n"); 
    for (i = 0; i < n - 1; i++){ 
        printf(" P%d =>", ans[i]);
    } 
    printf(" P%d\n", ans[n - 1]); 
  
    return (0); 
}

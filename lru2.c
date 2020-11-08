#include<stdio.h>
#include<stdlib.h>
int findLRU(int tim[], int n){
	int i, min = tim[0], pos = 0;
	for(i = 1; i < n; ++i){
		if(tim[i] < min){
			min = tim[i];
			pos = i;
		}
	}
	return pos;
} 
int main(){
    int fram, pag, frames[10], pages[30], flag = 0, tim[10], flag1, flag2, i, j, pos, faults = 0;
	printf("Enter number of frames: ");
	scanf("%d", &fram);
	printf("Enter number of pages: ");
	scanf("%d", &pag);
	printf("Enter reference string: ");
    for(i = 0; i<pag;i++){
    	scanf("%d", &pages[i]);
    }
	for(i=0;i<fram;i++){
    	frames[i] = -1;
    }
    for(i=0;i<pag;i++){
    	flag1 = flag2 = 0;
    	for(j=0;j<fram;j++){
    		if(frames[j] == pages[i]){
	    		flag++;
	    		tim[j] = flag;
	   			flag1 = flag2 = 1;
	   			break;
   			}
    	}
    	if(flag1 == 0){
			for(j=0;j<fram;j++){
	    		if(frames[j] == -1){
	    			flag++;
	    			faults++;
	    			frames[j] = pages[i];
	    			tim[j] = flag;
	    			flag2 = 1;
	    			break;
	    		}
    		}	
    	}
    	if(flag2 == 0){
    		pos = findLRU(tim, fram);
    		flag++;
    		faults++;
    		frames[pos] = pages[i];
    		tim[pos] = flag;
    	}
    	printf("\n");
    	for(j=0;j<fram;j++){
    		printf("%d\t", frames[j]);
    	}
	}
	printf("\n\nTotal Page Faults = %d", faults);
    return 0;
}

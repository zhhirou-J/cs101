#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE* lotto;
int num[6] = {0};
void lottery(){
    int arr,c,n=0;
    for(int i=1;i<6;i++){
        num[i]=0;
    }
    while(n < 5){
        arr=rand()%69+1;
        c = 0;
        for(int i =1;i<=n;i++){
            if(num[i] == arr){
                c = 1;
            }
        }
        if(c == 0){
            num[n] = arr;
            n++;
        }
    }
        int q = 0, w = 0 ,temp = 0;
    	for( q = 0; q < 5; q++) {
        	for( w = q; w < 5; w++) {
            	if( num[w] < num[q] ) {
                temp = num[w];
                num[w] = num[q];
                num[q] = temp;
            }
        }
    }
    num[5] = rand()%10+1;
    for(int i=0;i<6;i++){
        fprintf(lotto,"%02d ",num[i]);
    }
}
int main(){
	lotto=fopen("lotto.txt","w+");
    int n=2;
    srand((unsigned) time(NULL));
    time_t curtime;
    time(&curtime);
    fprintf(lotto,"======== lotto649 ========\n%s",ctime(&curtime));
    for(int i=0;i<n;i++){
        fprintf(lotto,"[%d] : ",i+1);
        lottery();
		fprintf(lotto,"\n");
    }
	for (int h=0;h<(5-n);h++){
        fprintf(lotto,"[%d] : ",n+h+1);
        for(int j=0;j<6;j++){
        	fprintf(lotto,"-- ");
        }fprintf(lotto,"\n");
    }
    fprintf(lotto,"======== csie@cgu ========");
    fclose(lotto);
}
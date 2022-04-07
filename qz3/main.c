#include <stdio.h>

FILE* Hanoi;

void rec_dec(char* s) {
	if(*(s)!=0){
		printf("%c,", s[0]);
		return rec_dec(++s);
	}
}

void hanoii(int n,char A,char B,char C){
    if (n) {
	    hanoii(n-1, A, C, B);
	    fprintf(Hanoi,"Move disk %d from %c to %c\n", n, A, C);  
	    hanoii(n-1 , B, A, C);
	}
}

int hanoi_tower(int n){
    Hanoi = fopen("hanoi.txt", "w+");
    hanoii(n,'A','B','C');
	fclose(Hanoi);
}

int multiplication(int i,int j){
    if (j < 10) {
		printf("%d*%d=%d ", i, j, i*j);	
		return multiplication(i, j+1);
	}
	else if (i < 9){
		j = 1;
		printf("\n");
		return multiplication(i+1, j);
	}
}

int main()
{
    char s[]="1234567890";
    printf("func#1-----------------------\n");
    rec_dec(s);
    printf("\nfunc#2-----------------------\n");
    hanoi_tower(16);
    printf("\nfunc#3-----------------------\n");
    multiplication(1,1);
    return 0;
}
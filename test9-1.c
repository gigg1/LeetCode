#include <stdio.h>

int isPalindrome(int x) {
    int count=0;
    int left=0;
    int right=0;
    char numberString[50];
    int x2=x;
    
    if(x<0){
        return 0;
    }else if(x==0){
        return 1;
    }else{
        while(x2!=0){
            x2/=10;
            count++;
        }
        printf("x=%d\n", x);
        sprintf(numberString,"%d",x);
        right=count;
        /*
        for(int j=0;j<count;j++){
        	printf("%c ",numberString[j]);
        }
        */
        //printf("\n");
        for(int i=0;i<count;i++){
            left=i;
            right=right-1;
            //printf("left=%d,right=%d\n",left,right);
            if(left==right){
                break;
            }
            if(numberString[left]==numberString[right]){
                continue;
            }else{
                return 0;
            }
            if(left==right-1){
                break;
            }
        }  
    }
    return 1;
}


int main(){

	int a=11344312;
	printf("%d\n",isPalindrome(a));

	return 0;
}
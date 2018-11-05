#include <stdio.h>
#include <stdlib.h>
int romanToInt(char* s) {
    int result=0,s1=0,s2=0;
    char map[7]={'I','V','X','L','C','D','M'};
    for(int i=0;;i++){
        //printf("%d\n",result);
        if(s[i+1]=='\0'){
            if(s[i]=='I'){
                result=result+1;
            }else if(s[i]=='V'){
                result=result+5;
            }else if(s[i]=='X'){
                result=result+10;
            }else if(s[i]=='L'){
                result=result+50;
            }else if(s[i]=='C'){
                result=result+100;
            }else if(s[i]=='D'){
                result=result+500;
            }else if(s[i]=='M'){
                result=result+1000;
            }
            break;
        }
        for(int j=0;j<7;j++){
            if(s[i]==map[j]) {
                s1=j;
            }
            if(s[i+1]==map[j]){
                s2=j;
            }
        }
        if(s1<s2){
            if(s[i]=='I'){
                result=result-1;
            }else if(s[i]=='X'){
                result=result-10;
            }else if(s[i]=='C'){
                result=result-100;
            }
        }else{
            if(s[i]=='I'){
                result=result+1;
            }else if(s[i]=='V'){
                result=result+5;
            }else if(s[i]=='X'){
                result=result+10;
            }else if(s[i]=='L'){
                result=result+50;
            }else if(s[i]=='C'){
                result=result+100;
            }else if(s[i]=='D'){
                result=result+500;
            }else if(s[i]=='M'){
                result=result+1000;
            }
        }
    }
    return result;
}

int main(){
    char arr[10];
    scanf("%s",arr);
    int result=romanToInt(arr);
    printf("%d\n",result);
    return 0;
}
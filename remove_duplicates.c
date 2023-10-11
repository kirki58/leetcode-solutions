#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// remove all adjacent duplicates in a string
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

void removeadj(char* s , char* frstchar){
    char* temp = frstchar;
    while(true){
        if(*(temp+2) == '\0'){
            *temp = '\0';
            break;
        }
        *temp = *(temp+2);
        temp++;
    }

}

char * removeDuplicates(char * s){
    bool IsThereDuplicates = false;

    if(strlen(s) <= 1){
        return s;
    }
    
    char* frst = s;
    char* second = s+1;

    while (*second != '\0')
    {
        if(*frst == *second){
            removeadj(s,frst);
            IsThereDuplicates = true;
            frst = frst-2;
            second = second-2;
        }
        else{
            frst++;
            second++;
        }
    }
    
    if(IsThereDuplicates == false){
        return s;
    }
    return removeDuplicates(s);
}

int main(){
    char str[9] = "aabbdefgg";
    printf("%s\n",removeDuplicates(str));
    return 0;
}
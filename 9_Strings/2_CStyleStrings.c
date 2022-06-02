#include<stdio.h>
#include<string.h>

int main(){
    // 1 Intialization
    char str[] = "gfg";
    /*as at lst place /0 is stored*/
    printf("%d\n",sizeof(str));
    for(int i=0;i<sizeof(str);i++){
        printf("%c",str[i]);
    }
    printf("\n");
    // 2 Initialization
    char Str[] = {'g','f','g','\0'}; // without '\0' it will give error in traditional c
    printf("%d\n",sizeof(Str));
    for(int i=0;i<sizeof(Str);i++){
        printf("%c",Str[i]);
    }
    printf("\n");
    // 3 strcmp
    char s1[]="abc";
    char s2[]="bcd";
    int res = strcmp(s1,s2); // compare strings in term of lexiogrphical order
    if(res>0){               // it will give smaller as 'a'<'b'
        printf("Greater");
    } 
    else if(res==0){
        printf("Same");
    }
    else{
        printf("Smaller");
    }
    printf("\n");
    // 4 strcpy
    char strg[5];
    // str = "gfg"; // it won't work as we can't assign string to array
    strcpy(strg,"gfg");
    printf("%d\n",sizeof(str));
    for(int i=0;i<sizeof(str);i++){
        printf("%c",str[i]);
    }
    printf("\n");
    return 0;
}
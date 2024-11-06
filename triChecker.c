#include <stdio.h>
#include <string.h>
int s1; int s2; int s3;
char s[20];
int triCzech(int st1, int st2, int st3){
    if(st1>st2+st3){
        return 0;
    }
    else if(st3>st2+st1){
        return 0;
    }
    else if(st2>st1+st3){
        return 0;
    }
    return 1;
}
int main(int argc, char *argv[]) {
    if(argc>1&&strcmp(argv[1],"user")==0){
        printf("Enter your Numbers\n");
        fgets(s,20,stdin);
        //printf("nums given:%s\n",s);
        sscanf(s, "%d %d %d",&s1,&s2,&s3);
        //printf("nums broken up:%d | %d | %d\n",s1,s2,s3);
        if(s1>s2+s3){
            printf("invalid\n");
            return 0;
        }
        else if(s3>s2+s1){
            printf("invalid\n");
            return 0;
        }
        else if(s2>s1+s3){
            printf("invalid\n");
            return 0;
        }
        else{
            printf("valid\n");
            return 0;
        }
    }
    if(argc>1&&strcmp(argv[1],"horizontal")==0){
        int cont=0;
        int count=0;
        while(fgets(s, sizeof(s),stdin)!=NULL){
            int l = strlen(s);
            if(s[l-1]=='\n'){
                if(l==1&&!cont){
                    printf("valid triangles: %d\n",count);
                    break;
                }
                cont=0;
                sscanf(s, "%d %d %d",&s1,&s2,&s3);
                if(triCzech(s1,s2,s3)){
                    count++;
                }
                //printf("\nline recieved %s",s);
            }
            else{
                //printf("line recieved no end newie %s",s);
                cont=1;
            }
        }
    }
    else{
        printf("Run the executable with user as input to process one triangle\n Run the executable with horizontal as input to find the number of\n valid triangles in multiple lines\n");
    }
    return 0;
}



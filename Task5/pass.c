#include <stdio.h>
#include <string.h>

int main()
{
    FILE* ptr;
    char* k;
    char s;
    char login[256];
    char buffer[256];
    //char *filename="passwdcopy";
    ptr=fopen( "passwdcopy", "r");

    printf("Введите ваш логин:");
 
    scanf("%s",login);
    //printf("%s\n",login);
    if (NULL==ptr){
        printf("file cann't be opened!!\n");
    }
   /*while(s!=EOF)
   {
    s=fgetc(ptr);
    printf("%c",s);
   }*/
    while(fgets(buffer,256,ptr))
    {
        //printf("%s",buffer);
        if (strstr(buffer,login)!=NULL)
        {
            break;
        }
    }
    k=strstr(buffer,":");
    for(int i=0;i<3;i++){
    k=strstr(k+1,":");
        //printf("%s\n",k);
    }
 
    k=strtok(k+1, ",");
    //printf("%s\n",k);
    printf("Имя вашего пользователя:%s\n",k);
    printf("_________________________\n");
    printf("Логин:%s\nИмя:%s\n",login,k);
}

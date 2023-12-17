#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100
struct person
{
    char surname[10];
    int number;
    char faculty[10];
    char group[10];
    //struct person* pNext;
};

void Insert(struct person list1[])
{
    printf("surname ");
   scanf("%s",list1->surname);
    printf("number ");
   scanf("%d",&(list1->number));
     printf("faculty " );
     scanf("%s",list1->faculty);
      printf("group ");
    scanf("%s",list1->group);

}
int Read_file(struct person list2[],const char* filename)
{
    FILE* S;
    S=fopen(filename,"r");
    if (S==NULL)
    {
        printf("Can't open");
        return 0;
    }
    int counter=0;
    while(fscanf(S, "%s %d %s %s",list2[counter].surname,&list2[counter].number,list2[counter].faculty,list2[counter].group)==4){
        

        counter++;
    }
    fclose(S);
    return counter;
} 

int Search(struct person list1[],int size_t, int data)
{
    for (int i=0;i<size_t;i++){
        if ( list1[i].number == data )
        {
           return 1;
        }
        
    }
    return 0;
}
void Save(struct person list1[], int size_t)
{
    FILE *S;
    S=fopen("Data.txt","w");

        for (int j=0;j<size_t;j++)
        {
            fprintf(S,"%s %d %s %s\n",list1[j].surname,list1[j].number,list1[j].faculty,  list1[j].group);
        
        }
    
    fclose(S);
}

void Delete(struct person list1[],int *size_t, int index)
{
    if(index>=*size_t){
        return ;
    }
    
    for(int i=index; i<=*size_t;i++)
    {
        list1[i]=list1[i+1];
    }
    (*size_t)--;
}

int main()
{
    //int size;
    printf("Размер таблицы: ");
    //scanf("%d",&size);
    int size_t=0;
    int y,b=1,a,z;
    struct person list[size];
    struct person x;
    struct person x1;
    struct person x2;
    system("clear");
    while(b==1){
    printf("Для выхода введите 0\n");
    printf("_____________________\n");
    printf(" 1)Добавить данные\n 2)Вывод списка \n 3)Сортировка\n 4)Сохранения в файл\n 5)Поиск по номеру зачетки\n 6)Удаление строки по номеру\n 7)Изменение строки таблицы\n 8)ЧТЕНИЕ\n ");
    printf("Выберите действия:");
    scanf("%d", &y);
    switch (y)
    {
    case 1:{
    
        Insert(&list[size_t]);
        size_t++;
        break;
        }
    case 2:{
        printf("_____________________\n");
        for (int i=0;i<size_t;i++){
            printf("%s, %d, %s, %s\n",list[i].surname,list[i].number,list[i].faculty,  list[i].group);
        }
        printf("_____________________\n");
        break;
        }
    
    case 3:{
        system("clear");
        printf(" 1)Сортировка по фамилиям\n 2)Сортировка по номерам книжки\n 3)Сортировка по факультетам\n 4)Сортировка по группам\n");
        printf("Выберите действия:");
         scanf("%d", &a);
         switch (a)
         {
         case 1:{
                        for(int i=0; i<size_t-1;i++)
                {
                    
                for(int j=size_t-1; j>i;j--)
                {
                    x1=list[j];
                    x2=list[j-1];

                    for(int k=0; k<10;k++)
                    {  
                        if(x1.surname[k]==0 || x2.surname[k]==0)
                        {
                            break;
                        }
                        if (x1.surname[k]<x2.surname[k])
                        {
                            
                            x=list[j];
                            list[j]= list[j-1];
                            list[j-1]=x;
                            break;
                        }
                    
                    }
                        
                }
                }
                break;
            }
          case 2:{
                        for(int i=0; i<size_t-1;i++)
                {
                for(int j=size_t-1; j>i;j--)
                {
                    if (list[j-1].number>list[j].number)
                    {
                    x=list[j];
                    list[j]= list[j-1];
                        list[j-1]=x;
                    }
                }
                }
                break;
                }
            case 3:{ 
                        for(int i=0; i<size_t-1;i++)
                {
                    
                for(int j=size_t-1; j>i;j--)
                {
                    x1=list[j];
                    x2=list[j-1];

                    for(int k=0; k<10;k++)
                    {  
                        if(x1.faculty[k]==0 || x2.faculty[k]==0)
                        {
                            break;
                        }
                        if (x1.faculty[k]<x2.faculty[k])
                        {
                            
                            x=list[j];
                            list[j]= list[j-1];
                            list[j-1]=x;
                            break;
                        }
                    
                    }
                        
                }
                break;
                }
                
                }       
          case 4:{
            for(int i=0; i<size_t-1;i++)
                {
                    
                for(int j=size_t-1; j>i;j--)
                {
                    x1=list[j];
                    x2=list[j-1];

                    for(int k=0; k<10;k++)
                    {  
                        if(x1.group[k]==0 || x2.group[k]==0)
                        {
                            break;
                        }
                        if (x1.group[k]<x2.group[k])
                        {
                            
                            x=list[j];
                            list[j]= list[j-1];
                            list[j-1]=x;
                            break;
                        }
                    
                    }
                        
                }
                }
                break;
          }  
        
         }
         break;
    }
    case 4:{
        Save(list,size_t);
        break;
       }
    case 5:{
        system("clear");
        int data;
        printf("Введите данные для поиска:");
        scanf("%d",&data);
        if(Search(list,size_t,data)==1)
        {
            printf("Число найдено\n");
            
        }else
        printf("Число не найдено\n");
        break;
        }
    case 6:{
        system("clear");
        int index;
        printf("Введите индекс удаляемого элемента:");
        scanf("%d",&index);
        Delete(list,&size_t,index);
        //size_t--;
        break;
    }
    case 7:{
        int index;
        system("clear");
        printf("Введите индекс изменяемого элемента:");
        scanf("%d",&index);
        if(index<size_t){
         Insert(&list[index]);}
         else
         printf("Данной позиции нету\n");
         break;
    }
    case 8:{
        system("clear");
        printf("Введите имя файла\n");
        char filename[50];
        scanf("%s",filename);
        size_t=Read_file(list,filename);
        break;
    }
    
    case 0:{
        b=0;
        break;
    }
    }
}
}    

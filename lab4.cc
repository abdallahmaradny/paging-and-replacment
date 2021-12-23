#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
int frame_val;
int star;
}node;
void FIFO(int Number_of_pages);
void LRU(int Number_of_pages);
void CLOCK(int Number_of_pages);

int main()
{
    int number_of_pages;
    char policy[10];
 
    scanf("%d",&number_of_pages);
    scanf("%s",policy);
    
if(strcmp(policy,"FIFO")==0)
{
 FIFO(number_of_pages);
}
else if(strcmp(policy,"LRU")==0)
 {
 LRU(number_of_pages);
}
else if(strcmp(policy,"CLOCK")==0)
{
CLOCK(number_of_pages);
}
printf("\n");

return 0;
}   
    void FIFO(int Number_of_pages)
{
        FILE *fp;
    char c[1000];
    char *argument;
    char *TOKENS[1000];
    int position = 0;
    int Pages_Needed[50];
    int Pages=0;
    while(1)
    {
       scanf("%d",&Pages_Needed[Pages]);
    if(Pages_Needed[Pages]==-1)
    {
        break;
    }
    Pages++;
    }
//     //opening file for matrix multiplication
//     fp = fopen("inputFIFO.txt", "r");
//     //reading till end of file
//     fscanf(fp,"%[^EOF]",c);
//     fclose(fp);
//     argument = strtok(c,"\n");
//     //divide read file and get output from it
//     while (argument != NULL)
//     {
//         TOKENS[position] = argument;
//         //printf(" %s ",TOKENS[position]);
//         position++;
//         argument = strtok(NULL,"\n");
//     }
//     Number_of_pages=atoi(TOKENS[0]);
//     //printf("jjjj%d",Number_of_pages);
//     for(int i=2;i<position-1;i++)
//     {
//       Pages_Needed[i-2]=atoi(TOKENS[i]);
//       //printf("%d",Pages_Needed[i-2]);
//     }
// //    / printf("POSITION %d ",position);
//    /* open the file for writing*/
//    fp = fopen ("outputFIFO1.txt","w");
  printf("Replacement Policy = FIFO\n"); 
  printf("-------------------------------------\n");
  printf("Page   Content of Frames\n");
  printf("----   -----------------\n");
 
    int frame[Number_of_pages];
    int temp_Number_of_pages=0;
    int faultflag=0;
    int number_of_page_faults=0;
    int index_of_oldest_frame=1;
frame[0]=Pages_Needed[0];
for(int x=1;x<Number_of_pages;x++)
{
    frame[x]=-1;
}
    temp_Number_of_pages++;
    printf("%02d     ",Pages_Needed[0]);
    printf("%02d \n",frame[0]);
    for(int i=1;i<Pages;i++)
    {
        faultflag=0;
        printf("%02d",Pages_Needed[i]);
            
        for(int x=0;x<temp_Number_of_pages;x++)
        {
         // printf("PAGE:%d\n",Pages_Needed[i]);
            if(frame[x]==Pages_Needed[i])
            {
                 printf("     ");
              faultflag=0;
             break;
            }
            else{
             faultflag=1;   
            }
        }
 
        if(faultflag==1)
        {
            if(index_of_oldest_frame==Number_of_pages)
            {
            index_of_oldest_frame=0;
            }
            frame[index_of_oldest_frame]=Pages_Needed[i];
            if(temp_Number_of_pages==Number_of_pages){
             number_of_page_faults++;
             
             printf(" F");            

             
            }
            if(temp_Number_of_pages<Number_of_pages)
            {
                    printf("  ");
           
                temp_Number_of_pages++;
            }
            index_of_oldest_frame++; 
       printf("   ");
    
        }
       
        for(int x=0;x<Number_of_pages;x++)
        {   if(frame[x]!=-1)
        {
            printf("%02d ",frame[x]);
        }}
        printf("\n");
    } 
    printf("-------------------------------------\n");
    printf("Number of page faults = %d",number_of_page_faults);
     

}


void LRU(int Number_of_pages)
{
    FILE *fp;
    char c[1000];
    char *argument;
    char *TOKENS[1000];
    int position = 0;
    int Pages_Needed[50];
        int Pages=0;
    while(1)
    {
       scanf("%d",&Pages_Needed[Pages]);
    if(Pages_Needed[Pages]==-1)
    {
        break;
    }
    Pages++;
    }
//     //opening file for matrix multiplication
//     fp = fopen("inputLRU.txt", "r");
//     //reading till end of file
//     fscanf(fp,"%[^EOF]",c);
//     fclose(fp);
//     argument = strtok(c,"\n");
//     //divide read file and get output from it
//     while (argument != NULL)
//     {
//         TOKENS[position] = argument;
//         //printf(" %s ",TOKENS[position]);
//         position++;
//         argument = strtok(NULL,"\n");
//     }
//     Number_of_pages=atoi(TOKENS[0]);
//     //printf("jjjj%d",Number_of_pages);
//     for(int i=2;i<position-1;i++)
//     {
//       Pages_Needed[i-2]=atoi(TOKENS[i]);
//       //printf("%d",Pages_Needed[i-2]);
//     }
// //    / printf("POSITION %d ",position);
//    /* open the file for writing*/
//   fp = fopen ("outputLRU1.txt","w");
  printf("Replacement Policy = LRU\n"); 
  printf("-------------------------------------\n");
  printf("Page   Content of Frames\n");
  printf("----   -----------------\n");
 
    int frame[Number_of_pages];
    int temp_Number_of_pages=0;
    int faultflag=0;
    int number_of_page_faults=0;
    int index_of_oldest_frame=1;
    int previous[50];
    int index_of_prev=0;
    int duplicateflag=0;
frame[0]=Pages_Needed[0];
for(int x=1;x<Number_of_pages;x++)
{
    frame[x]=-1;
}
previous[0]=Pages_Needed[0];
index_of_prev++;     
    temp_Number_of_pages++;
    printf("%02d     ",Pages_Needed[0]);
    printf("%02d \n",frame[0]);
    for(int i=1;i<Pages;i++)
    {
        faultflag=0;
        printf("%02d",Pages_Needed[i]);
            
        for(int x=0;x<temp_Number_of_pages;x++)
        {
         // printf("PAGE:%d\n",Pages_Needed[i]);
            if(frame[x]==Pages_Needed[i])
            {
                printf("     ");
              faultflag=0;
             break;
            }
            else{
             faultflag=1;   
            }
        }
        index_of_prev++;
        previous[index_of_prev]=Pages_Needed[i];
         
 
        if(faultflag==1)
        {
            if(temp_Number_of_pages<Number_of_pages)
            {
                frame[temp_Number_of_pages]=Pages_Needed[i];
                 printf("  ");
           
            }
             //   frame[index_of_oldest_frame]=Pages_Needed[i];
            if(temp_Number_of_pages==Number_of_pages){                
             
             number_of_page_faults++;
             printf(" F");
           int limit=index_of_prev-Number_of_pages;
              for(int x=index_of_prev-1;x>=limit;x--)
              {
               for(int y=x-1;y>=x-Number_of_pages+1;y--)
               {
                   if(previous[y]==previous[x])
                   {
                     limit--;
                     duplicateflag=1;
                     break;  
                   }
               }
              }
              for(int x=0;x<Number_of_pages;x++)
              {
                  
                  if(previous[limit]==frame[x])
                  {                      
                      frame[x]=Pages_Needed[i];
                  }
              }
            }
            if(temp_Number_of_pages<Number_of_pages)
            {
                temp_Number_of_pages++;
            }
        printf("   ");

         }
        
        for(int x=0;x<Number_of_pages;x++)
        {   if(frame[x]!=-1)
        {
            printf("%02d ",frame[x]);
        }}
        printf("\n");
    } 
    printf("-------------------------------------\n");
    printf("Number of page faults = %d",number_of_page_faults);
     

}
void CLOCK(int Number_of_pages)
{
    FILE *fp;
    char c[1000];
    char *argument;
    char *TOKENS[1000];
    int position = 0;
    int Pages_Needed[50];
    int Pages=0;
    while(1)
    {
       scanf("%d",&Pages_Needed[Pages]);
    if(Pages_Needed[Pages]==-1)
    {
        break;
    }
    Pages++;
    }
//     //opening file for matrix multiplication
//     fp = fopen("inputCLOCK.txt", "r");
//     //reading till end of file
//     fscanf(fp," %[^EOF]",c);
//     fclose(fp);
//     argument = strtok(c,"\n");
//     //divide read file and get output from it
//     while (argument != NULL)
//     {
//         TOKENS[position] = argument;
//         //printf(" %s ",TOKENS[position]);
//         position++;
//         argument = strtok(NULL,"\n");
//     }
//     Number_of_pages=atoi(TOKENS[0]);
//     for(int i=2;i<position-1;i++)
//     {
//       Pages_Needed[i-2]=atoi(TOKENS[i]);
//       //printf("%d",Pages_Needed[i-2]);
//     }
//   fp = fopen ("outputCLOCK1.txt","w");
  printf("Replacement Policy = CLOCK\n"); 
  printf("-------------------------------------\n");
  printf("Page   Content of Frames\n");
  printf("----   -----------------\n");
 

    node frame[Number_of_pages];
    int temp_Number_of_pages=0;
    int faultflag=0;
    int number_of_page_faults=0;
    int index_of_oldest_frame=1;
    int pointer=0;
frame[0].frame_val=Pages_Needed[0];

for(int x=1;x<Number_of_pages;x++)
{
frame[x].frame_val=-1;
}
pointer=1;     
    temp_Number_of_pages++;
    printf("%02d     ",Pages_Needed[0]);
    printf("%02d \n",frame[0].frame_val);
    for(int i=1;i<Pages;i++)
    {
        faultflag=0;
        printf("%02d",Pages_Needed[i]);
            
        for(int x=0;x<temp_Number_of_pages;x++)
        {
            if(frame[x].frame_val==Pages_Needed[i])
            {
            frame[x].star=1;
            faultflag=0;
             printf("     ");
             break;
            }
            else{
             faultflag=1;   
            }
        }
 
        if(faultflag==1)
        {
             if(temp_Number_of_pages<Number_of_pages)
             {
                 frame[temp_Number_of_pages].frame_val=Pages_Needed[i];
                  frame[temp_Number_of_pages].star=1;
             pointer=(pointer+1)%Number_of_pages;
             }
             
             
            if(temp_Number_of_pages==Number_of_pages){
             number_of_page_faults++;
            int flag=0;
             
             printf(" F");            
             while(1)
             {
                 if(frame[pointer].star==0)
                 {
                     frame[pointer].frame_val=Pages_Needed[i];
                     frame[pointer].star=1;
                     flag=1;
                     break;
                 }
                 frame[pointer].star=0;
                 pointer=(pointer+1)%Number_of_pages;
             }
             if(flag==1)
             {
                 pointer=(pointer+1)%Number_of_pages;
                 
             }
            }

            
            if(temp_Number_of_pages<Number_of_pages)
            {
                    printf("  ");
           
                temp_Number_of_pages++;
            }
            index_of_oldest_frame++; 
        printf("   ");
   
        }

        for(int x=0;x<Number_of_pages;x++)
        {   if(frame[x].frame_val!=-1)
        {
            printf("%02d ",frame[x].frame_val);
        }}
        printf("\n");
    } 
    printf("-------------------------------------\n");
    printf("Number of page faults = %d",number_of_page_faults);
     
}

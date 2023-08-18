#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 20

int main()
{
    char production[SIZE][SIZE], alpha[SIZE], beta[SIZE];
    int nont_terminal,i,j, index,num;
   
    printf("\n Enter the number of production: ");
    scanf("%d", &num);

    printf("\n Enter the Production as E-=E/A: ");
    for(int i = 0; i < num; i++)
    {
        scanf("%s", production[i]);
    }
   
    for(int cnt = 0; cnt < num; cnt++)
    {
        nont_terminal=production[cnt][0];
        index = 2;
        int pointer=0;
        if(nont_terminal==production[cnt][index]) //Checking if the Grammar is LEFT RECURSIVE
        {
            //Getting Alpha
            for(i=++index,j=0;production[cnt][i]!='/';i++,j++)
            {
                alpha[j]=production[cnt][i];
                pointer++;
                //Checking if there is NO Vertical Bar (|)
                if(production[cnt][i+1]==0)
                {
                    printf("This Grammar CAN'T BE REDUCED.\n");
                    exit(0); //Exit the Program
                }
            }
            alpha[j]='\0'; //String Ending NULL Character

            if(production[cnt][++i]!=0) //Checking if there is Character after Vertical Bar (|)
            {
                //Getting Beta
                for(j=i,i=0;production[cnt][j]!='\0';i++,j++)
                {
                    beta[i]=production[cnt][j];
                }
                beta[i]='\0'; //String Ending NULL character

                //Showing Output without LEFT RECURSION
                printf("After eliminating:\n");
                printf(" %c=%s%c'\n", nont_terminal,beta,nont_terminal);
                printf(" %c'=%s%c'|null\n", nont_terminal,alpha,nont_terminal);
            }
            else
                printf("This Grammar CAN'T be REDUCED.\n");
        }
        else
            //printf("\n This Grammar is not LEFT RECURSIVE.\n");
            printf(" %s\n", production[cnt]);
    }
    return 0;
}

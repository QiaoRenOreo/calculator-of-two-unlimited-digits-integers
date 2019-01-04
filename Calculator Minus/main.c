#include <stdio.h>
#include <stdlib.h>
void BigMinusSmall(int var1[], int var2[], int len1, int len2, int *minus);

int len(char *s)
{
    int cnt;
    for(cnt=0;s[cnt]!='\0';cnt++);
    return cnt;
}

int compare(int array1[], int array2[], int len1, int len2) //compare array1 => or  < arrray 2
{
    int r=1;
    int i;
    if (len1>len2)
    {
        r=1; //r=1 means len1> len2 means array1>array2
    }
    else if (len1==len2)
    {
        i=0;
        while((array1[i]==array2[i])&&(i<=len1-1))
        {
            i=i+1;
        }
        if (array1[i]>array2[i])
        {
            r=1;//means array1>array2
        }
        else
        {
            r=2;//means array1=<array2
        }
    }
    else
    {
        r=2;//means array1=array2
    }
    /*
    if (r==1)
    {
        printf("r=1, situation1: array1>=array2\n");
    }
    else
    {
        printf("r=2, situation2: array1<array2\n");
    }
    */
    return r;
}

void minus(int var1[], int var2[], int len1, int len2, int *minus)
{
    int r;
    r=compare(var1, var2, len1, len2);
    if (r==1)//means var1> or =var2
    {
        BigMinusSmall(var1, var2, len1, len2,minus);
    }
    if (r==2)//means var1<var2
    {
        printf("-");
        BigMinusSmall(var2, var1, len2, len1,minus);
    }
    free(minus);
}

 void BigMinusSmall(int var1[], int var2[], int len1, int len2, int *minus)
 {
    int MaxIndex1=len1-1;
    int MaxIndex2=len2-1;
    if(minus == NULL)
    {
        printf("Error! memory not allocated.");
        exit(0);
    }
    //printf("initial minus=");
    int i;
    for (i=0;i<len1+len2;i++)//initialization of the "sum" array
    {
        minus[i]=0;
        //printf("%d",minus[i]);// success
    }
    //printf("\n");

    int Index1=MaxIndex1;
    int Index2=MaxIndex2;
    int IndexMinus=len1+len2-1;
    //printf("Max Index Minus=%d\n\n",IndexMinus);

    while ((Index1>=0) && (Index2>=0))//????
    {
        if(var1[Index1]>=var2[Index2])
        {
            minus[IndexMinus]=var1[Index1]-var2[Index2];
        }
        else
        {
            minus[IndexMinus]=10+var1[Index1]-var2[Index2];
            var1[Index1-1]=var1[Index1-1]-1;
        }
        Index1--;
        Index2--;
        IndexMinus--;
    }
    while(Index1!=-1)
    {
        minus[IndexMinus]=var1[Index1];
        Index1--;
        IndexMinus--;
    }
    printf("calculated Minus=");

    for (IndexMinus=0;IndexMinus<len1+len2;IndexMinus++)
    {
        printf("%d",minus[IndexMinus]);
    }
    printf("\n\n");
    //free (minus);
 }


int main()
{
    char str1[10];
    int len1;
    int i;
    printf("enter number:");
    scanf("%s",str1);
    len1=len(str1);
    //printf("length of the first string =%d",len1);
    int var1[len1];
    for (i=0; i<len(str1); i++)
    {
        var1[i]=str1[i]-'0';
        printf("%d",var1[i]);
    }
    printf("\n");
    printf("max index=%d, value of final digit=%d\n",len1-1,var1[len1-1]); //4 digits do not work

    char str2[10];
    int len2;
    printf("enter number:");
    scanf("%s",str2);
    len2=len(str2);
    int var2[len2];
    for (i=0; i<len(str2); i++)
    {
        var2[i]=str2[i]-'0';//var1[i]=atoi(str1[i]);
    }
    printf("max index=%d, value of final digit=%d\n",len2-1,var2[len2-1]);
//_________________________________________________________//


    int *MINUS;
    MINUS=(int*)malloc((len1+len2)*sizeof(int));
    compare(var1, var2, len1, len2);
    minus(var1, var2, len1, len2,MINUS);//BigMinusSmall*/

    //free(MINUS);


    return 0;
}



#include <stdio.h>
#include <stdlib.h>
int len(char *s);
void sum(int var1[], int var2[], int len1, int len2, int*sum);
int GetLongInt(char *array);
//void CharToInt(char *array, int len)
/*
void CharToInt(char *array, int len)
{
    int i=0;
    for (i=0;i<len;i++)
    {
        array[i]=array[i]-'0';
    }
}
*/
int GetLongInt(char *array)
{
    int cnt=0;
    int size1=4;
    //char *var1;
    array=(char*)malloc(size1*sizeof(char));//*sizeof(char));//sizeof(char)=1 integer
    int i=0,j=0;
    char c;
    c=getchar();
    while(c!='\n')//('0'<=(c=getchar())&&(c=getchar())<='9') ||((c=getchar())=='\\') )
    {

         if (c=='\\')
        {
            while (getchar()!='\n')
                ;
        }
        else
        {
             if (i==size1)
            {
                char *temp;
                temp=(char*)malloc(size1+4);
                for (j=0;j<size1;j++)
                {
                    temp[j]=array[j];
                }
                free(array);
                array=temp;
                size1=size1+4;
            }
        }
            array[i] =c;
            i=i+1;
            cnt=cnt+1;
            c=getchar();//read the next single character, store it in variable c
    }
    printf("print long integer\n");
    for (i=0;i<size1;i++)
    {
        printf ("here: %d:%c\n",i,array[i]);
    }
    printf("%d",cnt);
    return cnt;
}


void sum(int var1[], int var2[], int len1, int len2, int*sum)
{
    int MaxIndex1=len1-1;
    int MaxIndex2=len2-1;
    sum=(int*)malloc((len1+len2)*sizeof(int));//2
    printf("initial sum=");
    int i;
    for (i=0;i<len1+len2;i++)//initialization of the "sum" array
    {
        sum[i]=0;
        printf("%d",sum[i]);// success
    }
    printf("\n");
    int c;
    int Index1=MaxIndex1;
    int Index2=MaxIndex2;
    int IndexSum=len1+len2-1;
    printf("Max Index Sum=%d\n\n",IndexSum);

    while ((Index1>=0) && (Index2>=0))
    {
        c=var1[Index1]+var2[Index2];
        printf("var1[%d]+var2[%d]=%d\n",Index1,Index2,c);
        sum[IndexSum]=sum[IndexSum]+c%10;
        printf("sum[%d]=%d\n",IndexSum,sum[IndexSum]);
        sum[IndexSum-1]=sum[IndexSum-1]+1.0*c/10;
        printf("sum[%d]=%d\n",IndexSum-1,sum[IndexSum-1]);
        IndexSum--;
        Index1--;
        Index2--;
    }
    printf("IndexSum=%d, Index1=%d,Index2=%d\n\n",IndexSum,Index1,Index2);

    if (Index1!=-1)
    {
        printf("1\n");
        while(Index1>=0)
        {
            printf("sum[%d]=%d",IndexSum,sum[IndexSum]);
            c=sum[IndexSum]+var1[Index1];
            printf("c=%d\n",c);
            sum[IndexSum]=c%10;
            printf("sum[%d]=%d\n",IndexSum,sum[IndexSum]);
            sum[IndexSum-1]=sum[IndexSum-1]+1.0*c/10;
            printf("sum[%d]=%d\n",IndexSum-1,sum[IndexSum-1]);
            Index1--;
            IndexSum--;
        }
    }
    else //means Index2=-1
    {
        printf("2\n");

        while(Index2>=0)
        {
            printf("sum[%d]=%d\n",IndexSum,sum[IndexSum]);
            c=sum[IndexSum]+var2[Index2];
            printf("c=%d\n",c);
            sum[IndexSum]=c%10;
            printf("sum[%d]=%d\n",IndexSum,sum[IndexSum]);
            sum[IndexSum-1]=sum[IndexSum-1]+1.0*c/10;
            printf("sum[%d]=%d\n",IndexSum-1,sum[IndexSum-1]);
            Index2--;
            IndexSum--;
        }
    }
    printf("result:sum=");

    for (IndexSum=0;IndexSum<len1+len2;IndexSum++)
    {
        printf("%d",sum[IndexSum]);
    }
}

int main()
{
    int len1;
    int i;
    char *var1="";
    //int size1=4;
    //var1=(char*)malloc(size1*sizeof(char));
    printf("Enter the 1st integer number: \n");
    len1=GetLongInt(var1);
    //CharToInt(var1, len1);

    /*char *var2;
    printf("Enter the 2nd integer number: \n");
    GetLongInt(var2);*/
    //len1=len(var1);
    int integer[len1];
    printf("len1[5]=%c\n",var1[2]);
    for (i=0;i<len1;i++)
    {
        integer[i]=var1[i]-'0';//var1[i]=atoi(str1[i]);
        printf("i=%d, %d\n",i,integer[i]);
    }
    printf("max index=%d, value=%d\n",len1-1,integer[len1-1]);
///////
/*
    char str2[10];
    int len2;
    printf("enter number:");
    scanf("%s",str2);
    len2=len(str2);
    printf("len2=%d\n",len2);
    printf("str2=%s\n",str2);
    int var2[len2];
    for (i=0;i<len(str2);i++)
    {
        var2[i]=str2[i]-'0';//var1[i]=atoi(str1[i]);
        printf("i=%d, %d\n",i,var2[i]);
    }
    printf("max index=%d, value=%d\n",len2-1,var2[len2-1]); //4 digits do not work
*/
    /*int *SUM;
    sum(var1, var2, len1, len2,SUM);*/

    return 0;
}


#include <stdio.h>
#include <stdlib.h>


int len(char *s)
{
    int cnt;
    for(cnt=0;s[cnt]!='\0';cnt++);
    return cnt;
}

void SumForMulti(int var1[], int var2[], int len1, int len2, int *sum)
{
    printf("Hello sum function!!!!\n\n");
    int MaxIndex1=len1-1;
    int MaxIndex2=len2-1;
    printf("initial sum=");
    int i;
    for (i=0;i<len1+len2;i++)
    {
        printf("%d",sum[i]);
    }
    int c;
    int Index1=MaxIndex1;
    int Index2=MaxIndex2;
    int IndexSum=len1+len2-1;
    //printf("Max Index Sum=%d\n\n",IndexSum);

    while ((Index1>=0) && (Index2>=0))
    {
        c=var1[Index1]+var2[Index2];
        //printf("var1[%d]+var2[%d]=%d\n",Index1,Index2,c);
        sum[IndexSum]=sum[IndexSum]+c%10;
        //printf("sum[%d]=%d\n",IndexSum,sum[IndexSum]);
        sum[IndexSum-1]=sum[IndexSum-1]+1.0*c/10;
        //printf("sum[%d]=%d\n",IndexSum-1,sum[IndexSum-1]);
        IndexSum--;
        Index1--;
        Index2--;
    }
    //printf("IndexSum=%d, Index1=%d,Index2=%d\n\n",IndexSum,Index1,Index2);

    if (Index1!=-1)
    {
        printf("1\n");
        while(Index1>=0)
        {
            //printf("sum[%d]=%d",IndexSum,sum[IndexSum]);
            c=sum[IndexSum]+var1[Index1];
            //printf("c=%d\n",c);
            sum[IndexSum]=c%10;
            //printf("sum[%d]=%d\n",IndexSum,sum[IndexSum]);
            sum[IndexSum-1]=sum[IndexSum-1]+1.0*c/10;
            //printf("sum[%d]=%d\n",IndexSum-1,sum[IndexSum-1]);
            Index1--;
            IndexSum--;
        }
    }
    else //means Index2=-1
    {
        //printf("2\n");

        while(Index2>=0)
        {
            //printf("sum[%d]=%d\n",IndexSum,sum[IndexSum]);
            c=sum[IndexSum]+var2[Index2];
            //printf("c=%d\n",c);
            sum[IndexSum]=c%10;
            //printf("sum[%d]=%d\n",IndexSum,sum[IndexSum]);
            sum[IndexSum-1]=sum[IndexSum-1]+1.0*c/10;
            //printf("sum[%d]=%d\n",IndexSum-1,sum[IndexSum-1]);
            Index2--;
            IndexSum--;
        }
    }
    printf("calculated sum=");

    for (IndexSum=0;IndexSum<len1+len2;IndexSum++)
    {
        printf("%d",sum[IndexSum]);
    }
    free(sum);
}



 void multiplication(int var1[], int var2[], int len1, int len2,int *product)
 {
     printf("multi\n");
     int *temp;
     temp=(int*)malloc((len1+len2)*sizeof(int));//what is the max size??
     int c;
     int MaxIndex1=len1-1;
     int MaxIndex2=len2-1;
     printf("MaxIndex2=%d\n",MaxIndex2);
     int kmax=len1+len2-1;//k is the index of the temp array
     int  i=0,j=0,k=0,p=0,q;
     for (k=0;k<len1+len2;k++)
     {
         temp[k]=0; //initialize it as -1 or 0? 0 is convenient in sum
         product[k]=0;
     }

      for (j=MaxIndex2;j>=0;j=j-1)
     {
                printf("index of denominator j=%d\n",j);
                int k=kmax;
                //printf("kmax=%d\n",kmax);
                //int kstart=kmax-(MaxIndex2-j);
                for (p=0;p<MaxIndex2-j;p=p+1)//for (k=len1+len2-1;k>kstart;k=k-1) how many 0 should be put in
                {
                    temp[k]=0;
                    //printf("when k=%d, temp[k]=%d\n",k,temp[k]);
                    k=k-1;
                }

                for (i=MaxIndex1;i>=0;i=i-1)//j is fixed in each of this for loop
                {
                    printf("i=%d\n",i);
                    //printf("var1[%d] * var2[%d]=%d * %d\n",i,j,var1[i],var2[j]);
                    c=var1[i]*var2[j];
                    printf("original c=%d\n",c);
                    if (i!=len1-1)
                    {
                        //printf("k=%d,temp[k]=%d\n",k,temp[k]);
                        c=c+temp[k];//+?????
                        //printf("new c=%d\n",c);
                    }
                    temp[k]=c%10;
                    printf("temp[%d]=%d\n",k,temp[k]);
                    temp[k-1]=c/10;
                    printf("temp[%d]=%d\n",k-1,temp[k-1]);
                    k=k-1;
                }
        printf("\n add temp to product \n");
        int d=0;
        for (k=kmax;k>=0;k--)
        {
            printf("product[%d]=%d  ",k,product[k]);
        }
        for (k=kmax;k>=0;k--)
        {
                printf("k=%d\n",k);
                //printf("temp[k]=%d   ",temp[k]);
                printf("product[%d]=%d   ",k,product[k]);
                //printf("d=%d   ",d);
                d=temp[k]+product[k];
                printf("d=%d=%d+%d\n",d,temp[k],product[k]);
                product[k]=d%10;
                printf("d=%d\n,product[%d]=%d\n",d,k,product[k]);
                product[k-1]=product[k-1]+(d/10);
                printf("product[%d]=%d\n", k-1,product[k-1]);
                printf("\n");
        }
                printf("\n temporary product result is:");
                for (q=0;q<len1+len2;q=q+1)
                {
                    printf("%d",product[q]);
                }
        }
        //SumForMulti(product, temp, len1+len2, len1+len2, product);//means product=product+temp;
        //sum(int var1[], int var2[], int len1, int len2, int *sum)
        printf("\n\n\n");

        printf("final product result is: \n");
        for (k=0;k<len1+len2;k++)
        {
            printf("%d",product[k]);
        }
        printf("\n\n");
    //free(product);
 }

int main()
{
    char str1[10];
    int len1;
    int i;
    printf("enter number:");
    scanf("%s",str1);
    len1=len(str1);
    printf("length of the first string =%d\n",len1);
    int var1[len1];
    for (i=0; i<len(str1); i++)
    {
        var1[i]=str1[i]-'0';
        printf("%d",var1[i]);
    }
    printf("\n");
    //printf("max index=%d, value of final digit=%d\n",len1-1,var1[len1-1]); //4 digits do not work

    char str2[10];
    int len2;
    printf("enter number:");
    scanf("%s",str2);
    len2=len(str2);
    printf("length of the second string =%d\n",len2);
    int var2[len2];
    for (i=0; i<len(str2); i++)
    {
        var2[i]=str2[i]-'0';//var1[i]=atoi(str1[i]);
    }
    //printf("max index=%d, value of final digit=%d\n",len2-1,var2[len2-1]);

    int *PRODUCT;
    PRODUCT=(int*)malloc((len1+len2)*sizeof(int));
    multiplication(var1, var2, len1,len2, PRODUCT);
    //free(PRODUCT);
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
//single integral
double fun(double x)
{
    return x;//x*x/2+3*x-1/x
}
double SingleIntegral(double lowBound, int n, double dx)
{
    int i;
    double xi,rectangleArea,sum;
    for (i=0;i<n;i++)
    {
        double xi=lowBound+i*dx;
        double funValue=fun(xi);
        double rectangleArea=funValue*dx;
        sum=sum+rectangleArea;
    }
    return sum;
}
int main()
{
    double lowBound=4;
    double upBound=7;
    int n=5000;
    double dx=(upBound-lowBound)/n;
    double result=SingleIntegral(lowBound,n, dx);
    printf("%f",result);
}



//double integral(unfinished)
double DoubleIntegral(double lowBound1, double lowBound2, int n, double dx,double dy)
{
    int i;
    double xi,rectangleArea,sum;
        for (i=0;i<n;i++)
        {
            double xi=lowBound+i*dx;
            double funValue=fun(xi);
            double rectangleArea=funValue*dx;
            sum=sum+rectangleArea;
        }
    return sum;
}
int main()
{
    double lowBound1=4;
    double upBound1=7;
    double lowBound2=5;
    double upBound2=8;
    int n=5000;
    double dx=(upBound-lowBound)/n;
    double result=DoubleIntegral(lowBound,n, dx);
    printf("%f",result);
}

log(0.5)
sin(0.5)
/*
    double y;
    y=tan(0.5);
    printf("%f",y);
    return 0;
    */

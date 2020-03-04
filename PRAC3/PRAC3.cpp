// PRAC3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
typedef struct
{
    int day;
    int month;
    int year;

} MyDate;
double DOUBLE_ARRAY[10] = {1, 2.4 ,1.3, 48.1,6,8.2,4.6, 9.154, 2.2};

int dayDifference(MyDate start, MyDate end);
void comparison(int* p, double* q);

//Q_4
double average(double* a, int a_size);
double maximum(double* a, int a_size);


int main()
{
    //q1
    MyDate s, e;
    s = { 12,12,2001 };
    e = { 13,12,2002 };
    cout << "Q1" << endl;
    cout << dayDifference(s, e)<<endl<<endl;

    //q3
    int myInt = 10;
    double myDouble = 0.4;
    
    int* p = &myInt;
    double* q = &myDouble;

    
    cout << "Q3" << endl;
    comparison(p, q);

    cout <<"*p:     "<< *p <<endl;
    cout <<"*q:     "<< *q << endl;
    cout << endl;

    //q4
    cout << "Q4" << endl;
    cout<<average(DOUBLE_ARRAY, 2)<<endl;
    cout<<maximum(DOUBLE_ARRAY, 2)<<endl;
    

}

//Q_1
int leapyearcorrection_sincezero(int year) {
    int correction = 0;
    for (int i = 0; i < year; i++)
    {
        if (i % 4 == 0) 
        {
            if (i % 100 == 0) 
            {
                if (i% 400==0)
                {
                    correction++;
                }
            }
            else 
            { 
                correction++; 
            }
        }
    }
    return correction;
}
int countDaysForMonths(int month) {
    int daycount = month*31; //default 31 day month
    for (int i = 1; i < month; i++)
    {
        if ((month <= 7 && month % 2 == 0) || (month > 7 && month % 2 == 1)) //adjust all short months by -1
        { 
            daycount--; 
        }
    }
    if (month > 2) //adjust for feb if it has completely passed
    {
        daycount -= 2;
    }
    return daycount;
}
int dayDifference(MyDate start, MyDate end)
{
    int ZerotoStart = start.year * 365 + countDaysForMonths(start.month) + start.day + leapyearcorrection_sincezero(start.year);
    int ZerotoEnd = end.year * 365 + countDaysForMonths(end.month) + end.day + leapyearcorrection_sincezero(end.year);
    return abs(ZerotoEnd-ZerotoStart);
}



//Q_3
void comparison(int* p, double* q) 
{
    cout << "p:     " << (unsigned long)p << endl;
    cout << "p+1:   " << (unsigned long)(p+1) << endl;

    cout << "q:     " << (unsigned long)q << endl;
    cout << "q+1:   " << (unsigned long)(q+1) << endl;

}

//Q_4
double average(double *a, int a_size) 
{
    double av = 0;
    for (int i = 0; i < a_size; i++)
    {
        av += *a;
        a++;
    }

    av = av / a_size;

    return av;

}

double maximum(double* a, int a_size)
{
    if (a_size == 0) { return NULL; }

    double max = *a;
    try
    {
        for ( int i = 1; i < a_size; i++)
        {
            a++;
            if (*a > max)
            {
                max = *a;
            }
            
        }
        return max;

    }
    catch (const std::exception&)
    {
        return NULL;
    }

}
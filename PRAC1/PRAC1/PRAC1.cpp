
#include <iostream>
#include <cmath>
using namespace std;

//question 1
int findmin(double num1, double num2);
int HCF(int num1, int num2);
int LCM(int num1, int num2);
int FibonacciAtIndex(int n);
int drawDiamond(int height);
int drawZigZag(int height);

//question 2
int calcChange(double price, double paid);

//question 3
int quadratic(int a, int b, int c);

int main()
{   
    /** 
    question 1 
    **/
        double num1, num2;
        cout << "enter a number \n";
        cin >> num1;
        cout << "enter another number \n";
        cin >> num2;

        //min value
        cout << "the minimum value of " << num1 << " and " << num2 << " is " << findmin(num1, num2)<<endl;
        //hcf
        cout << "the HCF of " << num1 << " and " << num2 << " is " << HCF(num1, num2) << endl;
        //LCM
        cout << "the LCM of " << num1 << " and " << num2 << " is " << LCM(num1, num2) << endl;
        //fibonacci
        cout << "the fibonacci number a index " << num1 << " is " << FibonacciAtIndex(num1) << endl;
        cout << "the fibonacci number a index " << num2 << " is " << FibonacciAtIndex(num2) << endl;
        //drawing shapes
        int size = 0;
        cout << "enter a size for the shapes \n";
        cin >> size;
        drawDiamond(size);
        drawZigZag(size);
       
    /**
    question 2
    **/
        double price;
        double paid;
        cout << "enter the price\n";
        cin >> price;
        cout << "enter the amount paid\n";
        cin >> paid;
        calcChange(price, paid);

    /**
    question 3
    **/
        int a, b, c;
        cout << "enter a , b and c"<<endl;
        cin >> a >> b >> c;
        quadratic(a, b, c);



    return 0;
}

int findmin(double num1, double num2)
{
    return num1<num2? num1: num2;
}

int HCF(int num1, int num2)
{
    int maxpossible = findmin(num1, num2) / 2;
    for (int i = maxpossible; i > 0; i--)
    {
        if ((num1 % i == 0) && (num2 % i == 0)) 
        {
            return i;
        }
    }
    return 0;
}

int LCM(int num1, int num2){
    //lcm <= product
    int maxpossible = num1 * num2;

    //lcm >= max of the two nums
    int minpossible = num1 > num2 ? num1 : num2;

    for (int i = minpossible; i <= maxpossible; i++)
    {
        if ((i % num1 == 0) && (i % num2 == 0))
            return i;
    }
    return 0;
}

int FibonacciAtIndex(int n)
{
    if (n == 0) { return 0; }
    else if (n == 1) { return 1; }
    else
    {
        return (FibonacciAtIndex(n - 1) + FibonacciAtIndex(n - 2));
    }
}

int drawDiamond(int height){
    //upper half
    int spaces = height - 1;

    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < spaces; j++)
        {
            cout << " ";

        }
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";

        }
        cout << "\n";
        spaces--;

    }

    //reverse for lower half
    spaces = 0;

    for (int i = height; i > 0; i--)
    {

        for (int j = 0; j < spaces; j++)
        {
            cout << " ";

        }
        for (int j = 0; j < i; j++)
        {
            cout << "* ";

        }
        cout << "\n";
        spaces++;

    }




    return 0;
}

int drawZigZag(int level){
    //4 levels per zig, 4 levels per zag
    for (int i = 0; i < level; i++)
    {
        //zig
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < j; k++)
            {
                cout << " ";
            }
            cout<< "* * * \n" ;
        }
        //zag
        for (int j = 4; j >= 0; j--)
        {
            for (int k = 0; k < j; k++)
            {
                cout << " ";
            }
            cout << "* * * \n";
        }

    }
    


    return 0;
}

int calcChange(double price, double paid)
{
    cout << "change programme \n";
    double denominations[9] = { 50,    20,     10,      5,      1,      0.5,    0.2,    0.1,    0.05};
    double totalOwed = paid - price;

    if (price > paid) 
    { 
        cout << "customer still owes R" << (-1* totalOwed); 
        return 0;
    }
    if (price == paid) 
    { 
        cout << "no change owed"; 
        return 0;
    }
    else 
    {
        int i = 0;
        //sequentially subtract the highest denomination less than or equal to remaining total
        cout << "change owed:"<<totalOwed<<endl;
        while (totalOwed > 0.05)
        {
            while (totalOwed >= denominations[i]) {
                totalOwed -= denominations[i];
                if (i < 6) {
                    cout << "R " << denominations[i] << endl;
                }
                else {
                    cout << 100 * denominations[i] << "c";
                }
                

            }
            
            i++; 
        }
        if (totalOwed > 0) { cout << "5c"; }

        return 0;
    }
}

int quadratic(int a, int b, int c)
{
    int discrim = b * b - 4 * a * c;

    if (discrim < 0)
    {
        cout << "no solution";
    }
    else 
    {
        int x1 = (-1 * b -sqrt(discrim)) / (2 * a);
        int x2= (-1 * b + sqrt(discrim)) / (2 * a);

        cout << "x1 = " << x1 << endl;

        if (x2 != x1)
        {
            cout << "x2 = " << x2 << endl;
        }
    }
    


    return 0;
}


// Prac2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <stack>
#include <string>

using namespace std;
int rotatePoint(double& py, double& px, double alpha);
int longDiv(int dividend, int divisor);
int reCalcSpaces(int minuend, int subtrahend, string &spaces);//finds the difference in order of magnitude, between a minuend and subtrahend, given the minuend and SUBTRAHEND. then adds that many spaces to the spaces variable

int main()
{  
    int choice=2;
    do 
    {
        cout << "pick a question: 2,3,4"<<endl<<"give any other input to terminate"<<endl;
        cin >> choice;


        //Q_2
        if (choice == 2)
        {
            double px = 0;
            double py = 0;
            double alpha = 0;

            cout << "enter x of point: " << endl;
            cin >> px;
            cout << "enter y of point: ";
            cin >> py;
            cout << "enter angle of rotation: ";
            cin >> alpha;

            rotatePoint(px, py, alpha);
            cout << "new point is " << endl << "X: " << px << ", Y" << py << endl;
        }




        //Q_3
        else if (choice == 3)
        {
            int dividend = 0;
            int divisor = 1;
            cout << "enter dividend" << endl;
            cin >> dividend;
            cout << "enter divisor";
            cin >> divisor;
            if (divisor == 0)
            {
                cout << "cannot divide by zero";
            }
            else
            {
                longDiv(dividend, divisor);
            }
        }







        cout << endl;
    } while (choice>=2 && choice<=4);
    
        
    return 0;
}

//q_2
int rotatePoint(double &py, double &px, double alpha)
{
    double qx = px*cos(alpha) + py*sin(alpha);
    double qy = -1 * px * sin(alpha) + py * cos(alpha);
    py = qy;
    px = qx;

    return 0;
}
//q_3
int longDiv(int dividend, int divisor)
{
    //represent the dividend as a stack where the earlier digits are higher up.
    int splittingDividend = dividend;
    stack<int> dividendStack;
    while (splittingDividend > 0)
    {
        dividendStack.push(splittingDividend % 10);
        splittingDividend /= 10;
    }

    //prepare for division
    int subdividend = 0;//the parts of the original dividend carried down to the next level in the working
    int answerElement = 0;//a digit to add onto the answer
    int subtrahend = 0;//what is subtracted at each level from the current subdividend
    int answer = 0;//at the end of the loop this will hold the final answer
    string gradualSpaces = " ";//as we go down levels, the working moves right so we can attach a digit to the end of a difference 
    string immediateSpaces = "";//the space subdividend(minuend) and subtrahend in each level if they are of different orders of magnitude

    //print initial problem
    cout <<gradualSpaces<<" "<<dividend << "/"<<divisor<<":"<<endl;

    while (!dividendStack.empty())//while there are more digits to bring down
    {
        //bring down a digit, accounting for which column it should be in
        subdividend *= 10;
        subdividend += dividendStack.top();
        dividendStack.pop();
        cout <<gradualSpaces<<" "<<subdividend<<endl;

        //calculate the next digit in the answer
        answerElement = subdividend / divisor;

        //calculate the next subtrahend
        subtrahend = answerElement * divisor;

        //incase the subdividend and subtrahend differ in OoM, prepare a string of spaces, with a length of that difference 
        reCalcSpaces(subdividend, subtrahend, immediateSpaces);

        //DEBUGGING
        //cout << "____________________________________________" << subdividend <<immediateSpaces<<subtrahend<< endl;

        //print out subtrahend, formatted and accounting for column
        cout << gradualSpaces<<immediateSpaces<<"-" << subtrahend << endl;

        //append the most recent answer digit onto the answer
        answer *= 10; answer += answerElement;

        //reset immediateSpaces, since the OoM difference of the next pair of subdividend and subtrahend is not known.
        immediateSpaces = "";

        //determine how far right gradualSpaces needs to move the next step of the process
        reCalcSpaces(subdividend, subdividend-subtrahend, gradualSpaces);

        //find the leftmost digit of the next subdividend. Iin the next iteration, the next digit will be appended, and then only will it be printed
        subdividend = subdividend - subtrahend;
        //print a seperator between levels
        cout <<gradualSpaces<< "---" << endl;

        //DEBUGGING
        //cout << " " << subdividend << endl;

    }
    //last difference will be omitted due to loop condition. print it, accoutning for column
    cout <<gradualSpaces<<" "<< subdividend << endl;

    cout << "answer = " << answer<<endl;

    //the subdividend is the remainder at this point
    cout << "r= "<<subdividend << endl;

    //exit
    return 0;
}

int reCalcSpaces(int minuend, int subtrahend, string& spaces)
{
    string sub = to_string(subtrahend);
    string min = to_string(minuend);
    int diff = min.length() - sub.length();

    //DEBUGGING
    //cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << min.length() << " " << sub.length() << endl;
    for (int i = 0; i < diff; i++)
    {
        spaces += " ";
    }
    return 0;
}

/*deprecated
int reCalcGradualSpaces(int minuend, int subtrahend, string &spaces) 
{
   string difference = to_string(minuend - subtrahend);
   string min = to_string(minuend);
   int diff = min.length() - difference.length();

   //cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << min.length()<<" "<< difference.length()<< endl;
   for (int i = 0; i < diff; i++)
   {
       spaces += " ";
   }
   //cout << "." << spaces << "."<<endl;
   return 0;
}*/

//q4



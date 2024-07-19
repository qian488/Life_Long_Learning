#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>
#include<string>
#define PI 3.14

using namespace std;

void addxy();
void RadiusToArea();
void RandTest();
void RandScope();
void CharTest();
void StringTest();

int main()
{
    double radius;
    int file_size = 100;

    addxy();
    RadiusToArea();
    RandTest();
    RandScope();
    CharTest();
    StringTest();
    cout << "That are OK!" << endl;

    return 0;
}

void addxy()
{
    double x, y;
    cout << "Enter values for x and y :";
    cin >> x >> y;
    cout << "x+y=" << x + y << endl;
    cout << "addxy is Ok!" << endl;
}

void RadiusToArea()
{
    double radius;
    cout << "Enter radius:";
    cin >> radius;
    double area = PI * pow(radius,2.0);
    cout << area << endl;
    cout << "RadiusToArea is Ok!" << endl;
}

void RandTest()
{
    srand(time(0));
    int number = rand() % 10;
    cout << number << endl;
    cout << "RandTest is Ok!" << endl;
}

void RandScope()
{
    const short MinValue = 0;
    const short MaxValue = 9;

    srand(time(0));
    short first = rand() % (MaxValue - MinValue + 1) + MinValue;
    short second = rand() % (MaxValue - MinValue + 1) + MinValue;

    cout << first << "," << second << endl;
    cout << "RandScope is Ok!" << endl;
}

void CharTest()
{
    char char1[13] = "bing";
    char char2[13] = "google";
    char char3[13];
    int len;
    cout << "char1:bing" << endl;
    cout << "char2:google" << endl;
    strcpy(char3, char1);
    cout << "strcpy(char3,char1):" << char3 << endl;
    strcat(char1, char2);
    cout << "strcat(char1,char2):" << char1 << endl;
    len = strlen(char1);
    cout << "strlen(char1):" << len << endl;
    cout << "CharTest is Ok!" << endl;
}

void StringTest()
{
    string str1 = "bing";
    string str2 = "google";
    string str3;
    int  len ;
    cout << "str1:bing" << endl;
    cout << "str2:google" << endl;
    str3 = str1;
    cout << "str3 : " << str3 << endl;
    str3 = str1 + str2;
    cout << "str1 + str2 : " << str3 << endl;
    len = str3.size();
    cout << "str3.size() :  " << len << endl;
    cout << "StringTest is Ok!" << endl;
}

//Student grading system

#include <iostream>
#include <string>

int main() 
{
    using namespace std;

    string name;
    int roll, seat_no, english, maths, science, history, geography, IT, tot;
    float per;
    string grade;

    cout << "\n Enter Student's name = ";
    cin >> name;

    cout << "\n Enter Student's roll no. = ";
    cin >> roll;

    cout << "\n Enter Seat no. = ";
    cin >> seat_no;

    cout << "\n Enter marks in English: ";
    cin >> english;

    cout << "\n Enter marks in Maths: ";
    cin >> maths;

    cout << "\n Enter marks in Science: ";
    cin >> science;

    cout << "\n Enter marks in History: ";
    cin >> history;

    cout << "\n Enter marks in Geography: ";
    cin >> geography;

    cout << "\n Enter marks in Information Technology: ";
    cin >> IT;

    tot = english + maths + science + history + geography + IT;
    per = tot / 6.0;

    cout << "\n Total marks = " << tot;
    cout << "\n Percentage = " << per;

    if (tot >= 550 && tot <= 600) 
	{
        grade = "A+";
    } 
	else if (tot >= 450 && tot < 550) 
	{
        grade = "A";
    } 
	else if (tot >= 350 && tot < 450) 
	{
        grade = "B+";
    } 
	else if (tot >= 250 && tot < 350) 
	{
        grade = "B";
    } 
	else if (tot >= 150 && tot < 250) 
	{
        grade = "C+";
    } 
	else 
	{
        grade = "C";
    }

    cout << "\n Grade = " << grade;
    
    
    if (grade == "A+" || grade == "A") 
    {
        cout << "\n Highest grade";
    } 
    else if (grade == "B+" || grade == "B") 
    {
        cout << "\n Average grade";
    } 
    else 
    {
        cout << "\n Lowest grade";
    }

}



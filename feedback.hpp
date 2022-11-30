#include <bits/stdc++.h>
#include "patientgiving.hpp"
#include "doctorgiving.hpp"
#include "patient.hpp"
#include "doctor.hpp"
using namespace std;

class Feedback_Directory
{
public:
    void ischeck();
};

void Feedback_Directory ::ischeck()
{
    cout << "-------------------------------------------" << endl;
    cout << "Welcome to the Feedback Directory" << endl;
    cout << "If you are a Doctor select '1" << endl;
    cout << "If you are patient select '2" << endl;
    cout << "-------------------------------------------" << endl;

    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        feedbdoctor.enterfeedback();
        break;
    }
    case 2:
    {
        feedbpatient.enterfeedback();
        break;
    }
    default:
    {
        cout << "Not a valid input. Please enter a valid choice" << endl;
        Feedback_Directory ::ischeck();
    }
    }
}
#include <bits/stdc++.h>
#include "doctor.hpp"
#include "patient.hpp"
using namespace std;
string x; // patient uid
string y; // doctor uid
class feedbackd
{
public:
    int overallrate;
};
class feedbdoctor
{
public:
    void enterfeedback();
};

bool Doctors_Directory ::searc()
{
    fstream myFile;
    myFile.open("DoctorsData.csv", ios::in);
    if (myFile.peek() != EOF)
    {
        while (!myFile.eof())
        {
            DOCTOR temp;
            getline(myFile, temp.UID, ',');

            doctorsDataByUID.insert({temp.UID, temp});
        }
    }
    cout << "Enter the UID of the Doctor: ";
    string y;
    getline(cin, y);
    auto itr = doctorsDataByUID.find(y);

    if (itr != doctorsDataByUID.end())
    {
        myFile.close();
        return false;
    }
    else
    {
        myFile.close();
        return true;
    }
}

void enterfeedback()
{
    void enterfeedback()
    {
        Patients_Directory ptd;
        Doctors_Directory dtd;

        if (dtd.searc())
        {
            ptd.givefeedback();
        }
    }
}

void patients_Directory ::givefeedback()
{
    fstream myFile;
    myFile.open("patientsData.csv", ios::in);
    if (myFile.peek() != EOF)
    {
        while (!myFile.eof())
        {
            PATIENT temp;
            getline(myFile, temp.UID, ',');
            getline(myFile, temp.rating, ',');

            patientsDataByUID.insert({temp.UID, temp});
        }
    }
    cout << "Enter the UID of the Patienr you want to give feedback" << endl;
    cin >> x;
    cin.ignore();
    if (ispatientisvited(x, y)) ///  make a boolean function to check is doctor checkup the patient or not
    {
        string temp;
        getline(cin, temp);
        auto it = patientsDataByUID.find(temp);
        if (it != patientsDataByUID.end())
        {

            cout << " Give the feedback to the patient   between 1 to  5" << endl;
            int intfeed;
            cin >> intfeed;

            it->second.rating = to_string(intfeed);

            fstream myNewFile;
            myNewFile.open("PatientsDataNew.csv", ios::out);

            for (auto itr = patientsDataByUID.begin(); itr != doctorsDataByUID.end(); itr++)
            {
                myNewFile << itr->second.UID << ',' << itr->second.name << ',' << itr->second.department << ',' << itr->second.employType << ',' << itr->second.start << ',' << itr->second.end << ',' << itr->second.rating << ',' << itr->second.patCount << ',' << itr->second.contact << ',' << itr->second.mail;
                if (next(itr) != patientsDataByUID.end())
                    myNewFile << "\n";
            }

            myFile.close();
            myNewFile.close();
            remove("PatientsData.csv");
            rename("PatientsDataNew.csv", "PatientsData.csv");
        }
    }
}

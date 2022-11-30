#include <bits/stdc++.h>
#include "patient.hpp"
#include "doctor.hpp"
using namespace std;
string x;
string y;

class feedbackp
{
public:
    int overallrate;
};

bool Patients_Directory ::search()
{
    fstream myFile;
    myFile.open("PatientsData.csv", ios::in);
    if (myFile.peek() != EOF)
    {
        while (!myFile.eof())
        {
            PATIENT temp;
            getline(myFile, temp.UID, ',');

            patientsDataByUID.insert({temp.UID, temp});
        }
    }
    cout << "Enter the UID of the patient: ";
    string x;
    getline(cin, x);
    auto itr = patientsDataByUID.find(x);

    if (itr != patientsDataByUID.end())
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

class feedbpatient
{
public:
    void enterfeedback();
};
void enterfeedback()
{
    Patients_Directory ptd;
    Doctors_Directory dtd;

    if (ptd.search())
    {
        dtd.givefeedback();
    }
}

void Doctors_Directory ::givefeedback()
{
    fstream myFile;
    myFile.open("DoctorsData.csv", ios::in);
    if (myFile.peek() != EOF)
    {
        while (!myFile.eof())
        {
            DOCTOR temp;
            getline(myFile, temp.UID, ',');
            getline(myFile, temp.rating, ',');
            getline(myFile, temp.patCount, ',');

            doctorsDataByUID.insert({temp.UID, temp});
        }
    }
    cout << "Enter the UID of the Doctor you want to give feedback\n";

    cin >> y;
    cin.ignore();
    if (isdoctorvisited(x, y)) // make a boolean function to check patient is visited to the doctor or not..
    {
        string temp;
        getline(cin, temp);
        auto it = doctorsDataByUID.find(temp);
        if (it != doctorsDataByUID.end())
        {

            cout << " Give the feedback to the doctor   between 1 to  5" << endl;
            int intfeed;
            cin >> intfeed;
            int poorana = stoi(it->second.patCount);
            int z = ((intfeed / poorana) + stoi(it->second.rating));

            it->second.rating = to_string(z);

            fstream myNewFile;
            myNewFile.open("DoctorsDataNew.csv", ios::out);

            for (auto itr = doctorsDataByUID.begin(); itr != doctorsDataByUID.end(); itr++)
            {
                myNewFile << itr->second.UID << ',' << itr->second.name << ',' << itr->second.department << ',' << itr->second.employType << ',' << itr->second.start << ',' << itr->second.end << ',' << itr->second.rating << ',' << itr->second.patCount << ',' << itr->second.contact << ',' << itr->second.mail;
                if (next(itr) != doctorsDataByUID.end())
                    myNewFile << "\n";
            }

            myFile.close();
            myNewFile.close();

            remove("DoctorsData.csv");
            rename("DoctorsDataNew.csv", "DoctorsData.csv");
        }
        else
        {
            cout << "Staff Not Found." << endl;
            myFile.close();
        }
    }
}
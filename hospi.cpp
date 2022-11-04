#include <bits/stdc++.h>
using namespace std;

class Doctor
{
public:
    string aadhar;
    string name;
    string department;
    string staff;
    int start, end;
    double rating;
    unsigned int Patients_Count;
    string contact;
    string Email;

    static unordered_map<string, Doctor> doctorsDataByAadhar;
    static map<string, Doctor> doctorsDataByName;
    static unordered_map<string, Doctor> doctorsDataByDepartment;
    static unordered_map<string, Doctor> doctorsDataByStaff;
    static unordered_map<string, Doctor> doctorsDataByContact;
    static unordered_map<string, Doctor> doctorsDataByEmail;
    static unordered_map<double, Doctor> doctorsDataByRating;
    static unordered_map<unsigned int, Doctor> doctorsDataByPatCount;
    static unordered_map<unsigned int, Doctor> doctorsDataByStartTime;
    static unordered_map<int, Doctor> doctorsDataByEndTime;

    void insertDoctor();
};

void Doctor ::insertDoctor()
{
    fstream fout;
    fout.open("dataDoc.csv", ios::out | ios::app);

    Doctor temp;
    cout << "Enter the Aadhar Card Number of the Doctor" << endl;
    cin >> temp.aadhar;
    cout << "Enter the Name of the Doctor" << endl;
    cin >> temp.name;
    cout << "Enter the Department of the Doctor" << endl;
    cin >> temp.department;
    cout << "Enter the Staff Type of the Doctor" << endl;
    cin >> temp.staff;
    temp.rating = 0;
    temp.Patients_Count = 0;
    cout << "Enter the Contact Number of the Doctor" << endl;
    cin >> temp.contact;
    cout << "Enter the Email ID of the Doctor" << endl;
    cin >> temp.Email;

    fout << temp.aadhar << ", "
         << temp.name << ", "
         << temp.department << ", "
         << temp.staff << ", "
         << temp.contact << ", "
         << temp.Email
         << "\n";
    // doctorsDataByName.insert({temp.aadhar, temp});
}

int main()
{
    Doctor temp;
    temp.insertDoctor();
    return 0;
}
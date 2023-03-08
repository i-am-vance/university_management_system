#include "iostream"
#include "fstream"

using namespace std;

class Student
{
protected:
    int id;
    string farstname;
    string lastname;
public:
    void Create_student(){
        fstream file;
        file.open("listname.txt", ios::out | ios::app);
        int id_in; 
        string farst_name;
        string last_name;
        cout << "Enter a id :";
        cin >> id_in;
        id = id_in;

        cout << endl << "Enter the first name :";
        cin >> farst_name;
        farstname = farst_name;

        cout << endl << "Enter the last name :";
        cin >> last_name;
        lastname = last_name;

        
        file << id << endl;
        file << farstname << " " << lastname << endl; 
        file.close();
    }

    void student_list(){
        
    }

};

int main(){
    Student student;
    student.Create_student();
    cout << endl;





    return 0;
}
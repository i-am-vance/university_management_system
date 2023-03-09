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
        fstream file_ido;
        fstream file_idi;

        int id = 0;
        int id_out;

        string id_str;

        string farst_name;
        string last_name;

        file.open("listname.txt", ios::out | ios::app);
        file_idi.open("id.txt", ios::in);

        if (!file_idi){
            file_ido.open("id.txt", ios::out);
            file_ido << id;
            file_ido.close();
        }

        while(getline(file_idi, id_str)){
        }
        id_out = atoi(id_str.c_str());
        id_out++;

        cout << "id :" << id_out;

        cout << endl << "Enter the first name :";
        cin >> farst_name;
        farstname = farst_name;

        cout << endl << "Enter the last name :";
        cin >> last_name;
        lastname = last_name;

        
        file << id_out << endl;
        file << farstname << " " << lastname << endl;

        file_ido.open("id.txt", ios::out);
        file_ido << id_out;

        file_ido.close();
        file.close();
        file_idi.close();
    }

    void student_list(){
    system("clear");
    ifstream file("listname.txt");
    int num;
    if (file.is_open()){
        cout << file.rdbuf();
    }
    file.close();
    cout << "Please enter 1 to exit : ";
    cin >> num;
    if (num == 1){
        system("clear");
    }
        
    }
    void find_student(){
        
    }

};

int main(){
    
    Student student1;
    int num, ch;
	do {
        system("clear");
		cout << endl;
		cout << "\t\t" << "*1) Add studet " << endl;
        cout << "\t\t" << "*2) show list student " << endl;
		cout << "\t\t" << "*3) Remove a student " << endl;
		cout << "\t\t" << "*4) Search a student " << endl;
		cout << "\t\t" << "*5) Add Course " << endl;
		cout << "\t\t" << "*6) rmove Course " << endl;
		cout << "\t\t" << "*7) Search a Course " << endl;
		cout << "\t\t" << "*8) " << endl;
		cout << "\t\t" << "*9) Exit " << endl;
 		cout << endl;
		cout << "\t\t" << "Enter your  choice: " ;
		cin >> ch;
		cout << endl;

		switch(ch){
			case 1:
				student1.Create_student();
				break;
			case 2:
                student1.student_list();
				break;
			case 3:

				break;
			case 4:

				break;
			case 5:

				break;
			case 6:

				break;
			case 7:

				break;
			case 8:

				break;
			case 9:
				system("clear"); //i use linux
				cout << "by by ";
				break;
			default:
				cout << "select Your option (1-9)";
				break;	
		}

	} while(ch!=9);
	


    return 0;
}
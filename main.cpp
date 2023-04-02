#include "iostream"
#include "fstream"

using namespace std;

class Student
{
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

        while(getline(file_idi, id_str)){}

        id_out = atoi(id_str.c_str());
        id_out++;

        cout << "id :" << id_out;

        cout << endl << "Enter the first name :";
        cin >> farst_name;

        cout << endl << "Enter the last name :";
        cin >> last_name;
        
        file << id_out << endl;
        file << farst_name << " " << last_name << endl;

        file_ido.open("id.txt", ios::out);
        file_ido << id_out;

        file_ido.close();
        file.close();
        file_idi.close();
    }

    void student_list(){

    system("clear");
    
    ifstream file("listname.txt");

    string exit;
    int num;

    if (file.is_open()){
        cout << file.rdbuf();
    }

    file.close();
    
    while(true){
        cout << "Type exit or q :" << endl;
        cin >> exit;
        if (exit == "exit" || exit == "q"){
            break;
        }
    }
        
    }
    void find_student(){

        system("clear");

        fstream file1;
	    fstream file2;

	    string id_in;
        string id;
	    string name;

        string exit;

	    int number;
	    int num1 = 1;
	    int num2 = 1;

        cout << "Enter the student ID :";
	    cin >> id_in;
	    file1.open("listname.txt", ios::in);
	    file2.open("listname.txt", ios::in);
	    if (!file1){
		    cout << "file not found";
	    }else{
		    while(getline(file1, id)){
			    if (num1%2 != 0 && id_in == id){
			 	    number = num1;
			    }
			num1++;
		    }
		    number++;
		    while(getline(file2, name)){
			    if (num2 == number){
				    cout << name << endl;
			    }
			num2++;
		    }
		
	    }
        file1.close();
        file2.close();
        while(true){
            cout << "Type exit or q :" << endl;
            cin >> exit;
            if (exit == "exit" || exit == "q"){
                break;
            }
        }
        
    }
    void remove_student(){
        fstream file1;
	    fstream file2;

	    ofstream ofs1;
	    ofstream ofs2;

	    string filename = "listname.txt";
	    string line;

	    string id_in;
	    string id;
	    string name;

	    char q;

	    int lineToRemove;
	    int lineNumber = 0;

	    int number;
	    int num1 = 1;
	    int num2 = 1;

	    cout << "Enter the student id :";
	    cin >> id_in;
	    file1.open("listname.txt", ios::in);
	    file2.open("listname.txt", ios::in);
	    if (!file1){
		    cout << "file not found";
	    }else{
		    while(getline(file1, id)){
			    if (num1%2 != 0 && id_in == id){
				    number = num1;
			    }
		    num1++;
		    }
		    lineToRemove = number;
		    number++;
		    while(getline(file2, name)){
			    if (num2 == number){
				    cout << name << endl;
			    }
		    num2++;
		    }
	    }
	    cout << "Are you sure of deleting this student? y/n :";
	    cin >> q;
	    if (q == 'y'){
		    ifstream inFile(filename);
		    ofstream tempFile("temp.txt");

		    while (getline(inFile, line)) {
			    ++lineNumber;

			    if (lineNumber == lineToRemove || lineNumber == lineToRemove + 1){
				    continue;
			    }

			    tempFile << line << endl;
		    }
		    inFile.close();
		    tempFile.close();

		    remove(filename.c_str());
		    rename("temp.txt", filename.c_str());
	    }

	    file1.close();
	    file2.close();
    }
};

class Course : public Student
{

};
int main(){
    
    Student student1;
    int ch;
	do {
        system("clear");
		cout << endl;
		cout << "\t\t" << "*1) Add studet " << endl;
        cout << "\t\t" << "*2) show list student " << endl;
		cout << "\t\t" << "*3) Search a student " << endl;
		cout << "\t\t" << "*4) Remove the student " << endl;
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
                student1.find_student();
				break;
			case 4:
                student1.remove_student();
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
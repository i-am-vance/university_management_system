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
		fstream file_theoretical;
		fstream file_practical;

        int id = 0;
        int id_out;

        string id_str;

        string farst_name;
        string last_name;

		string theoretical = "theoretical.txt";
		string practical = "practical.txt";

		string theoretical_out;
		string practical_out;

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

		theoretical_out = to_string(id_out);
		theoretical_out.append(theoretical);

		practical_out = to_string(id_out);
		practical_out.append(practical);

		file_practical.open(practical_out, ios::out);
		
		file_theoretical.open(theoretical_out, ios::out);

		file_practical.close();
		file_theoretical.close();

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

		string theoretical = "theoretical.txt";
		string practical = "practical.txt";

		string theoretical_out;
		string practical_out;

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

			theoretical_out = id_in;
			theoretical_out.append(theoretical);

			practical_out = id_in;
			practical_out.append(practical);

			remove(theoretical_out.c_str());
			remove(practical_out.c_str());
			
	    }

	    file1.close();
	    file2.close();
    }
};

class Course : public Student
{
public:
	void show_course(){
		fstream file_practical;
		fstream file_theoretical;

		fstream file1;
		fstream file2;

		string practical = "practical.txt";
		string practical_out;

		string theoretical = "theoretical.txt";
		string theoretical_out;

		string id_in;
		string id;
		string name;

		string course_practical;
		string course_theoretical;

		string exit;

		bool test = false;

		int number;
		int num1 = 1;
		int num2 = 1;

		int num1_th = 1;
		int num1_pr = 1;

		system("clear");

		cout << "Enter the student id :";
		cin >> id_in;

		file1.open("listname.txt", ios::in);
		file2.open("listname.txt", ios::in);

		if (!file1){
			cout << "file not found";
		}else{
			while(getline(file1, id)){
				if (num1%2 !=0 && id_in == id){
					number = num1;
					test = true;
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

		if (test == true)
		{
			practical_out = id_in;
			practical_out.append(practical);

			file_practical.open(practical_out, ios::in);

			if (!file_practical){
				cout << "file not found";
			}else{
				cout << "practical course :" << endl;
				while(getline(file_practical, course_practical)){
					cout << course_practical << endl;
				}
				cout << endl;
			}

			theoretical_out = id_in;
			theoretical_out.append(theoretical);

			file_theoretical.open(theoretical_out, ios::in);

			if (!file_theoretical){
				cout << "file not found";
			}else{
				cout << "theoretical course :" << endl;
				while(getline(file_theoretical, course_theoretical)){
					cout << course_theoretical << endl;
				}
				cout << endl;
			}
		}
		file_practical.close();
		file_theoretical.close();
		while(true){
			cout << "Type exit or q :" << endl;
			cin >> exit;
			if (exit == "exit" || exit == "q"){
				break;
			}
		}
	}
};

class TheoreticalCourse : public Course
{
public:
	void add_course_theoretical(){
		fstream file_theoretical_1;
		fstream file_theoretical_2;
	
		fstream file1;
		fstream file2;

		string theoretical = "theoretical.txt";
		string theoretical_out;

		string id_in;
		string id;
		string name;

		string id_course;
	
		string math = "math ";
		string physics = "physics ";
		string chemistry = "chemistry "; 
		string geography = "geography ";

		bool test = false;

		bool math_bool = false;
		bool physics_bool = false;
		bool chemistry_bool = false;
		bool geography_bool = false;

		const string math_id = "1";
		const string physics_id = "2";
		const string chemistry_id = "3";
		const string geography_id = "4";

		float score;

		int ch;

		int number;
		int num1 = 1;
		int num2 = 1;

		int num1_id = 1;

		cout << "Enter the student id :";
		cin >> id_in;
	
		file1.open("listname.txt", ios::in);
		file2.open("listname.txt", ios::in);
		
		if (!file1){
			cout << "file not found";
		}else{
			while(getline(file1, id)){
				if (num1%2 !=0 && id_in == id){
					number = num1;
					test = true;
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

		if (test == true)
		{
			theoretical_out = id_in;
			theoretical_out.append(theoretical);

			file_theoretical_1.open(theoretical_out, ios::in);
			file_theoretical_2.open(theoretical_out, ios::app);
		
			if (!file_theoretical_1){
				cout << "file not found";
			}else{
				while(getline(file_theoretical_1, id_course)){
					if (num1_id%2 !=0){
						if (id_course == math_id){
							math_bool = true;
						}else if (id_course == physics_id){
							physics_bool = true;
						}else if (id_course == chemistry_id){
							chemistry_bool = true;
						}else if (id_course == geography_id){
							geography_bool = true;
						}
					}
					num1_id++;
				}
			}

			

			cout << endl;
			cout << "\t\t" << "*1) math " << endl;
			cout << "\t\t" << "*2) physics " << endl;
			cout << "\t\t" << "*3) chemistry " << endl;
			cout << "\t\t" << "*4) geography " << endl;
			cout << "\t\t" << "*5) exit " << endl;
			cout << endl;
			cout << "\t\t" << "Enter your choice: ";
			cin >> ch;
			cout << endl;

			switch(ch){
				case 1:
					if (math_bool == false){
						cout << endl << "Enter the score : ";
						cin >> score;
						if (score > 20){
							score = 20;
						}else if (score < 0){
							score = 0;
						}
						file_theoretical_2 << math_id << endl;
						file_theoretical_2 << math << ":" << score << endl;
					}else{
						cout << "This course has already been added";
					}
					break;
				case 2:
					if (physics_bool == false){
						cout << endl << "Enter the score : ";
						cin >> score;
						if (score > 20){
							score = 20;
						}else if (score < 0){
							score = 0;
						}
						file_theoretical_2 << physics_id << endl;
						file_theoretical_2 << physics << ":" << score << endl;
					}else{
						cout << "This course has already been added";
					}
					break;
				case 3:
					if(chemistry_bool == false){
						cout << endl << "Enter the score : ";
						cin >> score;
						if (score > 20){
							score = 20;
						}else if (score < 0){
							score = 0;
						}
						file_theoretical_2 << chemistry_id << endl;
						file_theoretical_2 << chemistry << ":" << score << endl;
					}else{
						cout << "This course has already been added";
					}
					break;
				case 4:
					if(geography_bool == false){
						cout << endl << "Enter the score : ";
						cin >> score;
						if (score > 20){
							score = 20;
						}else if (score < 0){
							score = 0;
						}
						file_theoretical_2 << geography_id << endl;
						file_theoretical_2 << geography << ":" << score << endl;
					}else{
						cout << "This course has already been added";
					}
					break;
				case 5:
					system("clear");
					break;
				default:
					cout << "select Your option (1-5)";
					break;
			}
			
			file_theoretical_1.close();
			file_theoretical_2.close();
		}
		else
		{
			cout << "Student not found";
		}
	}

	void remove_course_theoretical(){

		fstream file_theoretical_1;
		fstream file_theoretical_2;

		fstream file1;
		fstream file2;

		ofstream ofs1;
		ofstream ofs2;

		string theoretical = "theoretical.txt";
		string theoretical_out;

		string id_course_in;
		string id_course;
		string name_course;

		string line;

		string id_in;
		string id;
		string name;

		char q;

		bool test = false;

		int lineToRemove;
		int lineNumber = 0;

		int number_course;
		int num1_course = 1;
		int num2_course = 1;

		int number;
		int num1 = 1;
		int num2 = 1;

		cout << "Enter the student id : ";
		cin >> id_in;

		file1.open("listname.txt", ios::in);
		file2.open("listname.txt", ios::in);

		if (!file1){
			cout << "file not found";
		}else{
			while(getline(file1, id)){
				if (num1%2 !=0 && id_in == id){
					number = num1;
					test = true;
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

		if (test == true){
			cout << "Enter the course ID : ";
			cin >> id_course_in;

			theoretical_out = id_in;
			theoretical_out.append(theoretical);

			file_theoretical_1.open(theoretical_out, ios::in);
			file_theoretical_2.open(theoretical_out, ios::in);

			if (!file_theoretical_1){
				cout << "file not found";
			}else{
				while(getline(file_theoretical_1, id_course)){
					if (num1_course%2 != 0 && id_course_in == id_course){
						number_course = num1_course;
					}
				num1_course++;
				}
				lineToRemove = number_course;
				number_course++;
				while(getline(file_theoretical_2, name_course)){
					if (num2_course == number_course){
						cout << name_course << endl;
					}
					num2_course++;
				}
			}
			cout << "Are you sure about deleting this course? y/n :";
			cin >> q;
			if (q == 'y'){
				ifstream inFile(theoretical_out);
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

				remove(theoretical_out.c_str());
				rename("temp.txt", theoretical_out.c_str());
			}
			file_theoretical_1.close();
			file_theoretical_2.close();
		}

	}
};

class PracticalCourse : public Course
{
public:
	void add_course_practical()
	{
		fstream file_practical_1;
		fstream file_practical_2;

		fstream file1;
		fstream file2;

		string practical = "practical.txt";
		string practical_out;

		string id_in;
		string id;
		string name;

		string id_course;

		string electrical_lab = "electrical_lab ";
		string computer_lab = "computer_lab ";
		string chemistry_lab = "chemistry_lab ";

		const string electrical_lab_id = "1";
		const string computer_lab_id = "2";
		const string chemistry_lab_id = "3";

		bool test = false;

		bool electrical_lab_bool = false;
		bool computer_lab_bool = false;
		bool chemistry_lab_bool = false;

		float score;

		int ch;

		int number;
		int num1 = 1;
		int num2 = 1;

		int num1_id = 1;

		cout << "Enter the student id :";
		cin >> id_in;
	
		file1.open("listname.txt", ios::in);
		file2.open("listname.txt", ios::in);

		if (!file1){
			cout << "file not found";
		}else{
			while(getline(file1, id)){
				if (num1%2 !=0 && id_in == id){
					number = num1;
					test = true;
				}
				num1++;
			}
			number++;
			while(getline(file2,name)){
				if (num2 == number){
					cout << name << endl;
				}
				num2++;
			}
		}

		file1.close();
		file2.close();

		if (test == true)
		{
			practical_out = id_in;
			practical_out.append(practical);

			file_practical_1.open(practical_out, ios::in);
			file_practical_2.open(practical_out, ios::app);

			if (!file_practical_1){
				cout << "file not found";
			}else{
				while(getline(file_practical_1, id_course)){
					if (num1_id%2 !=0){
						if (id_course == electrical_lab_id){
							electrical_lab = true;
						}else if (id_course == computer_lab_id){
							computer_lab_bool = true;
						}else if (id_course == chemistry_lab_id){
							chemistry_lab_bool = true;
						}
					}
					num1_id++;
				}
			}

			cout << endl;
			cout << "\t\t" << "*1) electrical_lab " << endl;
			cout << "\t\t" << "*2) computer_lab " << endl;
			cout << "\t\t" << "*3) chemistry_lab " << endl;
			cout << "\t\t" << "*4) exit " << endl;
			cout << endl;
			cout << "\t\t" << "Enter your choice: ";
			cin >> ch;
			cout << endl;

			switch(ch){
				case 1:
					if (electrical_lab_bool == false){
						cout << endl << "Enter the score : ";
						cin >> score;
						if (score > 20){
							score = 20;
						}else if (score < 0){
							score = 0;
						}
						file_practical_2 << electrical_lab_id << endl;
						file_practical_2 << electrical_lab << ":" << score << endl;
					}else{
						cout << "This course has already been added";
					}
					break;
				case 2:
					if (computer_lab_bool == false){
						cout << endl << "Enter the score : ";
						cin >> score;
						if (score > 20){
							score = 20;
						}else if (score < 0){
							score = 0;
						}
						file_practical_2 << computer_lab_id << endl;
						file_practical_2 << computer_lab << ":" << score << endl;
					}else{
						cout << "This course has already benn added";
					}
					break;
				case 3:
					if (chemistry_lab_bool == false){
						cout << endl << "Enter the score : ";
						cin >> score;
						if (score > 20){
							score = 20;
						}else if (score < 0){
							score = 0;
						}
						file_practical_2 << chemistry_lab_id << endl;
						file_practical_2 << chemistry_lab << ":" << score << endl;
					}else{
						cout << "This course has already benn added";
					}
					break;
				case 4:
					system ("clear");
					break;
				default:
					cout << "select Your option (1-4)";
					break;
			}
			file_practical_1.close();
			file_practical_2.close();
		}else{
			cout << "Student not found";
		}
		}
};

int main(){
    
    Course student;

	TheoreticalCourse student_theoretical;
	PracticalCourse student_practical;

    int ch;
	do {
        system("clear");
		cout << endl;
		cout << "\t\t" << "*1) Add studet " << endl;
        cout << "\t\t" << "*2) show list student " << endl;
		cout << "\t\t" << "*3) Search a student " << endl;
		cout << "\t\t" << "*4) Remove the student " << endl;
		cout << "\t\t" << "*5) Add Course theoretical " << endl;
		cout << "\t\t" << "*6) Add Course practical " << endl;
		cout << "\t\t" << "*7) Show Course " << endl;
		cout << "\t\t" << "*8) " << endl;
		cout << "\t\t" << "*9) Exit " << endl;
 		cout << endl;
		cout << "\t\t" << "Enter your  choice: " ;
		cin >> ch;
		cout << endl;

		switch(ch){
			case 1:
				student.Create_student();
				break;
			case 2:
                student.student_list();
				break;
			case 3:
                student.find_student();
				break;
			case 4:
                student.remove_student();
				break;
			case 5:
				student_theoretical.add_course_theoretical();
				break;
			case 6:
				student_practical.add_course_practical();
				break;
			case 7:
				student.show_course();
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
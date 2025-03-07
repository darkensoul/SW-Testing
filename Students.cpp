#include "Students.h"

//Branch
Students::Students()
{
}


Students::~Students()
{
}

//turns a vector of students into the StudentList
Students::Students(std::vector<Student> toAdd)
{
	for (int i = 0; i < toAdd.size()+1; ++i)
	{
		StudentList.push_back(toAdd[i]);
	}
}

//add student to the studentlist
void Students::addStudent(Student in_stud){
	StudentList.push_back(in_stud);
}

//deletes the input student from the student list
void Students::deleteStudent(Student out_stud){
	
	std::vector<Student>::iterator itemItr; 

	//searches student list till it find a match an returns an iterator --Changed to all matches in debugging
	StudentList.erase(std::remove(StudentList.begin(), StudentList.end(), out_stud));
}

//loads students into the studentList
void Students::loadStudents(){
	StudentList = fileIO::loadStudents();
}

//saves student list to a file
void Students::saveStudent(){
	fileIO::saveStudents(StudentList);
}

std::vector<Student> Students::searchStudents(searchBy search_by, std::string searchTerm){
	//creates a function pointer to the function that we are going to search by 
	
	std::string (Student::* func)() const;

	switch (search_by){
		case name:
			func = &Student::getName;
			break;
		case ID:
			func = &Student::getUID;
			break;
		case email:
			func = &Student::getName;
			break;
		default:
			std::cout << "error in search" << std::endl;
	}

	return searchStudents(func, searchTerm);

}

std::vector<Student> Students::searchStudents(std::string search_by_string, std::string searchTerm) {
	//creates a function pointer to the function that we are going to search by 

	searchBy search_by;

	if (search_by_string == "name")
	{
		search_by = name;
	}
	else if (search_by_string == "uid")
	{
		search_by = ID;
	}
	else if (search_by_string == "email")
	{
		search_by = email;
	}
	else
	{
		std::cout << "Invalid property : " + search_by_string << std::endl;
		std::vector<Student> dummy;
		return dummy;
	}



	return searchStudents(search_by, searchTerm);

}
// iterates through the student list and compare the search term and the functions return value
std::vector<Student> Students::searchStudents(std::string(Student::* func)() const, std::string searchTerm){
	std::vector<Student> to_return;
	std::vector<Student>::iterator it;

	for (int i = 0; i < StudentList.size(); ++i){
		while ((StudentList[i].*func)() == searchTerm){ //This is an error but I have no idea what it is trying to do
			to_return.insert(it+i, StudentList[i]);
		}
	}

	return to_return;
}

// overloaded equal operator
bool operator==(const Student& stud1, const Student& stud2){
	if (stud1.getName() == stud2.getName() && stud1.getUID() == stud2.getUID() && stud1.getEmail() == stud2.getEmail() &&
		stud1.getEssay1Grade() == stud2.getEssay1Grade() && stud1.getEssay1Grade() == stud2.getEssay1Grade()
		&& stud1.getTermProjGrade() == stud2.getTermProjGrade()){
		return true;
	}
	else {
		return false;
	}
}

//prints students
void Students::printAllStudents()
{
	std::cout << std::setw(10) << "Name" << std::setw(10) << "UID" << std::setw(20) << "Email" << 
		std::setw(9) << "Essay 1" << std::setw(9) << "Essay 2" << std::setw(9) << "Project" << std::endl;
	for (int i = 0; i < StudentList.size(); i++)
	{
		std::cout << std::setw(10) << StudentList[i].getName() << std::setw(10) << StudentList[i].getUID() << std::setw(20) << StudentList[i].getEmail() <<
			std::setw(9) << StudentList[i].getEssay1Grade() << std::setw(9) << StudentList[i].getEssay2Grade() << std::setw(9) << StudentList[i].getTermProjGrade() << std::endl;
	}
}

//We need a direct reference to the student object in the list in order to update it.
void Students::updateInfo(Student toUpdate, std::vector<std::string> updateCommand)
{
	for (int i = 0; i < StudentList.size(); i++)
	{
		if (StudentList[i] == toUpdate)
		{
			StudentList[i].updateInfo(updateCommand[0], updateCommand[1]);
			saveStudent();
			break;
		}
	}
}

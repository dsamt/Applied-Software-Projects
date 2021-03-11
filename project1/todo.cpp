#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <queue>
#include <utility>
#include <map>
#include <sstream>
#include <algorithm>
#include <iterator>

//sub function to determine if a character input is an integer, used for reading from file and reading command line arguments
bool isInt(char *ch) {
	bool flag = true;
	int ch_length = strlen(ch);
	for (int i = 0; i < ch_length; i++) {
		if (!std::isdigit(ch[i])) {
			return false;
		}
	}
	return flag;
}


//class to instantiate an object that is capable of adding, doing, and listing tasks
class todo {
public:
	todo();

	void add(std::string c, int pri, std::string file);
	void printList();
	void doIt(std::string file);
	void load(std::string file);
	void setDid(int x);
private:
	int prior;
	int count;

	std::fstream infile;	
	//structure Todo that represents a todo with its task and priority
	struct Todo {
		std::string task;
		int pri;
	};

	
	void showPD();
	void write(std::string file);
	int did;

	int getDid();
	
	std::vector<Todo> lists;
	std::vector<Todo> dones;
	Todo todos;
	std::vector<Todo> tasks;
	std::vector<Todo> donetask;
};

//default constructor to set the count for listing the tasks in showPD method
//sets the private variable to one every use of the program
todo::todo() {
	count = 1;
}

//sets the number of the task that is said to be done, sets the private variable did for use in the load method
void todo::setDid(int x) {
	this->did = x;
}

//returns the private variable did to be used in the load method
int todo::getDid() {
	return did;
}

//add method that reads in an integer and two strings as arguments to set the priority(integer) and todo(string) for a given task and writes to a file(string)
//ignores quotes given in an argument
void todo::add(std::string c, int pri, std::string file) {
	std::size_t start_pos = c.find("\"");

	while (start_pos != std::string::npos) {
		c.replace(start_pos, 1, "");
		start_pos = c.find("\"");
	}
	todos.pri = pri;
	todos.task = c;

	lists.push_back(todos);



	write(file);
}

//print method that calls upon the private method showPD that is capable of printing the contents of a file
void todo::printList() {
	showPD();
}

//method that is called when a task is done and just loads and writes the file contents
//load method is what marks a task as done and the write file passes that along
void todo::doIt(std::string file) {
	load(file);
	write(file);
}

//method that prints the contents of the file by loading a file whenever the list commnad is called, ehich sets the private variables lists and dones
//which represents tasks and done statuses and then prints those variables which are just vectors of the structure todo
void todo::showPD() {
	std::vector<std::string> sorderG, sorderD;
	std::vector<int> iorderG, iorderD;


	for (std::size_t i = 0; i < lists.size(); i++) {
		std::cout << count++ << ":[ ]" << "[" << lists[i].pri << "]" << lists[i].task << std::endl;
		
	}
	for (std::size_t i = 0; i < dones.size(); i++) {
		std::cout << count++ << ":[x]" << "[" << dones[i].pri << "]" << dones[i].task << std::endl;
		
	}

	
}

//mwethod that writes the contents if two vectors to a file that is passed as an argument
//uses the privates variables lists and dones that represent tasks and tasks that have been done, which are vectors of the structure Todo
void todo::write(std::string file) {
	remove(file.c_str());

	infile.open(file.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);

	std::vector<std::string> sorderG, sorderD;
	std::vector<int> iorderG, iorderD;
	Todo gtasks;
	Todo donetasks;

	for (std::size_t i = 0; i < lists.size(); i++) {
		gtasks.task = lists[i].task;
		gtasks.pri = lists[i].pri;

		tasks.push_back(gtasks);
	}
	for (std::size_t i = 0; i < dones.size(); i++) {
		donetasks.task = dones[i].task;
		donetasks.pri = dones[i].pri;

		donetask.push_back(donetasks);
	}



	std::stable_sort(tasks.begin(), tasks.end(), [&](const Todo& a, const Todo& b) {
			return a.pri < b.pri;
		});

	std::sort(donetask.begin(), donetask.end(), [&](const Todo& a, const Todo& b) {
		return a.pri <= b.pri;
		});

	

	for (std::size_t i = 0; i < tasks.size(); i++) {
		infile << tasks[i].pri << "," << tasks[i].task << "," << std::endl;
	}
	for (std::size_t i = 0; i < donetask.size(); i++) {
		infile << "x" << "," << donetask[i].pri << "," << donetask[i].task << "," << std::endl;
	}
	
	infile.close();
}

//load method that reads from a file and parses it to determine which contenst should be put in which private variables to be used for later
//file is used to keep track of all the tasks and their stauses and this method allows access to those task previously created
void todo::load(std::string file) {
	std::string line;
	std::string temp;
	std::vector<int> intV, didIntV;
	std::vector<std::string> stringV, didStringV;
	bool Done = false;

	infile.open(file.c_str(), std::fstream::in);
	int x = 1;
	while (std::getline(infile, line)) {
		std::stringstream linestream(line);
		std::string value;

		while (std::getline(linestream, value, ',')) {

			int n = value.length();
			char char_array[n + 1];
			strcpy(char_array, value.c_str());
			if (value == "x") {
				Done = true;
			}

			if ((Done && value != "x") || (getDid() == x && value != "x")){

				if (isInt(char_array)) {
					int pri = std::stoi(char_array);
					didIntV.push_back(pri);
				}
				else {
					didStringV.push_back(value);
				}
			}
			else if (!Done && value != "x") {
				if (isInt(char_array)) {
					int pri = std::stoi(char_array);
					intV.push_back(pri);
				}
				else {
					stringV.push_back(value);
				}
				
			}
		}
		x++;
	}
	Todo gtasks;
	Todo donetasks;
	for (std::size_t i = 0; i < intV.size(); i++) {
		gtasks.pri = intV[i];
		gtasks.task = stringV[i];

		lists.push_back(gtasks);

	}
	for (std::size_t i = 0; i < didIntV.size(); i++) {
		donetasks.pri = didIntV[i];
		donetasks.task = didStringV[i];

		dones.push_back(donetasks);

	}
	infile.close();
}





//main function that parses command line arguments and creates an object of the class todo and allows actions to be taken that are apart of the class
//to be called and excuted, returns EXIT_SUCCESS when the proper commnands are called and executed and returns EXIT_FAILURE when the worng command line arguments are used or if a command cannot be excuted
int main(int argc, char *argv[])
{

	std::ofstream outfile;
	std::string file = "todo.txt";
	todo List;

	if (argc <= 1) {
		std::cout << "missing argumenst" << std::endl;
		return EXIT_FAILURE;
	}
	else {
		if (std::strcmp(argv[1], "-f") == 0) {
			file = argv[2];
		}
		
		if (file == "todo.txt"){
			if (std::strcmp(argv[1], "-p") == 0) {
				if (std::strcmp(argv[3], "add") == 0 && argc > 2) {
					List.load(file);
					std::string line = "";
					for (int i = 4; i < argc; i++) {
						line = line + " " + argv[i];
					}
					if (isInt(argv[2])) {
						int priority = strtol(argv[2], NULL, 10);
						List.add(line, priority, file);
						return EXIT_SUCCESS;
					}
					else {
						return EXIT_FAILURE;
					}
				}
			}
			else if (std::strcmp(argv[1], "add") == 0 && argc > 2) {
				List.load(file);
				std::string line = "";
				for (int i = 2; i < argc; i++) {
					line = line + " " + argv[i];
				}
				List.add(line, 5, file);
				return EXIT_SUCCESS;
			}
			else if (std::strcmp(argv[1], "list") == 0) {
				if (argc > 2) {
					return EXIT_FAILURE;
				}
				else {
					List.load(file);
					List.printList();
					return EXIT_SUCCESS;
				}
			}
			else if (std::strcmp(argv[1], "do") == 0) {
				if (argc == 3) {
					if (isInt(argv[2])) {
						int pos = strtol(argv[2], NULL, 10);
						//std::cout << pos << std::endl;
						List.setDid(pos);
						List.doIt(file);
						return EXIT_SUCCESS;
					}
					else {
						return EXIT_FAILURE;
					}
				}
				else {
					return EXIT_FAILURE;
				}
			}
			else {
				return EXIT_FAILURE;
			}
		}
		else {
			if (std::strcmp(argv[3], "-p") == 0) {
				if (std::strcmp(argv[5], "add") == 0 && std::strcmp(argv[1], "-f") == 0  && argc > 4) {
					List.load(file);
					std::string line = "";
					for (int i = 6; i < argc; i++) {
						line = line + " " + argv[i];
					}
					if (isInt(argv[4])) {
						int priority = strtol(argv[4], NULL, 10);
						List.add(line, priority, file);
						return EXIT_SUCCESS;
					}
					else {
						return EXIT_FAILURE;
					}
				}
			}
			else if (std::strcmp(argv[3], "add") == 0 && std::strcmp(argv[1], "-f") == 0 && argc > 4) {
				List.load(file);
				std::string line = "";
				for (int i = 4; i < argc; i++) {
					line = line + " " + argv[i];
				}
				List.add(line, 5, file);
				return EXIT_SUCCESS;
			}
			else if (std::strcmp(argv[3], "list") == 0 && std::strcmp(argv[1], "-f") == 0) {
				if (argc > 4) {
					return EXIT_FAILURE;
				}
				else {
					List.load(file);
					List.printList();
					return EXIT_SUCCESS;
				}
			}
			else if (std::strcmp(argv[3], "do") == 0) {
				if (argc == 5 && std::strcmp(argv[1], "-f") == 0) {
					if (isInt(argv[4])) {
						int pos = strtol(argv[4], NULL, 10);
						//std::cout << pos << std::endl;
						List.setDid(pos);
						List.doIt(file);
						return EXIT_SUCCESS;
					}
					else {
						return EXIT_FAILURE;
					}
				}
				else {
					return EXIT_FAILURE;
				}
			}
			else {
				return EXIT_FAILURE;
			}
		}
		
	}
}


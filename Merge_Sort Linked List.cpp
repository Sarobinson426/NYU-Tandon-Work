// Author: Shaun Robinson
// Class: NYU Tandon Bridge Spring 2020
// Assignment: HW15
// Program: Linked List Merge Sort Print Sorted
// Input: ifstream .txt files
// Output: cout to screen
// Description: creates linked list of employees from .txt file and 
// print a sorted list descending with highest total pay printing first

#include <iostream>
#include <string>
#include <cstddef>
#include <list>
#include <fstream>
using namespace std;

class Employee;

typedef Employee* NodePtr;

class Employee {
public:
	Employee() : id(0), pay_rate(0), hours(0), total_pay(0), front_link(nullptr), previous_link(nullptr), is_printed(false) {};
	Employee(const Employee& other_employee) { *this = other_employee; }
	void operator =(const Employee& other_employee);
	~Employee() { delete front_link; }
	friend class Employee;

	// insert and create employees' in list
	void new_employee(NodePtr& head, string new_name, int new_id, double hourly);

	// mergesort (**fingers crossed**)
	void merge_sorts(NodePtr& main_list);
	void set_status() { is_printed = true; }
	void splits(NodePtr main, NodePtr& first_half, NodePtr& second_half);
	NodePtr merge_lists(NodePtr first, NodePtr last);

	// file intake and print employee info with search 
	void file_intake(NodePtr& intake_emp, ostream& outs);
	void print_employees(const NodePtr& print_me, ostream& outs);
	void search(NodePtr& the_search, int employee_id, double new_hours);

	// open file and calculate pay
	void open(ifstream& ins);
	void calculate_pay(NodePtr& pay_list);

private:
	string name;
	int id;
	double pay_rate, hours;
	double total_pay;
	bool is_printed;
	ifstream employee_file;
	ifstream employee_hours;
	Employee* front_link;
	Employee* previous_link;
};

int main()
{
	Employee* head = nullptr, * return_list;

	head = new Employee;
	return_list = new Employee;

	head->file_intake(head, cout);
	cout << endl;
	head->calculate_pay(head);
	head->merge_sorts(head);
	cout << endl;
	cout << "****PAYROLL INFORMATION*****" << endl;
	head->print_employees(head, cout);
	cout << "      ****END*****" << endl;

	return 0;
}
void Employee::operator =(const Employee& other_employee) {
	name = other_employee.name;
	id = other_employee.id;
	pay_rate = other_employee.pay_rate;
	hours = other_employee.hours;
	total_pay = other_employee.total_pay;
	is_printed = other_employee.is_printed;
	front_link = other_employee.front_link;
	previous_link = other_employee.previous_link;
}

void Employee::new_employee(NodePtr& head, string new_name, int new_id, double new_hourly) {
	NodePtr new_employee = head;
	new_employee = new Employee;

	new_employee->name = new_name;
	new_employee->id = new_id;
	new_employee->pay_rate = new_hourly;

	new_employee->front_link = head;
	head->previous_link = new_employee;
	head = new_employee;
}

void Employee::file_intake(NodePtr& print_employees, ostream& outs) {
	string emp_name;
	int emp_id;
	double emp_pay, emp_hours;

	print_employees->open(employee_file);
	while (employee_file >> emp_id) {
		employee_file >> emp_pay;
		employee_file.ignore(777, ' ');
		getline(employee_file, emp_name);
		print_employees->new_employee(print_employees, emp_name, emp_id, emp_pay);
		//outs << print_employees->name << endl;
		//outs << print_employees->id << endl;
		//outs << "$" << print_employees->pay_rate << endl;
	}

	emp_hours = 0.00;
	print_employees->open(employee_hours);
	while (employee_hours >> emp_id) {
		employee_hours >> emp_hours;
		//cout << emp_id << " " << emp_hours << endl;
		search(print_employees, emp_id, emp_hours);
	}
	employee_file.close();
	employee_hours.close();
}

void Employee::search(NodePtr& the_search, int employee_id, double new_hours) {
	NodePtr node_search = the_search;
	//cout << "Are you even searching!" << endl;

	if (node_search == nullptr) {
		return;
	}
	else {
		while (node_search->id != employee_id && node_search != nullptr) {
			node_search = node_search->front_link;
		}
		if (node_search->id == employee_id) {
			node_search->hours = (node_search->hours + new_hours);
			//cout << node_search->hours << endl;
		}
		else {
			return;
		}
	}
}

void Employee::print_employees(const NodePtr& print_employees, ostream& outs) {
	NodePtr employee = print_employees;

	while (employee != NULL) {
		outs << "Name: " << employee->name << endl;
		outs << "Employee ID: " << employee->id << endl;
		outs << "Pay rate $" << employee->pay_rate << endl;
		outs << "Hours: " << employee->hours << endl;
		outs << "Total pay $" << employee->total_pay << endl;
		employee = employee->front_link;
	}
}

void Employee::open(ifstream& ins) {
	string file_name;
	cout << "What file would you like to open: ";
	cin >> file_name;
	ins.open(file_name);
	while (!ins) {
		cout << "!!!!!!!!File Open Failure!!!!!!!!\n"
			<< "Which file would you like to open? ";
		cin >> file_name;
		ins.clear();
		ins.open(file_name);
	}
}

void Employee::calculate_pay(NodePtr& pay_list) {
	NodePtr pay_calc = pay_list;

	while (pay_calc->front_link != NULL) {
		pay_calc->total_pay = pay_calc->hours * pay_calc->pay_rate;
		//cout << pay_calc->total_pay << endl;
		//cout << pay_list->id << " " << pay_calc->id << endl;
		pay_calc = pay_calc->front_link;
	}
}

// Sorts 
void Employee::merge_sorts(NodePtr& main_list) {
	NodePtr head = main_list, first_half = NULL, last_half = NULL, return_list;

	return_list = new Employee;

	if (head == NULL || head->front_link == nullptr) {
		return;
	}

	splits(head, first_half, last_half);

	merge_sorts(first_half);
	merge_sorts(last_half);

	main_list = merge_lists(first_half, last_half);
}

void Employee::splits(NodePtr main, NodePtr& first_half, NodePtr& second_half) {
	NodePtr fast, slow;

	if (main == NULL || main->front_link == nullptr) {
		first_half = main;
		second_half = NULL;
	}
	else {
		slow = main;
		fast = main->front_link;

		while (fast->front_link != NULL) {
			fast = fast->front_link;

			if (fast->front_link != NULL) {
				slow = slow->front_link;
				fast = fast->front_link;

			}

		}
		first_half = main;
		second_half = slow->front_link;
		slow->front_link = NULL;
	}
}

NodePtr Employee::merge_lists(NodePtr first, NodePtr last) {
	NodePtr the_list;
	the_list = new Employee;

	if (first == NULL) {
		return last;
	}
	else if (last == NULL) {
		return first;
	}

	if (first->total_pay >= last->total_pay) {
		the_list = first;
		the_list->front_link = merge_lists(first->front_link, last);
	}
	else {
		the_list = last;
		the_list->front_link = merge_lists(first, last->front_link);
	}

	return the_list;
}
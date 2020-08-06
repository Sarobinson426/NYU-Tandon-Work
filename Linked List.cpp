#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Node {
private:
	int data;
public:
	Node* fwd;
	Node* bwd;

	Node(int new_data) : data(new_data), fwd(nullptr), bwd(nullptr) {};
	Node(const Node& other_node) {
		*this = other_node;
	}
	void operator = (const Node& other_node) {
		*this = other_node;
	}

	int return_data() { return data; }
};

class LinkedList {
private:
	Node* head;
public:
	LinkedList() : head(nullptr) {};
	~LinkedList() { delete head; }

	void append(int new_data) {           // add to the end of the list
		Node* new_node = new Node(new_data);

		if (head == NULL) {
			head = new_node;
			return;
		}
		Node* current = head;

		while (current->fwd != nullptr) {
			current = current->fwd;
		}
		current->fwd = new_node;
		new_node->bwd = current;
	}

	void prepend(int new_data) {           // add to head of list
		Node* new_node = new Node(new_data);

		if (head == NULL) {
			head = new_node;
			return;
		}

		head->bwd = new_node;
		new_node->fwd = head;
		head = new_node;
	}

	void del_node(int node_value_to_delete) {
		if (head == NULL) {
			return;
		}
		if (head->return_data() == node_value_to_delete) {
			head = head->fwd;
		}

		while (head->fwd->return_data() != node_value_to_delete) {
			head = head->fwd;
			if (head == NULL) {
				cout << "Value not found!" << endl;
				return;
			}
		}
		head->fwd = head->fwd->fwd;
		head->fwd->fwd->bwd = head;
	}

	void reverse_the_list() {
		Node* curr = head, * prev = NULL, * next = NULL;

		while (curr != NULL) {
			next = curr->fwd;
			curr->fwd = prev;
			prev = curr;
			curr = next;
		}

		head = prev;
	}

	void open_text_file(ifstream& ins) {       // ifstream to open a file if want to take input from file
		string file_name;
		
		cout << "What file do you want to open? " << endl;
		cin >> file_name;
		ins.open(file_name);

		while (!ins) {
			cout << "File " << file_name << " faile to open "
				<< "enter another file to open: ";
				cin >> file_name;
				ins.clear();
				ins.open(file_name);
		}
	}

	void print(ostream& outs) {               // ostream gives choice to print to a file or cout to screen
		Node* be_kind_rewind = head;
		while (head != NULL) {
			outs << head->return_data() << endl;
			head = head->fwd;
		}

		head = be_kind_rewind;
	}
};

int main()
{
	LinkedList the_list;

	// this is just an example of how the list works 
	// could do a cin >> input
	// and set values this way in a for loop
	// or ifstream open_text_file(ifstream & ins) and take in input this way
	// with slight modification to the code 

	// e.g. below
	the_list.append(22);
	the_list.append(500);
	the_list.prepend(777);
	the_list.prepend(555);
	the_list.append(9000);
	the_list.prepend(6000);
	the_list.append(3000);
	the_list.prepend(9999);

	cout << "The full list: " << endl;
	the_list.print(cout);
	
	cout << "The list with 6000 deleted: " << endl;
	the_list.del_node(6000);
	the_list.print(cout);
	
	cout << "The list in reverse: " << endl;
	the_list.reverse_the_list();
	the_list.print(cout);

	return 0;
}
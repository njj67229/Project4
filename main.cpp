#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "BinaryTree.h"
using namespace std;

// Intro that reads commands
char intro() {
	char treeType;
	int valid{0};
	while (valid == 0) {
		cout << "\nEnter tree type (i - int, f - float, s - std:string): ";
		cin >> treeType;
		cout << endl;
		// Check for valid input
		if (treeType != 'i' && treeType != 'f' && treeType != 's') {
			cout << "Invalid list type: " << treeType << endl;
		} else {
			valid = 1;
		} // if/else
	} // while
	cout << "Commands:" << endl;
	cout << "insert (i), delete (d), retrieve (r), length (l), in-order (n)," << endl;
	cout << "pre-order (p), post-order (o), getNumSingleParent (s)," << endl;
	cout << "getNumLeafNodes (f), getSumOfSubtrees (t), quit (q)" << endl;
    cout << endl;
	return treeType;
} // end intro

// Commands for ints
void commandsI(BinaryTree<int> s, char listType) {
    int quit = 0;
	char command = 0;
	string item = "";
	bool found = false;
	while (quit == 0) {
		cin.clear();
		cout << "Enter a command: ";
		cin >> command;
		if (command == 'i') { // insert
			cout << "Item to insert: ";
			cin >> item;
			int num = stoi(item);
			s.insert(num); // int
		    cout << "In-Order: ";
            s.inOrder();
            cout << endl;
		} else if (command == 'd') { // delete
			cout << "Item to delete: ";
			cin >> item;
			int num = stoi(item);
            s.retrieve(num, found); // int
			if (found == true) {
                s.deleteItem(num); // int
			} else {
				cout << "Item not in tree" << endl;
			} // if/else
		    cout << "In-Order: ";
            s.inOrder();
            cout << endl;
		} else if (command == 'r') { // retrieve
		    cout << "Item to be retrieved: ";
			cin >> item;
			int num = stof(item);
			s.retrieve(num, found); // int
			if (found == true) {
				cout << "Item found in tree" << endl;
			} else {
				cout << "Item not in tree" << endl;
			} // if/else
		} else if (command == 'l') { // length
		    cout << "Tree length: " << s.getLength() << endl;
		} else if (command == 'n') { // in-order
		    cout << "In-Order: ";
            s.inOrder();
            cout << endl;
		} else if (command == 'p') { // pre-order
            cout << "Pre-Order: ";
			s.preOrder();
            cout << endl;
  		} else if (command == 'o') { // post-order
            cout << "Post-Order: ";
			s.postOrder();
            cout << endl;
		} else if (command == 's') { // getNumSingleParent
			cout << "Number of Single Parents: " << s.getNumSingleParent(s.getRoot()) << endl;
		} else if (command == 'f') { // getNumLeafNodes
			cout << "Number of leaf nodes: " << s.getNumLeafNodes(s.getRoot()) << endl;
		} else if (command == 't') { // getSumOfSubtrees - Nathan
            cout << "Item to get sum of subtrees: ";
            cin >> item;
            int num = stoi(item);
            s.retrieve(num, found);
            if (found == true) {
                Node<int>* search;
                search->key = num;
                search = s.getItem(num, found, s.getRoot());
                cout << "Sum of subtrees: " << s.getSumOfSubtrees(search, found) << endl; // int
            } else {
                cout << "Item not in tree." << endl;
            }
		} else if (command == 'q') { // quit
			cout << "Quitting program..." << endl;
			quit = 1;
		} else {
			cout << "Command not recognized. Try again" << endl;
		} // if/else
        cout << endl;
		item = "";
		found = false;
	} // while
} // end commands

// Commands for floats
void commandsF(BinaryTree<float> s, char listType) {
    int quit = 0;
	char command = 0;
	string item = "";
	bool found = false;
	while (quit == 0) {
		cin.clear();
		cout << "Enter a command: ";
		cin >> command;
		if (command == 'i') { // insert
			cout << "Item to insert: ";
			cin >> item;
			float fl = stof(item);
			s.insert(fl); // float
		    cout << "In-Order: ";
            s.inOrder();
            cout << endl;
		} else if (command == 'd') { // delete - Nathan
			cout << "Item to delete: ";
			cin >> item;
			float fl = stof(item);
			s.retrieve(fl, found); // int
			if (found == true) {
                s.deleteItem(fl); // int
			} else {
				cout << "Item not in tree" << endl;
			} // if/else
		    cout << "In-Order: ";
            s.inOrder();
            cout << endl;
		} else if (command == 'r') { // retrieve
		    cout << "Item to be retrieved: ";
			cin >> item;
			float fl = stof(item);
			s.retrieve(fl, found); // float
			if (found == true) {
				cout << "Item found in tree" << endl;
			} else {
				cout << "Item not in tree" << endl;
			} // if/else
		} else if (command == 'l') { // length
		    cout << "Tree length: " << s.getLength() << endl;
		} else if (command == 'n') { // in-order
		    cout << "In-Order: ";
            s.inOrder();
            cout << endl;
		} else if (command == 'p') { // pre-order
			cout << "Pre-Order: ";
			s.preOrder();
            cout << endl;
  		} else if (command == 'o') { // post-order
			cout << "Post-Order: ";
			s.postOrder();
            cout << endl;
		} else if (command == 's') { // getNumSingleParent
		    cout << "Number of Single Parents: " << s.getNumSingleParent(s.getRoot()) << endl;
		} else if (command == 'f') { // getNumLeafNodes
			cout << "Number of leaf nodes: " << s.getNumLeafNodes(s.getRoot()) << endl;
		} else if (command == 't') { // getSumOfSubtrees - Nathan
            cout << "Item to get sum of subtrees: ";
            cin >> item;
            float fl = stof(item);
            if (found) {
                Node<float>* search;
                search->key = fl;
                search = s.getItem(search->key, found, s.getRoot());
                cout << "Sum of subtrees: " << s.getSumOfSubtrees(search, true) << endl; // float
            } else {
                cout << "Item not in tree." << endl;
            }
		} else if (command == 'q') { // quit
			cout << "Quitting program..." << endl;
			quit = 1;
		} else {
		    cout << "Command not recognized. Try again" << endl;
		} // if/else
        cout << endl;
		item = "";
		found = false;
	} // while
} // end commands

// Commands for string
void commandsS(BinaryTree<string> s, char listType) {
    int quit = 0;
	char command = 0;
	string item = "";
	bool found = false;
	while (quit == 0) {
		cin.clear();
		cout << "Enter a command: ";
		cin >> command;
		if (command == 'i') { // insert
			cout << "Item to insert: ";
			cin >> item;
			s.insert(item); // string
			cout << "In-Order: ";
            s.inOrder();
            cout << endl;
		} else if (command == 'd') { // delete - Written by Nathan
			cout << "Item to delete: ";
			cin >> item;
		    s.retrieve(item, found); // str
			if (found == true) {
                s.deleteItem(item); // str
			} else {
				cout << "Item not in tree" << endl;
			} // if/else
		    cout << "In-Order: ";
            s.inOrder();
            cout << endl;
		} else if (command == 'r') { // retrieve
		    cout << "Item to be retrieved: ";
			cin >> item;
			s.retrieve(item, found); // string
			if (found == true) {
				cout << "Item found in tree" << endl;
			} else {
				cout << "Item not in tree" << endl;
			} // if/else
		} else if (command == 'l') { // length
		    cout << "Tree length: " << s.getLength() << endl;
		} else if (command == 'n') { // in-order
			cout << "In-Order: ";
            s.inOrder();
            cout << endl;
		} else if (command == 'p') { // pre-order
			cout << "Pre-Order: ";
			s.preOrder();
            cout << endl;
  		} else if (command == 'o') { // post-order
			cout << "Post-Order: ";
			s.postOrder();
            cout << endl;
		} else if (command == 's') { // getNumSingleParent
		    cout << "Number of Single Parents: " << s.getNumSingleParent(s.getRoot()) << endl;
		} else if (command == 'f') { // getNumLeafNodes
			cout << "Number of leaf nodes: " << s.getNumLeafNodes(s.getRoot()) << endl;
		} else if (command == 't') { // getSumOfSubtrees - Written By Nathan
            cout << "Item to get sum of subtrees: ";
            cin >> item;
            if (found) {
                Node<string>* search;
                search->key = item;
                search = s.getItem(search->key, found, s.getRoot());
                cout << "Sum of subtrees: " << s.getSumOfSubtrees(search, true) << endl; // string
            } else {
                cout << "Item not in tree." << endl;
            }
		} else if (command == 'q') { // quit
			cout << "Quitting program..." << endl;
			quit = 1;
		} else {
		    cout << "Command not recognized. Try again" << endl;
		} // if/else
        cout << endl;
		item = "";
		found = false;
	} // while
} // end commands

void makeTree(string file, char treeType) {
	ifstream libFile;
	libFile.open(file, ios::in);
	char n;
	string item;
	if (treeType == 'i') { // if int list
        BinaryTree<int> s;
		// While loop to put items into list
		while(libFile.get(n)) {
			if (n != ' ' && n != '\n' && n != '\0') {
				item.push_back(n);
			} else {
				stringstream st;
				int nu;
				st << item;
				st >> nu;
				s.insert(nu);
				item = "";
			} // if/else
		} // while
		if (item.length() != 0) {
			stringstream st;
			int nu;
			st << item;
			st >> nu;
			s.insert(nu);
			item = "";
		} // if
        commandsI(s, treeType);
	} // if (int)
	if (treeType == 'f') { // if float list
        BinaryTree<float> s;
		while(libFile.get(n)) {
			if (n != ' ' && n != '\n' && n != '\0') {
				item.push_back(n);
			} else {
				stringstream st;
				float fl;
				st << item;
				st >> fl;
				s.insert(fl);
				item = "";
			} // if/else
		} // while
		if (item.length() != 0) {
			stringstream st;
			float fl;
			st << item;
			st >> fl;
			s.insert(fl);
			item = "";
		} // if
        commandsF(s, treeType);
	} // if (float)
	if (treeType == 's') { // if string list
        BinaryTree<string> s;
		while (libFile.get(n)) {
			if (n != ' ' && n != '\n' && n != '\0') {
				item.push_back(n);
			} else {
			    s.insert(item);
				item = "";
			} // if/else
		} // while
		if (item.length() != 0) {
			s.insert(item);
			item = "";
		} // if
        commandsS(s, treeType);
	} // if (string)
	libFile.close();
} // end makeList

// Program main
int main(int argc, char **argv) {
	if (argc != 2) { // error check for correct argument number
		cerr << "Usage: main [text_file]" << endl;
		exit (1);
	} // if
	string file = argv[1];
	char treeType = intro(); // call function above
	makeTree(file, treeType); // makeTree function, above
    return 0;
} //end main

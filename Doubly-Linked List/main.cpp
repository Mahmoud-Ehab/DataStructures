#include <iostream>
#include "dl_list.h"

using namespace std;
using namespace dll;

void traverse(LinkedList list) {
	LL_Node *temp = list.get(0);
	while (temp != NULL) {
		cout << temp->entry << '\n';
		temp = temp->next;
	}
}

int main() {
	LinkedList list;
	
	cout << "************************" << '\n';
	cout << "Test_0:  adding elements" << '\n';
	cout << "************************" << '\n';
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.add(5);
	list.add(6);
	cout << "size = " << list.getSize() << '\n';
	traverse(list);
	
	cout << "************************" << '\n';
	cout << "Test_1: removing first element" << '\n';
	cout << "************************" << '\n';
	list.remove(0);
	traverse(list);
	
	cout << "************************" << '\n';
	cout << "Test_2: removing element 3 out of 5 elements" << '\n';
	cout << "************************" << '\n';
	list.remove(2);
	traverse(list);
	
	cout << "************************" << '\n';
	cout << "Test_3: removing last element" << '\n';
	cout << "************************" << '\n';
	list.remove(list.getSize() - 1);
	traverse(list);
	
	cout << "************************" << '\n';
	cout << "Test_4: insert new element in the beginning" << '\n';
	cout << "************************" << '\n';
	list.insert(0, 1);
	traverse(list);
	
	cout << "************************" << '\n';
	cout << "Test_5: insert new element in the middle" << '\n';
	cout << "************************" << '\n';
	list.insert(2, 4);
	traverse(list);
	
	cout << "************************" << '\n';
	cout << "Test_6: insert new element in the end" << '\n';
	cout << "************************" << '\n';
	list.insert(list.getSize()-1, 6);
	traverse(list);
	
	return 0;
}

/*
* Written by Mahmoud Ehab Abd-alsalam
* December, 2020
*/

#include <cstdlib>

using namespace std;
	
namespace dll
{
	
	//Declare (Struct) the linked list node
	typedef struct LL_Node {
	
		int entry;
		LL_Node *next;
		LL_Node *prev;
		
	} LL_Node;
	
	//Function to create LL_Node and return a pointer to it
	LL_Node* createNode(int entry, LL_Node *n, LL_Node *p) {
	
		LL_Node *node = (LL_Node*) malloc(sizeof(LL_Node));
		node->entry = entry;
		node->next = n;
		node->prev = p;
		
		return node;
	}
	
	//Linked List Class
	class LinkedList
	{
		private:
			LL_Node *firstNode = NULL;
			LL_Node *lastNode = NULL;
			int size = 0;
			
		public:
			//Add new element in the list
			void add(int entry) {
				//The case when its the first element
				if (firstNode == NULL && lastNode == NULL) {
				
					LL_Node *newNode = createNode(entry, NULL, NULL);
					firstNode = newNode;
					lastNode = newNode;
					
					size++;
					return;
				}
				
				//Otherwise
				LL_Node *newNode = createNode(entry, NULL, lastNode); //Create New Node
				lastNode->next = newNode;	//Assign the new node as the next of the lastNode
				lastNode = newNode;	//Make the lastNode pointer points to the new(last)Node
				
				size++;
			}
			
			//Return the entery of an element in the list
			LL_Node* get(int index) {
				if (index >= size || index < 0) {
					return NULL;
				}
				else if (index == 0) {
					return firstNode;
				}
				else if (index == size - 1) {
					return lastNode;
				}
				
				//If the index is between 0 and size-1
				//If it's smaller than size/2.. loop over the left half
				if (index < size/2) {
					LL_Node *node = firstNode;
					for (int i = 0; i < index; i++) {
						node = node->next;
					}
					return node;
				}
				//Otherwise, loop over the right half
				else {
					LL_Node *node = lastNode;
					for (int i = size - 1; i > index; i--) {
						node = node->prev;
					}
					return node;
				}
			}
			
			//Remove an element from the list
			void remove(int index) {
				if (index >= size || index < 0) {
					return;
				}
				else if (index == 0) {
					firstNode = firstNode->next;
					free(firstNode->prev);
					firstNode->prev = NULL;
					size--;
					return;
				}
				else if (index == size - 1) {
					lastNode = lastNode->prev;
					free(lastNode->next);
					lastNode->next = NULL;
					size--;
					return;
				}
				
				//If the index is between 0 and size-1
				LL_Node *temp = get(index);
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				
				size--;
				free(temp);
			}
			
			//insert a new element in the list
			void insert(int index, int entry) {
				LL_Node *sNode = get(index);
				if (sNode == NULL) return;
				
				//Allocate new node in the ram
				LL_Node *newNode = createNode(entry, sNode, sNode->prev);
				
				//If index == 0, the user is insering in the first index
				if (sNode->prev == NULL)
					firstNode = newNode;
				//Otherwise
				else
					sNode->prev->next = newNode;
				
				//Reconnect the list
				sNode->prev = newNode;
				
				//Increase the size
				size++;
			}
			
			//Remove all nodes
			void clear() {
				size = 0;
				//Remove elements from right and left synchronously
				LL_Node *l = firstNode;
				LL_Node *r = lastNode;
				while (l->next != r && l != r) {
					//Remove one element from the left
					LL_Node *temp = l;
					l = l->next;
					free(temp);
					//Remove one element from the write
					temp = r;
					r = r->prev;
					free(temp);
				}
				
				if (l == r) {
					free(l);
					return;
				}
					
				free(l);
				free(r);
			}
			
			//Return the size of the list
			int getSize() {
				return size;
			}
	};
}


//	Code By Shahab Ghouri
// A menu base program for Doubly Linked List in C++

#include <iostream>
using namespace std;

class node{		// creating the class for node
	public:
		int data;
		node *next,*prev;		// node pointers which will hold the address of next and prev node, respectively
};

class LinkedList{			// creating the class for LinkedList
	public :
		node *head,*tail;		// node pointers which will point at head and tail nodes
			
			
			// Default Constructor initializing head and tail pointers
		LinkedList(){
			head = NULL;
			tail = NULL;
		}


//		-----------------------------------	
// FUNCTIONS FOR INSERTION 
		
			// function to insert a node at the end
		void InsertAtEnd(int n){
			node *temp = new node;
			temp->next = NULL;
			temp->prev = NULL;
			temp->data = n;
			
			// if no node found, create one
			if( head == NULL){
				head = temp;
				tail = temp;
			}
			// else add the node at the end
			else{
				tail->next = temp;
				temp->prev = tail;
				tail = temp;
			}
		}
		
		// function to insert node at front
		void InsertAtFront(int n){
			node *temp = new node;
			temp->next = NULL;
			temp->prev = NULL;
			temp->data = n;
			
			if( head == NULL){
				head = temp;
				tail = temp;
			}
			else{
				head->prev = temp;
				temp->next = head;
				head = temp;
			}
		}
		// function to insert node at the given position
		int InsertAtAnyPosition(int n,int pos){
			node *temp = new node;
			temp->next = NULL;
			temp->prev = NULL;
			temp->data = n;
			if(pos==0){
				cout<<" INVALID POSITION..."<<endl;
				return 0;
			}
			if(pos == 1){
				head->prev = temp;
				temp->next = head;
				head = temp;
			}
			else{
				node *curr, *pre;
				curr = head;
				for(int i=0; i<pos-1; i++){
					pre = curr;
					curr = curr->next;
				}
				pre->next = temp;
				temp->prev = pre;
				temp->next = curr;
				curr->prev = temp;
			}
			
		}
//		-----------------------------------
// 	FUNCTIONS TO TRAVERSE DOUBLY LINKED LIST
		void TraverseForward(){
			node *temp;
			
			temp = head;
			cout<<"NULL -> ";
			while(temp!=NULL){
				cout<<temp->data<<" -> ";
				temp = temp->next; 
			}
			cout<<"NULL"<<endl;
		}
		void TraverseBackward(){
				node *temp;
				temp = tail;
				cout<<"NULL -> ";
				while(temp!=NULL){
					cout<<temp->data<<" -> ";
					temp = temp->prev;
				}
				cout<<"NULL"<<endl;
		}
//		-----------------------------------
// FUNCTIONS FOR DELETE

		// function to delete a node from start
		void  DeleteFirst(){
			node *temp;
			temp = head->next;
			head = temp;
			head->prev = NULL;
		}
		
		// function to delete node from end
		void DeleteEnd(){
			node *temp;
			temp = tail->prev;
			
			tail = temp;
			tail->next = NULL;
		}
		
		// function to delete node from given position
		void DeleteAtAnyPosition(int pos){
			node *curr,*pre;
			
			if(pos==0){
				cout<<" INVALID POSITION..";
			}
			if(pos==1){
				DeleteFirst();
			}
			else{
				curr = head;
				for(int i=0; i<pos-1; i++){
					pre = curr;
					curr = curr->next; 
				}
				node *temp = curr->next;
				pre->next = temp;
				temp->prev = pre;
				curr->next = NULL;
				curr->prev = NULL;
					delete curr;
			}
		}
};

main(){
	LinkedList obj;
	int ch,n,pos;
	while(1){
		system("cls");
		cout<<" DOUBLY LINKED LIST\n\n"<<endl;
		
		cout<<" 1- TraverseForward()\n 2- TraverseBackward()\n 3- InsertAtFront()\n 4- InsertAtEnd()\n 5- InsertAtAnyPosition()\n 6- DeleteFirst()\n 7- DeleteEnd()\n 8- DeleteAtAnyPosition()\n 0 - EXIT";
		cout<<endl<<" Enter Your Choice : ";cin>>ch;
		if(ch==0){
			break;
		}
		switch(ch){
			case 1:
					obj.TraverseForward();
					cout<<" \nPress Any Key To Continue..\n";
					fflush(stdin);
					cin.get();
				break;
			case 2:
					obj.TraverseBackward();
					cout<<" \nPress Any Key To Continue..\n";
					fflush(stdin);
					cin.get();
				break;
			case 3 :
					cout<<endl<<" Enter A value : ";cin>>n;
					obj.InsertAtFront(n);
					cout<<" Value Added\nPress Any Key To Continue..\n";
					fflush(stdin);
					cin.get();
				break;
			case 4 :
					cout<<endl<<" Enter A value : ";cin>>n;	
					obj.InsertAtEnd(n);			
					cout<<" Value Added\nPress Any Key To Continue..\n";
					fflush(stdin);
					cin.get();
				break;
			case 5 :
					cout<<endl<<" Enter A value : ";cin>>n;	
					cout<<endl<<" Enter the Position : ";cin>>pos;
					obj.InsertAtAnyPosition(n,pos);
					cout<<" Value Added\nPress Any Key To Continue..\n";
					fflush(stdin);
					cin.get();
				break;
			case 6 :
					obj.DeleteFirst();	
					cout<<" \n Value Deleted From Start.\nPress Any Key To Continue..\n";
					fflush(stdin);
					cin.get();
				break;
			case 7 :
					obj.DeleteEnd();
					cout<<" \n Value Deleted From End.\nPress Any Key To Continue..\n";
					fflush(stdin);
					cin.get();
				break;
			case 8 :
					cout<<" Enter Position : ";cin>>pos;
					obj.DeleteAtAnyPosition(pos);
					cout<<" \n Value Deleted.\nPress Any Key To Continue..\n";
					fflush(stdin);
					cin.get();
				break;					
			default : 
					cout<<" Invalid Option..";
					cout<<" \nPress Any Key To Continue..\n";
					fflush(stdin);
					cin.get();
				break;							
		}
		
	}
	
	
}

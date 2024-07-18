#include <iostream>
using namespace std;


class DoubleLinkedlist {
    public:
        int data;
        DoubleLinkedlist* next = nullptr;
        DoubleLinkedlist* prev = nullptr;

        void append( int d_) {
            DoubleLinkedlist* indexer = this;

            while ( true )
            {
                if ( indexer->next == nullptr && indexer->prev == nullptr ) {
                    DoubleLinkedlist* new_node = new DoubleLinkedlist;
                    new_node->data = d_;
                    new_node->prev = this;
                    new_node->next = nullptr;

                    this->next = new_node;
                    this->prev = new_node;

                    break;
                } else if ( indexer->next == nullptr ) {
                    DoubleLinkedlist* new_node = new DoubleLinkedlist;
                    new_node->data = d_;
                    new_node->prev = indexer;
                    new_node->next = nullptr;

                    indexer->next = new_node;
                    this->prev = new_node;
                    break;
                } else {
                    indexer = indexer->next;
                }
            }
            
        }

        void printList() {
            DoubleLinkedlist* indexer = this;
            while ( true )
            {   
                if ( indexer->next != nullptr ) {
                    cout << indexer->data << " ";
                    indexer = indexer->next;
                } else {
                    cout << indexer->data << " ";
                    break;
                }
                
            }
            cout << endl;
        }

        void drop( int i_) {
            DoubleLinkedlist* indexer = this;
            int i = 0;

            while ( true ) {
                if ( i == i_ ) {
                    indexer->prev->next = indexer->next;
                    break;
                } else { 
                    i += 1;
                    indexer = indexer->next;
                }
            }


        }

        int len() {
            int i = 0;
            DoubleLinkedlist* indexer = this;
            while (indexer != nullptr) { 
                indexer = indexer->next;
                i += 1;
            }
            
            return i;
        }

};


int main() {
    DoubleLinkedlist list;
    list.data = 1;

    // Append
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);

    // Drop
    list.drop(2);
    

    // Print list
    list.printList();

    // List Lenght
    int len = list.len();
    
    return 0;
}
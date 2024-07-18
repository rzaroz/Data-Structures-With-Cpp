#include <iostream>
using namespace std;

class LinkedList {
    public:
        int data;
        LinkedList* next = nullptr;
        void append(int d_) {
            LinkedList* Index = this;

            while (true) {   
                if (Index->next == nullptr) {
                    LinkedList* new_node = new LinkedList;
                    new_node->data = d_;
                    new_node->next = nullptr;
                    Index->next = new_node;
                    break;
                } else {
                    Index = Index->next;
                }
            }
        }

        void drop(int dis_) {
            LinkedList* current = this;
            LinkedList* pre;

            int i_ = 0;
            while ( true ) {
                if ( dis_ == 0 ) {

                    while ( true )
                    {   
                        current->data = current->next->data;
                        pre = current;
                        current = current->next;
                        
                        if ( current->next == nullptr ) {
                            pre->next = nullptr;
                            delete current;
                            break;
                        }    
                    }
                    
                    break;
                }else if (i_ == dis_){
                    pre->next = current->next;
                    delete current;
                    break;
                }else {
                    pre = current;
                    current = current->next;
                    if ( current == nullptr ){
                        throw out_of_range("Index is out of range!");
                    }
                    i_ += 1;
                }
            }
        }

        void printList() {
            LinkedList* Index = this;
            while (Index != nullptr) { 
                cout << Index->data << " ";
                Index = Index->next;
            }
            cout << endl;
        }
        
        int len() {
            int i = 0;
            LinkedList* Index = this;
            while (Index != nullptr) { 
                Index = Index->next;
                i += 1;
            }
            
            return i;
        }
};

int main() {
    LinkedList MyList;
    MyList.data = 0;

    // Append Method
    MyList.append(23);

    // drop index
    MyList.drop(1);

    // Len 
    int list_len = MyList.len();

    // Print list 
    MyList.printList();
    return 0;
}

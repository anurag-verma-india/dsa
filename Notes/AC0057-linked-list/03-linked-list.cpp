// Note: initializing HEAD and TAIL with nullptr will also have same effect (and to 0) too
// But nullptr is better approach (don't over emphasize this though, as it's a stylistic choice)
#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class List {
    Node* HEAD;
    Node* TAIL;

   public:
    List() {
        HEAD = TAIL = nullptr;
    }

    void push_front(int val) {
        // O(1)
        /*
        Two cases
        If HEAD is NULL (list is empty)
            Make a new Node HEAD & TAIL both point to this
        If HEAD is not NULL (list is not empty)
            Make a new node
            Make it's next point to the HEAD
            update head to point to this
        */
        Node* newNode = new Node(val);  // pointer to the new node (is newNode)
        if (HEAD == nullptr) {
            // newNode->next = HEAD; // this is also correct, because we know from the default constructor that HEAD is NULL
            // newNode->next = NULL; // No need to do this by default all new nodes' next already point to NULL
            HEAD = TAIL = newNode;
            return;
        }
        newNode->next = HEAD;
        HEAD = newNode;
    }

    void push_back(int val) {
        // Here O(1), using TAIL
        // Otherwise O(N)
        /*
        Make a new node
        Two cases
        If HEAD is NULL
            assign HEAD and TAIL both to point to the new node
        otherwise
            Make the pointer at tail point to the new node
            Update the TAIL
        */
        Node* newNode = new Node(val);  // ptr to new node
        if (TAIL == nullptr) {
            HEAD = TAIL = newNode;
            return;
        }
        // else {
        TAIL->next = newNode;
        TAIL = newNode;
        // }
    }

    void pop_front() {
        // O(1)
        /*
        Case1:
        If HEAD is NULL show error

        Case 2:
        If HEAD is TAIL (there is only one pointer)
            Delete the Node
            Point HEAD and TAIL to the nullptr

        Case 3:
        otherwise
            make a new temp value that points to the HEAD
            Mode head to next
            make the next of temp (previously HEAD), NULL
            free temp from memory by delete keyword
        */

        // Case 1:
        if (HEAD == nullptr) {
            cout << "The LL is empty" << endl;
            return;
        }

        // Case 2:
        if (HEAD == TAIL) {
            // There is only one node
            delete HEAD;
            HEAD = TAIL = nullptr;
            return;
        }

        // Case 3:
        Node* temp = HEAD;
        HEAD = HEAD->next;
        temp->next = nullptr;

        delete temp;
        // Already handled in Case 2
        // if (HEAD == nullptr) {
        //     TAIL = nullptr;  // handling the case with only single node in the list being deleted
        //     // Without this TAIL becomes a dangling pointer
        // }
        // temp = nullptr; // no need to do this buy may keep for documentation
    }

    void pop_back() {
        // O(n)
        // Note: In case of implementation without TAIL pointer
        //     the new TAIL will be the Node next of whose next is NULL
        /*
        Case 1:
        If TAIL is NULL
            print that the list is empty

        Case 2:
        If HEAD is TAIL (there is only one node)
            make HEAD and TAIL both point to NULL

        Case 3:
        otherwise
            find the penultimate (just before tail) element
            disconnect the penultimate element from the TAIL
            Delete the TAIL
            update TAIL to point to the penultimate element we found earlier

        */
        // Case 1: List is empty
        if (TAIL == nullptr) {
            cout << "The list is empty" << endl;
            return;
        }

        // Case 2: List has only one node
        if (HEAD == TAIL) {
            delete HEAD;
            HEAD = TAIL = nullptr;
            return;
        }

        // Case 3: List has more than one node
        // Node* prevTAIL = TAIL;
        Node* temp = HEAD;
        // Find node just before TAIL
        while (temp->next != TAIL) {
            temp = temp->next;
        }
        temp->next = nullptr;  // remove the reference to the previous TAIL, point to nullptr instead
        // TAIL->next = nullptr; // no need to do this buy may keep for documentation
        delete TAIL;  // Delete previous TAIL node
        TAIL = temp;  // Update TAIL node to be the newly found one
    }

    void insert(int val, int pos) {
        // O(n)
        /*
        (See image in nodes)
        Case 1:
        The position is negative (invalid)

        Case 2:
        The position is 0
            call push_front with the value

        Case 3:
        The position is somewhere in the middle of the list

            3 steps:
            Find the previous node to the position (prevNode)
            Make a new node and connect it to the list (do this first to preserve the link to next node in prevNode position)
            replace prevNode's next connection to the new node we made
        */

        if (pos < 0) {
            cout << "Invalid position" << endl;
            return;
        }

        if (pos == 0) {
            push_front(val);
            return;
        }

        Node* temp = HEAD;
        for (int i = 0; i < pos - 1; i++) {
            if (temp->next == nullptr) {
                cout << "invalid position\n";
                return;
            }
            temp = temp->next;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;

        temp->next = newNode;
    }

    int search(int key) {
        // O(n)
        /*
        Traverse the linked list and check each key
        If key equal to current data return current index

        return -1 by default
        */

        int pos = 0;

        Node* temp = HEAD;
        while (temp->next != nullptr) {
            if (temp->data == key) return pos;
            temp = temp->next;
            ++pos;
        }

        if (temp->data == key) return pos;

        return -1;
    }

    void printLL() {
        Node* temp = HEAD;  // Not performing operations directly on HEAD, we need to preserve this
        while (temp != nullptr) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    // List* l1 = new List();
    List l1;
    // l1.push_front(1);
    // l1.push_front(2);
    // l1.push_front(3);

    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_back(4);

    // l1.pop_front();
    // l1.pop_back();

    // l1.insert(4, 4);
    cout << l1.search(-1) << endl;

    l1.printLL();

    return 0;
}

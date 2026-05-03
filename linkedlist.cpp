/*
Name: Frank Wiygul

Description: provides a list using a singly linked list and can sort in multiple ways,
shuffle the numbers, display the list, search, and remove values using many different algorithms.
*/
#include "linkedlist.h"

// constructor and destructor
LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList()
{
    if(size > 0)
    {
        Node *temp;

        while(head != nullptr)
        {
            // grabs the node after the head
            temp = head->next;

            // deletes the head
            delete head;

            // reassigns the head
            head = temp;
        }
    }
}

// display and add functions (given to you)
void LinkedList::display()
{
    // starts temporary Node at the beginning (head)
    Node *temp = head;

    while(temp != nullptr)
    {
        // displays information
        cout << temp->number << endl;

        // moves the temp node to the next node in the sequence
        temp = temp->next;
    }
}

void LinkedList::append(int number)
{
    // if the list is currently empty
    if(size == 0)
    {
        // create a new node at the head
        // with the information brought in
        head = new Node(number);

        // assigns tail to the head
        tail = head;
    }

    // otherwise, if it's not empty
    else
    {
        // creates a new node
        // with the information brought in
        Node *temp = new Node(number);

        // point current tail to new node
        tail->next = temp;

        // make new node the new tail
        tail = temp;
    }

    size++;
}

void LinkedList::pop()
{
    // error check:
    // checks if the current size is zero
    if(size == 0)
    {
        cout << "List was empty -- pop failed!" << endl;
        return;
    }

    // if removing a node will empty the list
    if(size == 1)
    {
        // store current head
        Node *temp = head;

        // sanity check clear head and tail
        head = nullptr;
        tail = nullptr;

        // delete node
        delete temp;
    }

    // otherwise, if it won't empty the list...
    else
    {
        // grab the node before the tail
        Node *temp = head;

        while(temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        // delete the current tail
        delete tail;

        // sanity check clear the next pointer
        // and assign the new tail
        tail = temp;
        tail->next = nullptr;
    }

    size--;
}

// this shows selection sort
// as applied to linked lists
void LinkedList::sort()
{
    // example shows: selection sort
    for(int i = 0; i < size - 1; i++)
    {
        int smallIndex = i;

        for(int j = i + 1; j < size; j++)
        {
            // gets node at j
            Node *jItem = head;
            for(int k = 0; k < j; k++)
            {
                jItem = jItem->next;
            }

            // gets node at smallIndex
            Node *smallIndexItem = head;
            for(int k = 0; k < smallIndex; k++)
            {
                smallIndexItem = smallIndexItem->next;
            }

            // runs comparison
            if(jItem->number < smallIndexItem->number)
            {
                smallIndex = j;
            }
        }

        // grabs node at index i
        Node *current = head;
        for(int k = 0; k < i; k++)
        {
            current = current->next;
        }

        // grabs node at index smallIndex
        Node *small = head;
        for(int k = 0; k < smallIndex; k++)
        {
            small = small->next;
        }

        // grabs the information at the current node
        // stores it
        int tempNumber = current->number;

        // swaps current data to small data
        current->number = small->number;

        // overwrites small data to the stored data
        // (what used to be in current)
        small->number = tempNumber;
    }
}

// an example of a shuffle algorithm
void LinkedList::shuffle()
{
    // seeds random number
    srand(time(NULL));

    for(int i = 0; i < size; i++)
    {
        int num = rand() % size;

        // swaps current "index" with random "index"

        // gets node at current position
        Node *current = head;
        for(int j = 0; j < i; j++)
        {
            current = current->next;
        }

        // gets node at random position
        Node *random = head;
        for(int j = 0; j < num; j++)
        {
            random = random->next;
        }

        // stores the current Node's information
        int tempNumber = current->number;

        // reassigns the random Node's information to the current
        current->number = random->number;

        // and the stored current information to the random Node
        random->number = tempNumber;
    }
}

int LinkedList::binarySearch(int number)
{
    Node* start = head;
    Node* last = nullptr;
	int bestIndex = -1;

    while (last == nullptr || last != start) {
        
        //find middle node
        Node* slow = start;
        Node* fast = start;

        while (fast != last && fast->next != last) {
            fast = fast->next->next;
            slow = slow->next;
        }

        Node* mid = slow;

        //error check
        if (mid == nullptr) {
            break;
        }

        //check if mid is it
        if (mid->number == number) {
            
            // find index
            int index = 0;
            Node* temp = head;
            
            while (temp != mid) {
                temp = temp->next;
                index++;
            }
            
            //forces search to continue in left half until it is not found to fix the issue listed above
            bestIndex = index;
            last = mid;
        }
        
        //if mid is smaller, ignore left
        else if (mid->number < number) {
            start = mid->next;
        }
        
		//if mid is bigger, ignore right
        else {
            last = mid;
        }
    }
    return bestIndex;
}

void LinkedList::reverseSort()
{
    
    //already sorted
    if (size < 2) {
        return;
    }

    //flag variable
    bool swapped = true;

    while (swapped) {
        swapped = false;
        Node* current = head;

        //check if adjacent variables are in order
        while (current != nullptr && current->next != nullptr) {
            
            //if element is less, swap
            if (current->number < current->next->number) {
                
                //swap
                int temp = current->number;
                current->number = current->next->number;
                current->next->number = temp;

                swapped = true;
            }
            
            //move to next
            current = current->next;
        }
    }
}


void LinkedList::removeValues(int number)
{
    //find index using above
    int pos = binarySearch(number);

    //error check
    if (pos == -1) {
        cout << "Value not found." << endl;
        return;
    }

    while (pos != -1) {
        Node* temp = head;

        //at head
        if (pos == 0) {
            head = head->next;
            delete temp;
        }
        
        //further than head
        else {
            Node* prev = nullptr;
            
            //go until temp hits index
            for (int i = 0; i < pos; i++) {
                prev = temp;
                temp = temp->next;
            }
            
            //unlink
            prev->next = temp->next;

			//if temp is tail, reassign tail
            if (temp == tail) {
                tail = prev;
            }

            delete temp;
        }

        size--;
        
        //search again
        pos = binarySearch(number);
    }

    cout << "Remove completed." << endl;
}

void LinkedList::differentSort()
{
	//already sorted
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    for (Node* cur = head->next; cur != nullptr; cur = cur->next) {
        
        //go from head to cur
        for (Node* temp = head; temp != cur; temp = temp->next) {
			
            //if tmp is bigger, swap
            if (temp->number > cur->number) {
                
                int tempVal = temp->number;
                temp->number = cur->number;
                cur->number = tempVal;
            }
        }
    }
}

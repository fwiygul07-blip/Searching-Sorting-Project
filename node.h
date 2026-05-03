#ifndef NODE_H
#define NODE_H

class Node
{
    public:
        // defines basic information
        int number;
        Node *next; // points to the next Node in the sequence

        // zero constructor
        Node()
        {
            number = 0;
            next = nullptr;
        };

        // takes in basic information
        // assigns next pointer to nullptr
        Node(int number)
        {
            this->number = number;
            next = nullptr;
        };
};

#endif // NODE_H

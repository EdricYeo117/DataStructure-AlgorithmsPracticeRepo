#include <iostream>
#include <stdexcept>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr) {}
};

// Queue implementation using pointers
class Queue
{
public:
    Node *front;
    Node *rear;

    Queue() : front(nullptr), rear(nullptr) {}

    // Check if the queue is empty
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Enqueue an element to the rear of the queue
    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (rear)
        {
            rear->next = newNode;
        }
        rear = newNode;
        if (!front)
        {
            front = rear;
        }
    }

    // Dequeue an element from the front of the queue
    int dequeue()
    {
        if (isEmpty())
        {
            throw runtime_error("Queue is empty");
        }
        Node *temp = front;
        int value = temp->data;
        front = front->next;
        if (!front)
        {
            rear = nullptr;
        }
        delete temp;
        return value;
    }

    // Display the queue
    void display()
    {
        Node *temp = front;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Recursive function to count the number of elements in a queue
    /*
    Time Complexity: O(n) - Each node is visited exactly once.
    Space Complexity: O(n) - Recursive call stack for n nodes.
    */
    int Queue::count()
    {
        return countHelper(front);
    }

    int Queue::countHelper(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return 1 + countHelper(node->next);
    }

    // Recursive function to reverse the queue
    /*
Time Complexity: O(n) - Each element is dequeued and enqueued exactly once.
Space Complexity: O(n) - Recursive call stack for n elements.
*/
    void reverseQueue()
    {
        // Base case: If the queue is empty, return
        if (isEmpty())
        {
            return;
        }

        // Step 1: Dequeue the front element
        int frontElement = dequeue();

        // Step 2: Recursively reverse the remaining queue
        reverseQueue();

        // Step 3: Enqueue the dequeued element to the rear
        enqueue(frontElement);
    }

    // Recursive function to calculate sum of elements in a queue
    /*
Time Complexity: O(n) - Each node is visited exactly once.
Space Complexity: O(n) - Recursive call stack for n nodes.
*/
    int Queue::sum()
    {
        return sumHelper(front);
    }

    int Queue::sumHelper(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return node->data + sumHelper(node->next);
    }

    // Recursive function to find the maximum element in a queue
    /*
    Time Complexity: O(n) - Each node is visited exactly once.
    Space Complexity: O(n) - Recursive call stack for n nodes.
    */
    int Queue::findMax()
    {
        return findMaxHelper(front, INT_MIN);
    }

    int Queue::findMaxHelper(Node *node, int maxSoFar)
    {
        if (node == nullptr)
        {
            return maxSoFar;
        }
        maxSoFar = max(maxSoFar, node->data);
        return findMaxHelper(node->next, maxSoFar);
    }

    // Recursive function to search for an element in a queue
    /*
    Time Complexity: O(n) - Each node is visited until the element is found or the end is reached.
    Space Complexity: O(n) - Recursive call stack for n nodes.
    */
    bool Queue::search(int value)
    {
        return searchHelper(front, value);
    }

    bool Queue::searchHelper(Node *node, int value)
    {
        if (node == nullptr)
        {
            return false;
        }
        if (node->data == value)
        {
            return true;
        }
        return searchHelper(node->next, value);
    }

    // Recursive function to display queue
    /*
    Time Complexity: O(n) - Each node is visited exactly once.
    Space Complexity: O(n) - Recursive call stack for n nodes.
    */
    void Queue::display()
    {
        displayHelper(front);
    }

    void Queue::displayHelper(Node *node)
    {
        if (node == nullptr)
        {
            return;
        }
        cout << node->data << " ";
        displayHelper(node->next);
    }

    // Recursive function to remove all occurences of a value
    /*
    Time Complexity: O(n) - Each node is visited exactly once.
    Space Complexity: O(n) - Recursive call stack for n nodes.
    */
    void Queue::removeAll(int value)
    {
        front = removeAllHelper(front, value);
    }

    Node *Queue::removeAllHelper(Node *node, int value)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (node->data == value)
        {
            Node *temp = node->next;
            delete node;
            return removeAllHelper(temp, value);
        }
        node->next = removeAllHelper(node->next, value);
        return node;
    }

    // Recursive function to count the number of even elements in a queue
    /*
    Time Complexity: O(n) - Each node is visited exactly once.
    Space Complexity: O(n) - Recursive call stack for n nodes.
    */
    int Queue::countEven()
    {
        return countEvenHelper(front);
    }

    int Queue::countEvenHelper(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int count = (node->data % 2 == 0) ? 1 : 0;
        return count + countEvenHelper(node->next);
    }

    // Recursive function to check if the queue is sorted
    /*
    Time Complexity: O(n) - Each node is visited exactly once.
    Space Complexity: O(n) - Recursive call stack for n nodes.
    */
    bool Queue::isSorted()
    {
        return isSortedHelper(front);
    }

    bool Queue::isSortedHelper(Node *node)
    {
        if (node == nullptr || node->next == nullptr)
        {
            return true;
        }
        if (node->data > node->next->data)
        {
            return false;
        }
        return isSortedHelper(node->next);
    }

    // Recursive function to find middle element of a queue
    /*
    Time Complexity: O(n) - Count function takes O(n), and middle search takes O(n).
    Space Complexity: O(n) - Recursive call stack for middle search.
    */
    int Queue::findMiddle()
    {
        int size = count(); // Use the count function to get the size of the queue
        int middleIndex = size / 2;
        return findMiddleHelper(front, middleIndex, 0);
    }

    int Queue::findMiddleHelper(Node *node, int middleIndex, int currentIndex)
    {
        if (node == nullptr)
        {
            return -1; // Should not happen if count is accurate
        }
        if (currentIndex == middleIndex)
        {
            return node->data;
        }
        return findMiddleHelper(node->next, middleIndex, currentIndex + 1);
    }

    // Recursive function to delete alternate nodes
    /*
    Time Complexity: O(n) - Each node is visited exactly once.
    Space Complexity: O(n) - Recursive call stack for n/2 recursive calls.
    */
    void Queue::deleteAlternate()
    {
        front = deleteAlternateHelper(front, true);
    }

    Node *Queue::deleteAlternateHelper(Node *node, bool keep)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (keep)
        {
            node->next = deleteAlternateHelper(node->next, false);
            return node;
        }
        else
        {
            Node *temp = node->next;
            delete node;
            return deleteAlternateHelper(temp, true);
        }
    }
};

int main()
{
    Queue q;

    // Enqueue elements into the queue
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    cout << "Original Queue: ";
    q.display();

    cout << "Number of elements in the queue: " << q.count() << endl;

    // Reverse the queue
    q.reverseQueue();

    cout << "Reversed Queue: ";
    q.display();

    return 0;
}

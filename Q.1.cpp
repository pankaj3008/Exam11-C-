#include<iostream>
using namespace std;

// Node Class
class Node {
public:
    int Data;
    Node* Next;

    Node(int val) {
        Data = val;
        Next = NULL;
    }
};

// Linked List Class
class LL {
    Node* Head;
    Node* Tail;
    int size;

public:
    LL() {
        Head = Tail = nullptr;
        size = -1;
    }

    void push_front(int val) {
        Node* NewNode = new Node(val);

        if (Head == NULL) {
            Head = Tail = NewNode;
        } else {
            NewNode->Next = Head;
            Head = NewNode;
        }
        size++;
    }

    void push_back(int val) {
        Node* NewNode = new Node(val);

        if (Head == NULL) {
            Head = Tail = NewNode;
        } else {
            Tail->Next = NewNode;
            Tail = NewNode;
        }
        size++;
    }

    void insert(int val, int position) {
        if (position < 0 || position > size + 1) {
            cout << "Invalid position" << endl;
            return;
        }

        if (position == 0) {
            push_front(val);
            return;
        }

        if (position == size + 1) {
            push_back(val);
            return;
        }

        Node* NewNode = new Node(val);
        Node* Temp = Head;
        for (int i = 0; i < position - 1; i++) {
            Temp = Temp->Next;
        }

        NewNode->Next = Temp->Next;
        Temp->Next = NewNode;
        size++;
    }

    void delete_at(int position) {
        if (position < 0 || position > size) {
            cout << "Invalid position" << endl;
            return;
        }

        if (position == 0) {
            pop_front();
            return;
        }

        Node* Temp = Head;
        for (int i = 0; i < position - 1; i++) {
            Temp = Temp->Next;
        }

        Node* toDelete = Temp->Next;
        Temp->Next = Temp->Next->Next;
        if (toDelete == Tail) Tail = Temp;
        delete toDelete;
        size--;
    }

    void pop_front() {
        if (Head == NULL) {
            cout << "LL is Empty" << endl;
            return;
        }

        Node* Temp = Head;
        Head = Head->Next;
        delete Temp;
        size--;
    }

    void searching(int key) {
        Node* Temp = Head;
        int pos = 0;
        while (Temp != NULL) {
            if (Temp->Data == key) {
                cout << Temp->Data << " found at position " << pos << endl;
                return;
            }
            Temp = Temp->Next;
            pos++;
        }
        cout << "Invalid Value" << endl;
    }

    void reverse() {
        Node* prev = NULL;
        Node* curr = Head;
        Node* next = NULL;
        Tail = Head;
        while (curr != NULL) {
            next = curr->Next;
            curr->Next = prev;
            prev = curr;
            curr = next;
        }
        Head = prev;
    }

    void Show_list() {
        Node* Temp = Head;
        while (Temp != NULL) {
            cout << Temp->Data << " -> ";
            Temp = Temp->Next;
        }
        cout << "NULL" << endl;
    }
};

// Merge Function
void merge(int arr[], int start, int end, int middle) {
    int leftside = middle - start + 1;
    int rightside = end - middle;

    int left[leftside], right[rightside];

    for (int i = 0; i < leftside; i++)
        left[i] = arr[start + i];
    for (int i = 0; i < rightside; i++)
        right[i] = arr[middle + 1 + i];

    int i = 0, j = 0, k = start;

    while (i < leftside && j < rightside) {
        if (left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i < leftside)
        arr[k++] = left[i++];
    while (j < rightside)
        arr[k++] = right[j++];
}

// Merge Sort
void MS(int arr[], int start, int end) {
    if (start >= end) return;

    int middle = (start + end) / 2;
    MS(arr, start, middle);
    MS(arr, middle + 1, end);
    merge(arr, start, end, middle);
}

// Quick Sort Partition
int partition(int arr[], int start, int end) {
    int pivot = arr[end];
    int idx = start - 1;

    for (int i = start; i < end; i++) {
        if (arr[i] < pivot) {
            idx++;
            swap(arr[i], arr[idx]);
        }
    }
    idx++;
    swap(arr[idx], arr[end]);
    return idx;
}

// Quick Sort
void QS(int arr[], int start, int end) {
    if (start < end) {
        int pivot = partition(arr, start, end);
        QS(arr, start, pivot - 1);
        QS(arr, pivot + 1, end);
    }
}

// Binary Search
int binarysearch(int arr[], int start, int end, int target) {
    if (start > end) return -1;

    int middle = (start + end) / 2;
    if (arr[middle] == target) return middle;
    else if (arr[middle] < target) return binarysearch(arr, middle + 1, end, target);
    else return binarysearch(arr, start, middle - 1, target);
}

// Print Array
void print(int arr[], int N) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main Function
int main() {
    LL list;
    int arr[100], size = 0;
    int choice;

    do {
        cout << endl << " Menu: " << endl;
        cout << "1. Linked List Operations " << endl;
        cout << "2. Input Array " << endl;
        cout << "3. Sort Array (Merge Sort) " << endl;
        cout << "4. Sort Array (Quick Sort) " << endl;
        cout << "5. Binary Search " << endl;
        cout << "6. Display Array " << endl;
        cout << "7. Exit " << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int LLchoice, val, position;
            cout << endl << " Linked List Operations: " << endl;
            cout << "1. Insert at beginning " << endl;
            cout << "2. Insert at any position " << endl;
            cout << "3. Delete at any position " << endl;
            cout << "4. Search Element " << endl;
            cout << "5. Reverse Linked List " << endl;
            cout << "6. Display Linked List " << endl;
            cout << "Enter choice: ";
            cin >> LLchoice;

            if (LLchoice ==1){
                cout << "Enter value to be inserted: ";
                cin >> val;
                list.push_back(val);
            }
            
            if (LLchoice == 2) {
                cout << "Enter the position to be inserted: ";
                cin >> position;
                cout << "Enter the value to be inserted: ";
                cin >> val;
                list.insert(val, position);
            } else if (LLchoice == 3) {
                cout << "Enter position to delete: ";
                cin >> position;
                list.delete_at(position);
            } else if (LLchoice == 4) {
                cout << "Enter the value to search: ";
                cin >> val;
                list.searching(val);
            } else if (LLchoice == 5) {
                list.reverse();
            } else if (LLchoice == 6) {
                list.Show_list();
            }
            break;
        }

        case 2:
            cout << "Enter size of array: ";
            cin >> size;
            cout << "Enter array elements: " << endl;
            for (int i = 0; i < size; i++) {
                cin >> arr[i];
            }
            break;

        case 3:
            MS(arr, 0, size - 1);
            cout << "Array sorted using Merge Sort. " << endl;
            break;

        case 4:
            QS(arr, 0, size - 1);
            cout << "Array sorted using Quick Sort. " << endl ;
            break;

        case 5:
            int key;
            cout << "Enter value to search: ";
            cin >> key;
            int result;
            result = binarysearch(arr, 0, size - 1, key);
            if (result != -1)
                cout << "Element found at index " << result << endl;
            else
                cout << "Element not found. " << endl;
            break;

        case 6:
            cout << "Array: ";
            print(arr, size);
            break;

        case 7:
            cout << "Exiting program... " << endl;
            break;

        default:
            cout << "Invalid choice. " << endl;
        }

    } while (choice != 7);

    return 0;
}

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

class Book;

class Book {
public:
    int ID;
    string title;
    int copies;
};

class NODE {
public:
    NODE* pNext;
    NODE* pPrev;
    Book* nData;
};

NODE* pHead = NULL, * pTail = NULL;

void AppendNode(NODE* pNode) {
    if (!pHead) {
        pHead = pTail = pNode;
        pNode->pPrev = pNode->pNext = NULL;
    }
    else {
        pTail->pNext = pNode;
        pNode->pPrev = pTail;
        pNode->pNext = NULL;
        pTail = pNode;
    }
}

void RemoveNode(NODE* pNode) {
    if (!pNode) return;
    if (pNode->pPrev) pNode->pPrev->pNext = pNode->pNext;
    else pHead = pNode->pNext;
    if (pNode->pNext) pNode->pNext->pPrev = pNode->pPrev;
    else pTail = pNode->pPrev;
    delete pNode->nData;
    delete pNode;
}

void DeleteAllNodes() {
    NODE* pNode = pHead;
    while (pNode) {
        NODE* pNext = pNode->pNext;
        delete pNode->nData;
        delete pNode;
        pNode = pNext;
    }
    pHead = pTail = NULL;
}



// Simple integer validation function
int validateIntInput(string answer) {// prompt user for an integer input and validate it
    int value;
    cout << answer;
	while (!(cin >> value)) {// while the input is not an integer
        cout << "Invalid input. Please enter a number from 1 to 4: ";
        cin.clear();
        cin.ignore(100, '\n');
    }
    return value;
}

// Load books from file into linked list
int loadBooksFromFile(const string& filename) {
    ifstream fin(filename.c_str());
    if (!fin) {
        cout << "Error: File not found!" << endl;
        return 0;
    }
    int count = 0;
    while (true) {
        Book* bk = new Book;
        if (!(fin >> bk->ID)) {
            delete bk;
            break;
        }
        fin.ignore(); // skip one character (likely a space or comma)
        getline(fin, bk->title, ',');
        fin >> bk->copies;
        NODE* pNode = new NODE;
        pNode->nData = bk;
        AppendNode(pNode);
        count++;
    }
    fin.close();
    return count;
}

// Display all books
void displayBooks() {
    cout << "\n\tID\t\tTitle\t\t\t\tStatus\n";
    cout << "\t----------------------------------------------------------------------\n";
    for (NODE* pNode = pHead; pNode != NULL; pNode = pNode->pNext) {
        cout << "\t" << pNode->nData->ID << "\t" << pNode->nData->title << "\t";
        if (pNode->nData->copies > 0)
            cout << "\t" << "[" << pNode->nData->copies << " copies available]";
        else
            cout << "\t" << "[0]";
        cout << "\n" << endl;
    }
}

// function to update the copies to a book by add more copies 
void updateCopies() {
    int id = validateIntInput("Enter Book ID to update: ");
    for (NODE* pNode = pHead; pNode != NULL; pNode = pNode->pNext) {
        if (pNode->nData->ID == id) {
            int add = validateIntInput("Enter new amount of copies: ");
            pNode->nData->copies += add;
            cout << "Book copies updated!\n";
            return;
        }
    }
    cout << "Book ID not found.\n\n";
    
}

// Display statistics
void displayStats() {
    int total = 0, outOfStock = 0, max_copies = 0;
    NODE* highNode = NULL;
    int count = 0;
    for (NODE* pNode = pHead; pNode != NULL; pNode = pNode->pNext) {
        total += pNode->nData->copies;
        if (pNode->nData->copies == 0) outOfStock++;
        if (pNode->nData->copies > max_copies) {
            max_copies = pNode->nData->copies;
            highNode = pNode;
        }
        count++;
    }
    cout << "\nTotal copies in stock: " << total << endl;
    if (highNode)
        cout << "Book with highest copies: " << highNode->nData->title
        << " (" << highNode->nData->copies << ")\n";
    else
        cout << "No books available.\n";
    if (count > 0)
        cout << "Percentage out of stock: " << (outOfStock * 100.0 / count) << "%\n";
    else
        cout << "Percentage out of stock: 0%\n";
    
}


int main( ) {
    int n = loadBooksFromFile("books.txt");
    if (n == 0) {
        cout << "No books loaded. Exiting.\n";
        return 0;
    }

    int choice;
    do {
        cout << "\n" "Welcome to library Book Menu Option ";
        cout << " Menu:\n\n";
        cout << "1. Display all books from the menu\n";
        cout << "2. Update copies of books in the menu\n";
        cout << "3. Provide current status of the menu \n";
        cout << "4. Exit\n";

        choice = validateIntInput("Type your choice: ");

        switch (choice) {
        case 1: displayBooks(); break;
        case 2: updateCopies(); break;
        case 3: displayStats(); break;
        case 4: cout << "Exiting Book Menu !\n"; break;
        default: cout << " Not valid! Please choose between 1 to 4.\n";
        }
    } while (choice != 4);

    DeleteAllNodes();
}
#pragma once	
#include "Book.h"
#include "Node.h"
void AppendNode(NODE* pNode);
void RemoveNode(NODE* pNode);
	
void DeleteAllNodes();
int loadBooksFromFile(const string& filename);
void displayBooks();
void updateCopies();
void displayStats();
	
int validateIntInput(const string& prompt);
	
int validateMenuChoice(const string& prompt, int min, int max);
	
void saveBooksToFile(const string& filename);
for (NODE* pNode = pHead; pNode != NULL; pNode = pNode->pNext) {
	//         total++;
	//         if (pNode->nData->copies == 0)
		
	//             outOfStock++;
		
	

#pragma once
#include <string>
using namespace std;
class NODE {
public:
    NODE* pNext;
    NODE* pPrev;
    Book* nData;
};

NODE* pHead = NULL, * pTail = NULL;

#include "SqList.h"
#include <assert.h>
#include <iostream>
#include <algorithm>
SqList::SqList() {
    // 分配基地址，以及初始存储容量(LIST_INIT_SIZE)
    elem = new ElemType[LIST_INIT_SIZE];

    // 空间不足
    // if (!elem) {
    //     std::cout << "未成功初始化当前顺序表对象" << std::endl;
    //     exit(OVERFLOW);
    // }

    length = 0;               // 空表长度为0
    listSize = LIST_INIT_SIZE;// 初始存储容量
}

SqList::SqList(std::initializer_list<ElemType> ilist) : SqList() {
    assert(ilist.size() <= this->listSize);

    for (int i = 0; i < ilist.size(); i++) {
        *(elem + i) = *(ilist.begin() + i);
    }

    length = ilist.size();
}

SqList::~SqList() {
    delete[] elem;
}

ElemType SqList::at(int pos) {
    // if (pos < 0 || pos > length) {// 下标有误
    //     // std::cout << "null" << std::endl;
    //     return NULL;
    // } else {
    //     return elem[pos - 1];
    // }
    if (pos < 0 || pos > length)
        throw std::length_error("SqList::at() subscript out of range");
    return elem[pos];
}

ElemType SqList::operator[](int pos) {
    assert(pos >= 0 && pos < length);
    return elem[pos];
}

bool SqList::isEmpty() {
    return length == 0;
}

int SqList::getLength() {
    return length;
}

int SqList::findIndex(ElemType element) {
    int i{0};
    for (; i < length; i++) {
        if (elem[i] == element) {
            return i;
        }
    }
    if (i >= length)
        return ERROR;
}

void SqList::print() {
    for (int i = 0; i < length; i++) {
        std::cout << elem[i] << " ";
    }
    std::cout << std::endl;
}

Status SqList::insert(int pos, ElemType element) {
    assert(pos >= 0 && pos < length);

    if (length >= listSize) {
        auto *newBase = (ElemType *) realloc(elem, (listSize + LISTINCREMENT) * sizeof(ElemType));

        if (!newBase)
            exit(OVERFLOW);

        elem = newBase;
        listSize += LISTINCREMENT;
    }

    auto q = &elem[pos];
    for (auto p = &elem[length - 1]; p >= q; p--)
        *(p + 1) = *p;
    *q = element;
    length++;
    return OK;
}

Status SqList::push_back(ElemType element) {
    if (length >= listSize) {
        auto *newBase = (ElemType *) realloc(elem, (listSize + LISTINCREMENT) * sizeof(ElemType));

        if (!newBase)
            exit(OVERFLOW);

        elem = newBase;
        listSize += LISTINCREMENT;
    }

    elem[length] = element;
    length++;
    return OK;
}

Status SqList::erase(int pos) {
    assert(pos >= 0 && pos < length);

    auto q = &elem[length - 1];
    for (auto p = &elem[pos + 1]; p <= q; p++)
        *(p - 1) = *p;
    length--;
    return OK;
}

void SqList::erase(ElemType element, Range range) {
    switch (range) {
        case Range::all:
            erase(findIndex(element));
            break;
        case Range::first:
            while (true) {
                if (findIndex(element))
                    erase(findIndex(element));
                else
                    break;
            }
            break;
    }
}

Status SqList::pop_back(){
    assert(!isEmpty());
    length--;
    return OK;
}

Status SqList::clear() {
    assert(!isEmpty());
    length = 0;
    return OK;
}

bool descendCmp(ElemType a, ElemType b){
    return a > b;
}

Status SqList::sort(int beginPos, int endPos, SortWay sortWay) {
    assert(beginPos <= endPos);
    assert(beginPos >= 0);
    assert(endPos <= length);

    switch(sortWay){
        case SortWay::Ascend:
            std::sort(elem + beginPos, elem + endPos);
            break;
        case SortWay::Descend:
            std::sort(elem + beginPos, elem + endPos, descendCmp);
            break;
    }
}
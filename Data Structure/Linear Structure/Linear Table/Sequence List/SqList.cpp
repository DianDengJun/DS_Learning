//
// Created by hsing on 2020/10/28.
//
#include <iostream>
#include <cstdlib>
#include "SqList.h" // 自定义头文件SqList.h

using std::cout;
using std::endl;
using std::cin;

// 初始化一个空的动态顺序表
Status InitList_Sq(SqList &L)
{
    // 构造一个空的线性表L
    L.elem = new ElemType [LIST_INIT_SIZE]; // 分配基地址，以及初始存储容量(LIST_INIT_SIZE)

    if (!L.elem)
        exit(OVERFLOW); // 存储分配失败，返回OVERFLOW

    L.length = 0;				 // 空表长度为0
    L.listsize = LIST_INIT_SIZE; // 初始存储容量

    return OK; // 初始化成功，返回OK
}

// 创建动态顺序表
Status CreatList_Sq(SqList &L, int n) // n:要输入元素的个数
{
    int i;
    if (n > L.listsize) // 要输入元素的不能超过分配的存储容量
        return ERROR;

    cout << "输入这" << n << "个整型数:" << endl;
    for (i = 0; i < n; i++)
        cin >> L.elem[i];

    L.length = n; // 表长度更改为n
    return OK;	  // 创建成功，返回OK
}

// 输出动态顺序表的元素
void PrintList_Sq(SqList L)
{
    int i;
    for (i = 0; i < L.length; i++)
        cout << L.elem[i] << "\t";
    cout << endl;
}

// 插入新的元素e到第i个位序
Status ListInsert_Sq(SqList &L, int i, ElemType e) //注意：用户输入的i一定从1开始
{
    ElemType *newbase, *q, *p;
    /*
     * newbase:新基地址
     * q:要插入位置的指针
     * p:指针参数,用于移动至下一个位置
    */
    if (i < 1 || i > L.length) // 插入位置不合法
        return ERROR;

    if (L.length >= L.listsize) // 当前存储空间不足
    {
        newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType)); // 重新分配基地址，以及顺序表的存储容量

        if (!newbase) // 存储位置失败
            exit(OVERFLOW);

        L.elem = newbase;			 // 新基地址
        L.listsize += LISTINCREMENT; // 增加存储位置
    }

    q = &(L.elem[i - 1]); // 定位到要插入的位置
    // 将插入位置后的所有元素右移
    for (p = &(L.elem[L.length - 1]); p >= q; --p)
        *(p + 1) = *p;
    *q = e;		// 在q位置插入e
    ++L.length; // 表长增加1
    return OK;	// 插入成功，返回OK
}

// 删除第i个元素
Status ListDelete_Sq(SqList &L, int i, ElemType &e) // e用作记录被删除元素的值
{
    ElemType *p, *q;
    /*
     * p:记录要删除元素位置的指针
     * q:指针参数,用于移动至上一个位置
    */

    if (i < 1 || i > L.length) // 删除位置不合法
        return ERROR;

    p = &(L.elem[i - 1]);	   // 记录要删除元素位置的指针
    e = *p;					   // 被删除元素的值赋给e
    q = L.elem + L.length - 1; // 表尾位置元素的指针
    // 将删除位置后的所有元素左移
    for (++p; p <= q; ++p)
        *(p - 1) = *p;
    --L.length; // 表长减少1

    return OK; // 删除成功，返回OK
}

// 查找给定值的位序(第一个)
int LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType)) // 此处使用了函数指针
// 在顺序表L中查找第1个值与e满足compare()的元素的位序
{
    ElemType *p; //p:指针参数，用于移动至下一个位置
    int i = 1;	 //i:位序
    p = L.elem;	 //将p指向第一个位序
    while (i <= L.length && !(*compare)(*(p++), e))
        i++;
    if (i <= L.length)
        // 找到位序
        return i;
    else
        // 未找到，返回ERROR;
        return ERROR;
}

// 判断两个元素是否相等
// 此函数为LocatedElem_Sq函数准备第三个实参
Status equal(ElemType x, ElemType y)
{
    if (x == y)
        return OK;
    else
        return ERROR;
}

// 对顺序表进行排序
void sort(SqList &L)
{

    int t;
    for (int i = 1; i < L.length; i++)
    {
        for (int j = 0; j < L.length - 1; j++)
        {
            if (L.elem[j] > L.elem[j + 1])
            {
                t = L.elem[j];
                L.elem[j] = L.elem[j + 1];
                L.elem[j + 1] = t;
            }
        }
    }
}

// 删除给定值的第一个元素，或全部元素
void Delete_Elem(SqList &L, int elem, int model) // model为1表示删除所有元素，为0表示删除所有元素
{
    switch (model)
    {
        case 1:
            ListDelete_Sq(L, LocateElem_Sq(L, elem, equal), elem);
            break;
        case 0:
            while(true){
                if(LocateElem_Sq(L,elem,equal)){
                    ListDelete_Sq(L, LocateElem_Sq(L, elem, equal), elem);
                }else{
                    break;
                }
            }
            break;
    }
}

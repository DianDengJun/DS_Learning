//
// Created by hsing on 2020/10/28.
//

#ifndef TABLE_H
#define TABLE_H

#define OK 1
#define ERROR 0
#define OVERFLOW -2 // 溢出

#define LIST_INIT_SIZE 10 // 线性表存储空间的初始分配量
#define LISTINCREMENT 2      // 线性表存储空间的分配增量

typedef int Status;      // 设定为返回值为符号常量OK、ERROR等值的函数类型
typedef int ElemType; // 设定基本元素类型ElemType为int

//	数据结构
typedef struct {
    ElemType *elem; // 存储空间基地址
    int length;        // 当前长度
    int listsize;    // 当前分配的存储容量(单位是sizeof(ElemType))
} SqList;

/************************函数声明************************/
// 初始化一个空的动态顺序表
Status InitList_Sq(SqList &L);

// 创建动态顺序表
Status CreatList_Sq(SqList &L, int n);

// 输出动态顺序表的元素
void PrintList_Sq(SqList L);

// 插入新的元素e到第i个位序
Status ListInsert_Sq(SqList &L, int i, ElemType e);

// 删除第i个元素
Status ListDelete_Sq(SqList &L, int i, ElemType &e);

// 查找给定值的位序
int LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType));

// 判断两个元素是否相等
Status equal(ElemType x, ElemType y);

// 对顺序表进行排序
void sort(SqList &L);

// 删除给定值的第一个元素，或全部元素
void Delete_Elem(SqList &L, int elem, int model); // model为1表示删除所有元素，为0表示删除所有元素
#endif //TABLE_H


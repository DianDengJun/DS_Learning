/**
 * @file Sqlist.h
 * @brief 动态顺序表头文件
*/

#pragma once

#include <initializer_list>// 初始化列表

#define OK 1
#define ERROR 0
#define OVERFLOW -2// 溢出

#define LIST_INIT_SIZE 10// 线性表存储空间的初始分配量
#define LISTINCREMENT 2  // 线性表存储空间的分配增量

using Status = int;  // 设定为返回值为符号常量OK、ERROR等值的函数类型
using ElemType = int;// 设定基本元素类型ElemType为int

// 范围标识
enum class Range {
    first,
    all
};

// 排序方式
enum class SortWay {
    Ascend,// 升序
    Descend// 降序
};

class SqList {
private:
    ElemType *elem;// 基地址
    int length{0};    // 当前已有元素数量
    int listSize{0};  // 当前分配的存储容量(单位是sizeof(ElemType))
public:
    /**********构造**********/
    // 默认构造函数，用于初始化一个空的动态顺序表
    SqList();
    // 使用初始化列表进行顺序表的构造，相当于初始化非空的动态顺序表
    SqList(std::initializer_list<ElemType> ilist);
    // 析构函数，用于销毁顺序表
    ~SqList();

    /**********元素访问**********/
    // 访问指定序号元素
    ElemType at(int pos);
    // 访问指定序号元素
    ElemType operator[](int pos);

    /**********容量**********/
    // 检查顺序表是否为空
    bool isEmpty();
    // 返回当前已有元素的数量
    int getLength();

    /**********查找**********/
    // 查找元素第一次出现的位序
    int findIndex(ElemType element);

    /**********遍历**********/
    // 输出动态顺序表
    void print();

    /**********修改器**********/
    // 插入元素到指定位置
    Status insert(int pos, ElemType element);
    // 将元素添加到顺序表末尾
    Status push_back(ElemType element);
    // 删除指定位置上的元素
    Status erase(int pos);
    // 删除给定值的第一个元素，或所有元素，默认为所有元素
    /**
     * @brief 删除顺序表中的给定值元素
     * @param element 待删除的元素
     * @param range 删除的范围，
     *              选项：全部(Range::All)，第一个(Range::first)
    */
    void erase(ElemType element, Range range);
    // 移除末尾元素
    Status pop_back();
    // 清除所有元素
    Status clear();
    /**
     * @brief 对顺序表进行排序
     * @param beginPos 起始位置
     * @param endPos 终止位置
     * @param sortWay 排序方式，
     *                默认为升序(SortWay::Ascend)，
     *                或者可以是降序(SortWay::Descend)
     * @return 返回是否成功排序
    */
    Status sort(int beginPos, int endPos, SortWay sortWay = SortWay::Ascend);
};
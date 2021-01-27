#include <iostream>
#include "SqList.h"

using std::cout;
using std::endl;
using std::cin;

int menu_select(); // 输出菜单的函数声明

// 主函数，程序入口处
int main() {
    SqList L; // 实例化一个顺序表L
    Status s; // 状态参数

    auto n{0}, i{0}, e{0}; // 中间变量

    while (true) {
        switch (menu_select()) // 根据菜单函数的返回值选则相应的功能
        {
            case 1: // 初始化动态顺序表
                s = InitList_Sq(L); // 调用函数InitList_Sq进行初始化
                if (s)
                    cout << "初始化成功" << endl;
                else // 返回OVERFLOW，空间溢出，无法初始化顺序表
                    cout << "初始化失败" << endl;
                break;

            case 2: // 创建动态顺序表
                cout << "输入线性表的长度:";
                cin >> n;
                s = CreatList_Sq(L, n); // 调用函数CreatList_Sq创建顺序表
                if (s)
                    cout << "创建成功" << endl;
                else
                    cout << "创建失败" << endl;
                break;

            case 3: // 输出动态顺序表中的元素
                PrintList_Sq(L); // 调用函数PrintList_Sq输出顺序表
                break;

            case 4: // 在动态顺序表中插入元素
                cout << "请输入插入的位序:";
                cin >> i;
                cout << "请输入插入的新元素的值:";
                cin >> e;
                s = ListInsert_Sq(L, i, e);
                if (s)
                    cout << "插入成功!" << endl;
                else
                    cout << "插入失败!" << endl;
                break;

            case 5: // 删除动态顺序表中的元素
                cout << "输入删除的位序：";
                cin >> i;
                s = ListDelete_Sq(L, i, e);
                if (s)
                    cout << "删除了元素" << e << "成功" << endl;
                else
                    cout << "删除失败" << endl;
                break;

            case 6: // 查找给定元素值的位序
                cout << "请输入查找的元素的值:";
                cin >> e;
                i = LocateElem_Sq(L, e, equal); // 指向函数类型的指针作形参，实参用同类型的函数名equal
                if (i)
                    cout << e << "的逻辑位序是" << i << endl;
                else
                    cout << "查找失败!" << endl;
                break;

            case 7: // 对顺序表排序
                sort(L);
                cout << "已经对顺序表进行升序排列!" << endl;
                break;

            case 8: // 删除给定值的第一个元素，或全部元素
            {
                auto elem{0}, model{0};
                cout << "请输入想要删除的值:";
                cin >> elem;
                if (LocateElem_Sq(L, elem, equal) == ERROR) {
                    cout << "没有找到在顺序表这个值!" << endl;
                    break;
                } else {
                    cout << "在顺序表中找到了这个值!" << endl;
                }
                cout << "您是想要仅删除给定值第一个元素，还是所有元素?" << endl;
                cout << "输入1表示仅删除第一个，输入0表示所有:" << endl;
                while (true) {
                    cin >> model;
                    if (model == 0 || model == 1)
                        break;
                    else
                        cout << "错误！重新输入0或1:";
                }
                Delete_Elem(L, elem, model);
                if (model) {
                    cout << "已经成功删除给定值的第一个元素" << endl;
                } else {
                    cout << "已经成功删除给定值的所有元素" << endl;
                }
            }
                break;

            case 0: // 退出程序
                cout << "程序结束，谢谢使用！" << endl << endl;
                exit(0);
        }
    }
}

// 输出菜单函数
int menu_select() {
    auto sn{0};
    cout << endl
         << "显示菜单" << endl
         << "1.初始化" << endl
         << "2.创建" << endl
         << "3.显示" << endl
         << "4.插入" << endl
         << "5.删除位序" << endl
         << "6.查找" << endl
         << "7.排序" << endl
         << "8.删除值" << endl
         << "0.退出" << endl
         << "输入 0-8:";
    while (true) {
        cin >> sn;
        if (sn < 0 || sn > 8)
            cout << endl
                 << "输入错误，重选0－8:";
        else
            break;
    }
    return sn;
}

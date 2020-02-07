/*
    Old demo of linked lists, I wrote few years ago.
        ~ Ziemowit.
*/

#ifndef _Z_LIST_
#define _Z_LIST_

#include <iostream>

using namespace std;

namespace zst{

template <typename T>
struct listItem
{
    T content;
    listItem<T> * NEXT;
};

template <typename Any>
class ZList
{
private:
    struct INFO{
        listItem<Any> *FRONT;
        listItem<Any> *END;
    };
    INFO inf;
    int number_of_items;
public:
    ZList();                        
    ~ZList();
    ZList& operator--(Any);
    bool is_empty() { return inf.FRONT==nullptr; }
    void show();
    bool push_back(Any);
    void reset() { inf.FRONT=inf.END=nullptr; }
};

//===================================================================================================//

template <typename Any>
ZList<Any>::ZList()
{
    inf.FRONT=inf.END=nullptr;
}

template <typename Any>
ZList<Any>::~ZList()
{
    while (!is_empty()) (*this)--;
}

template <typename Any>
void ZList<Any>::show()
{
    listItem<Any> *LI = inf.FRONT;
    if(is_empty())
        cerr << "List is empty." << endl;
    else
    {
        int i = 1;
        while(LI != nullptr)
        {
            cout << i++ << ": " << LI->content << endl;
            LI = LI->NEXT;
        }
    }
}

template <typename Any>
ZList<Any>& ZList<Any>::operator--(Any)
{
    if(inf.FRONT == inf.END)
    {
        delete inf.FRONT;
        inf.FRONT = inf.END = nullptr;
    }
    else
    {
        listItem<Any> * tmp = inf.FRONT;
        while((tmp->NEXT) != inf.END)
            tmp = tmp->NEXT;
            inf.END = tmp;
            delete tmp->NEXT;
            tmp->NEXT = nullptr;
    }
    return(*this);
}

template <typename Any>
bool ZList<Any>::push_back(Any strc)
{
    listItem<Any> * it = new listItem<Any>;
    it->content = strc;
    it->NEXT = nullptr;
    if(is_empty())
        inf.FRONT=inf.END=it;
    else
    {
        inf.END->NEXT=it;
        inf.END=it;
    }
    number_of_items++;
    return true;
}

} // namespace zst

#endif //_Z_LIST_

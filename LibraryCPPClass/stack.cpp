#include "stack.h"

Stack::Stack()
{
}

Stack::Stack(const Stack &a) : list_(a.list_)
{
}

Stack &Stack::operator=(const Stack &a)
{
    if (this == &a) return *this;
    list_ = a.list_;
    return *this;
}

Stack::~Stack()
{
}

void Stack::push(Data data)
{
    list_.insert(data);
}

Data Stack::get() const
{
    if (list_.first())
    {
        return list_.first()->data();
    }
    return Data();
}

void Stack::pop()
{
    list_.erase_first();
}

bool Stack::empty() const
{
    return list_.first() == nullptr;
}
#include <cstddef>
#include "list.h"

List::List() : head_(nullptr), tail_(nullptr)
{
}

List::List(const List &a) : head_(nullptr), tail_(nullptr)
{
    Item *curr = a.head_;
    while (curr)
    {
        if (!head_) {
            head_ = tail_ = new Item(curr->val_, nullptr, nullptr);
        } else {
            tail_->next_ = new Item(curr->val_, nullptr, tail_);
            tail_ = tail_->next_;
        }
        curr = curr->next();
    }
}

List &List::operator=(const List &a)
{
    if (this == &a) return *this;

    while (head_) {
        Item *to_delete = head_;
        head_ = head_->next_;
        delete to_delete;
    }
    tail_ = nullptr;

    Item *curr = a.head_;
    while (curr)
    {
        if (!head_) {
            head_ = tail_ = new Item(curr->val_, nullptr, nullptr);
        } else {
            tail_->next_ = new Item(curr->val_, nullptr, tail_);
            tail_ = tail_->next_;
        }
        curr = curr->next();
    }
    return *this;
}

List::~List()
{
    Item *current = head_;
    while (current != nullptr)
    {
        Item *next_item = current->next_;
        delete current;
        current = next_item;
    }
}

List::Item *List::first()
{
    return head_;
}

const List::Item *List::first() const
{
    return head_;
}

List::Item *List::last()
{
    return tail_;
}

const List::Item *List::last() const
{
    return tail_;
}

List::Item *List::insert(Data data)
{
    Item *new_item = new Item(data, head_, nullptr);
    if (head_)
    {
        head_->prev_ = new_item;
    }
    else
    {
        tail_ = new_item;
    }
    head_ = new_item;
    return new_item;
}

List::Item *List::insert_after(Item *item, Data data)
{
    if (!item)
    {
        return insert(data);
    }

    Item *new_item = new Item(data, item->next_, item);
    if (item->next_)
    {
        item->next_->prev_ = new_item;
    }
    else
    {
        tail_ = new_item;
    }
    item->next_ = new_item;
    return new_item;
}

List::Item *List::erase_first()
{
    if (!head_) return nullptr;

    Item *next_item = head_->next_;
    if (next_item)
    {
        next_item->prev_ = nullptr;
    }
    else
    {
        tail_ = nullptr;
    }

    delete head_;
    head_ = next_item;
    return head_;
}

List::Item *List::erase_next(Item *item)
{
    if (!item)
    {
        return erase_first();
    }

    Item *target = item->next_;
    if (!target) return nullptr;

    Item *next_item = target->next_;
    item->next_ = next_item;

    if (next_item)
    {
        next_item->prev_ = item;
    }
    else
    {
        tail_ = item;
    }

    delete target;
    return next_item;
}
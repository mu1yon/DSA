#ifndef LIST_H
#define LIST_H

#include <cstddef>

// Change it to desired type
typedef int Data;

class List
{
public:
    class Item
    {
    public:
        Item(Data val, Item *n = nullptr, Item *p = nullptr)
            : next_(val ? n : n), prev_(p), val_(val) {}

        Item *next() { return next_; }
        const Item *next() const { return next_; }

        Item *prev() { return prev_; }
        const Item *prev() const { return prev_; }

        Data data() const { return val_; }
        void set_data(Data data) { val_ = data; }

        Item *next_;
        Item *prev_;
        Data val_;
    };

    // Creates new list
    List();

    // copy constructor
    List(const List &a);

    // assignment operator
    List &operator=(const List &a);

    // Destroys the list and frees the memory
    ~List();

    // Retrieves the first item from the list
    Item *first();
    const Item *first() const;

    // Retrieves the last item of the list
    Item *last();
    const Item *last() const;

    // Inserts new list item into the beginning
    Item *insert(Data data);

    // Inserts new list item after the specified item
    // Inserts first element if item is null
    Item *insert_after(Item *item, Data data);

    // Deletes the first list item.
    // Returns pointer to the item next to the deleted one.
    Item *erase_first();

    // Deletes the list item following the specified one.
    // Deletes the first element when item is null.
    // Returns pointer to the item next to the deleted one.
    // Should be O(1)
    Item *erase_next(Item *item);

private:
    Item *head_;
    Item *tail_;
};

#endif
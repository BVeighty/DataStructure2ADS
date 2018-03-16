#include "liste.h"

using namespace std;

Liste::Liste()
{
    nb = 0;
}

int Liste::count() { return nb; }
Node* Liste::get_first() { return first; }

Node* Liste::get_node(int index)
{
    if (index >= nb or index < 0)
    {
        cout << "Error not that many element" << endl;
        return NULL;
    }

    Node* current = first;

    for(int i = 0; i < index; i++)
    {
        current = current->get_next();
    }
    return current;
}
int Liste::get(int index)
{
    if (index >= nb)
    {
        cout << "Error not that many element" << endl;
        return -1;
    }

    Node* current = first;

    for(int i = 0; i < index; i++)
    {
        current = current->get_next();
    }
    return current->get_value();
}

void Liste::insert_first(int val)
{
    Node* node = new Node(val);
    node->set_next(first);
    first = node;
    nb++;
}

void Liste::insert_last(int val)
{
    Node* node = new Node(val);
    Node* last = get_node(nb-1);
    last->set_next(node);
    nb++;
}

void Liste::insert(int val, int i)
{
    if (i >= nb)
    {
        cout << "Error not that many element" << endl;
        return;
    }

    Node* prev_node = get_node(i-1);
    Node* next_node = get_node(i);
    Node* new_node = new Node(val);

    prev_node->set_next(new_node);
    new_node->set_next(next_node);

    nb++;
}

int Liste::search(int val)
{
    Node* current = first;
    for(int i = 0; i < nb; i++)
    {
        if (current->get_value() == val)
        {
            return i;
        }
        current = current->get_next();
    }
    return -1; // Not found
}

void Liste::remove(int index)
{
    Node* removed = get_node(index);
    Node* prev = get_node(index - 1);
    Node* next = removed->get_next();

    if (removed == NULL)
    {
        return;
    }

    if (prev)
    {
        prev->set_next(next);
    } else
    {
        first = next;
    }

    removed->set_next(NULL);
    removed = NULL;
    delete removed;
    nb--;
}

void Liste::remove_by_value(int val)
{
    int index = search(val);
    if (index != -1)
    {
        remove(index);
    }
}

void Liste::update(int index, int value)
{
    Node* node = get_node(index);
    node->set_value(value);
}

bool Liste::is_empty()
{
    return nb == 0;
}

void Liste::print()
{
    cout << "[";
    Node* current = first;

    for(int i = 0; i < nb; i++)
    {
        cout << current->get_value() << ", ";
        current = current->get_next();
    }
    cout << "]" << endl;
}

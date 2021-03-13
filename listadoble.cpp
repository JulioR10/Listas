#include "listadoble.h"

ListaDoble::ListaDoble()
{

}

void ListaDoble::for_each(std::function<void (TipoDato &)> action) const
{

}

void ListaDoble::enumerate(std::function<void (int, TipoDato &)> action) const
{

}

int ListaDoble::size() const
{

}

bool ListaDoble::empty() const
{

}

void ListaDoble::push_back(const TipoDato &dato)
{

}

void ListaDoble::push_front(const TipoDato &dato)
{

}

void ListaDoble::insert(const TipoDato &dato, int pos)
{
    if (pos == 0) { // This is a particular scenario
        this->push_front(dato);
        return;
    }

    // Create the element we are going to insert
    auto elem = std::make_shared<ElementoListaDoble>(ElementoListaDoble{dato});

    // Search for the position where we are going to insert
    auto iterator = front;
    int idx = 0;
    while (idx != pos) {
        iterator = iterator->next;
        idx++;
    }

    // Now assign the pointers properly
    elem->next = iterator;
    elem->prev = iterator->prev;
    elem->next->prev = elem;
    elem->prev->next = elem;
}

void ListaDoble::pop_back()
{
    if (front != back) {
        // Take the element before the latest one
        auto prevprev = back->prev;
        // The next element now is 'nullptr'
        prevprev->next = nullptr;

        // Update the value of 'back'
        back = prevprev;
    } else { // If there is only one element in the list
        this->clear(); // Just clear the list
    }
}

void ListaDoble::pop_front()
{

}

void ListaDoble::clear()
{

}

void ListaDoble::erase(int pos)
{

}

void ListaDoble::swap(int pos1, int pos2)
{

}

int ListaDoble::search(const TipoDato &dato) const
{

}

void ListaDoble::sort()
{

}

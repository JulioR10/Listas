#include "listasimple.h"

ListaSimple::ListaSimple() : front{nullptr}, back{nullptr}
{

}

ListaSimple::ListaSimple(const TipoDato & dato)
{
    front = std::make_shared<ElementoListaSimple>(ElementoListaSimple{dato});
    back = front;
    // both are pointing to the same element
}

void ListaSimple::push_back(const TipoDato &dato)
{
    std::shared_ptr<ElementoListaSimple> elem = std::make_shared<ElementoListaSimple>(ElementoListaSimple{dato});
    if(front == nullptr){
        front = elem;
        back = elem;
    }else{
        back->next = elem;
        back = elem;
    }
}

void ListaSimple::push_front(const TipoDato &dato)
{
    std::shared_ptr<ElementoListaSimple> elem = std::make_shared<ElementoListaSimple>(ElementoListaSimple{dato});
    if(front == nullptr){
        front = elem;
        back = elem;
    }else{
        elem->next = front;
        front = elem;
    }
}

void ListaSimple::pop_back()
{

}

void ListaSimple::pop_front()
{

}

void ListaSimple::clear()
{

}

void ListaSimple::erase(int pos)
{

}

void ListaSimple::swap(int pos1, int pos2)
{

}

int ListaSimple::find(const TipoDato &dato) const
{

}

void ListaSimple::sort()
{

}

bool ListaSimple::is_sorted() const
{

}

void ListaSimple::for_each(std::function<void (TipoDato&)> action) const
{
    std::shared_ptr<ElementoListaSimple> iterator = front;
    while(iterator->next != nullptr){
        action(iterator->dato);//Call the action
        iterator = iterator->next;
    }
}

void ListaSimple::enumerate(std::function<void (int, TipoDato &)> action) const
{
    //Iterate the list as usual
    std::shared_ptr<ElementoListaSimple> iterator = front;
    int id = 0;
    while(iterator->next != nullptr){
        action(id, iterator->dato);//Call the action
        iterator = iterator->next;
        id++;
    }
}

int ListaSimple::size() const
{

}

bool ListaSimple::empty() const
{

}

void ListaSimple::insert(const TipoDato &dato, int pos)
{

}

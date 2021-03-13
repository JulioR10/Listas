#include <iostream>
#include <vector>
#include "listasimple.h"

using namespace std;

int main()
{
    /*
    cout << "Hello World!" << endl;
    ListaSimple lista;
    lista.push_back(TipoDato("algo"));
    lista.push_back(TipoDato("algo mas"));

    auto print = [](TipoDato& dato){
        cout << pos << ": " << dato.name << std::endl;
    };
    lista.for_each(print);

    cout << lista.size() << endl;

    cout << "He llegado hasta aqui." << endl;
    */

    ListaSimple films;
    films.push_back(TipoDato{"Citizen Kane", 1941, 5});
    films.push_back(TipoDato{"Into the wild", 2007, 5});
    films.push_back(TipoDato{"Avengers", 2005, 5});
    //Hay que terminar con un Dato vacio para poder mostrar el elemento final.
    films.push_front(TipoDato{"Yoquese", 2500, 5});
    films.push_back(TipoDato{});
    //films.push_front(TipoDato{});
    // ... add more films

    films.sort();
    films.for_each([](TipoDato& dato) {
        std::cout << "Nombre: " << dato.film << "   Year: " << dato.year << "    Estrellas: " << dato.number_stars << std::endl;
    });

    /*
    ListaSimple films;
    films.push_back(TipoDato{"Citizen Kane", 1941, 5});
    films.push_back(TipoDato{"Into the wild", 2007, 5});
    // ... add more films

    // Store the 'positions' of those films
    std::vector<int> positions;
    films.enumerate([](int pos, TipoDato& dato) {
        if (dato.number_stars < 3) {
            positions.push_back(pos);
        }
    });

    // Now remove the films at those positions
    // ATTENTION!!! Why we need to iterate in reverse order?
    for (int i = positions.size(); i>0; i--) {
        int pos = positions.at(i-1);
        films.erase(pos);
    }

    // Print and check
    */
    return 0;
}

/*
void print_list(std::shared_ptr<Element> lista) {
    std::shared_ptr<Element> iterator = lista;
    while (iterator != nullptr) {
        std::cout << iterator->dato.name << std::endl;
        iterator = iterator->next;
    }
}

// Calls 'action' with the data of each element in the list
void for_each(std::shared_ptr<Element> lista, std::function<void (TipoDato&)> action) {
    // Iterate the list as usual
    std::shared_ptr<Element> iterator = lista;
    while (iterator != nullptr) {
        action(iterator->dato); // Call the action
        iterator = iterator->next;
    }
}

// Calls 'action' with the data of each element in the list
void enumerate(std::shared_ptr<Element> lista,
              std::function<void (int, TipoDato&)> action) {
    // Iterate the list as usual
    std::shared_ptr<Element> iterator = lista;
    int idx = 0;
    while (iterator != nullptr) {
        action(idx, iterator->dato); // Call the action
        iterator = iterator->next;
        idx++;
    }
}

//ITERATIVO
int size(std::shared_ptr<Element> lista) {
    int size = 0;
    std::shared_ptr<Element> iterator = lista; // first element
    while (iterator != nullptr) {
        size += 1;
        iterator = iterator->next;
    }
    return size;
}
//RECURSIVO
int size(std::shared_ptr<Element> lista) {
    if (lista == nullptr) {
        return 0;
    }
    return 1 + size(lista->next);
}

bool empty(std::shared_ptr<Element> lista) {
    return (lista == nullptr);
}
//OTRA FORMA
bool empty(std::shared_ptr<Element> lista) {
    return size(lista) == 0;
}

// Returns data from the first element in 'lista'
TipoDato& front(std::shared_ptr<Element> lista) {
    return lista->dato;
}

// Returns data from the last element in 'lista'
TipoDato& back(std::shared_ptr<Element> lista) {
    std::shared_ptr<Element> iterator = lista;
    while (iterator->next != nullptr) {
        iterator = iterator->next;
    }
    return iterator->dato;
}

// Returns the data from 'lista' at position 'pos'
TipoDato& at(std::shared_ptr<Element> lista, int pos) {
    std::shared_ptr<Element> iterator = lista;
    int idx = 0;
    while (iterator != nullptr) {
        if (idx == pos) {
            break;
        }
        iterator = iterator->next;
        idx++;
    }
    return iterator->dato;
}

// Inserts new date at the end
void push_back(std::shared_ptr<Element>& lista,  // Note the reference
               const TipoDato& dato) {
    // Create the element to hold the incoming dato
    std::shared_ptr<Element> elem = std::make_shared<Element>(Element{dato});
    if (empty(lista)) {
        lista = elem;  // Now it is the only element in the list
    }
    else {
        // Traverse the list to the latest element
        std::shared_ptr<Element> iterator = lista;
        while (iterator->next != ) {
            iterator = iterator->next;
        }
        // The new element will become the latest one
        iterator->next = elem;
    }
}

// Inserts element 'elem' as the first element of the list
void push_front(std::shared_ptr<Element>& lista, // Note the reference
                const TipoDato& dato) {
    // Create the element to hold the incoming data
    std::shared_ptr<Element> elem = std::make_shared<Element>(Element{dato});
    if (empty(lista)) {
        lista = elem;  // Now it is the only element in the list
    }
    else {
        elem->next = lista;
        lista = elem;
    }
}

// Inserts 'dato' in the position indicated by 'pos'.
void insert(std::shared_ptr<Element>& lista, // Note the reference
            const TipoDato& dato,
            int pos) {
    // Create the element to hold the incoming data
    std::shared_ptr<Element> elem = std::make_shared<Element>(Element{dato});

    if (pos == 0) {
        // Insertion at the beginning is particular
        push_front(lista, dato);
    }
    else {
        // Search the element before the requested position
        std::shared_ptr<Element> iterator = lista;
        int idx = 0;
        while (idx != pos - 1) {
            iterator = iterator->next;
            idx++;
        }
        elem->next = iterator->next;
        iterator->next = elem;
    }
}

// Removes the last element from the list
void pop_back(std::shared_ptr<Element>& lista) {
    if (lista->next == nullptr) {
        // If the list only has one element
        lista = nullptr;
    }
    else {
        std::shared_ptr<Element> iterator = lista;
        while (iterator->next->next != nullptr) {
            iterator = iterator->next;
        }
        iterator->next = nullptr;
    }
}

// Removes the first element from the list
void pop_front(std::shared_ptr<Element>& lista) {
    lista = lista->next;
}

// Remove all elements from the list
void clear(std::shared_ptr<Element>& lista) {
    lista = nullptr;
}

// Remove element at position 'pos'
void erase(std::shared_ptr<Element>& lista, int pos) {
    if (pos == 0) {
        lista = lista->next;
    }
    else {
        // Search the element before the requested position
        std::shared_ptr<Element> iterator = lista;
        int idx = 0;
        while (idx != pos - 1) {
            iterator = iterator->next;
            idx++;
        }
        iterator->next = iterator->next->next;
    }
}

// Swap two elements inside the list. Assume pos2 > pos1
void swap(std::shared_ptr<Element>& lista,
          int pos1, int pos2) {
    auto& dato1 = at(lista, pos1);  // Note the reference
    auto& dato2 = at(lista, pos2);  // Note the reference
    std::swap(dato1, dato2);
}

// Function to compare two instances of TipoDato
bool equal(const TipoDato& lhs, const TipoDato& rhs) {
    return lhs.name == rhs.name;
}

// Returns the index of the element. If not found, returns -1.
int find(std::shared_ptr<Element> lista, const TipoDato& dato) {
    std::shared_ptr<Element> iterator = lista;
    int found = -1; // If not found, it will return -1
    int idx = 0;
    while (iterator != nullptr) {
        if (equal(iterator->dato, dato)) {  // Use external function to compare
            found = idx;
            break;
        }
        iterator = iterator->next;
        idx++;
    }
    return found;
}

// Returns the slice taken from the input 'lista' between
// indexes 'begin' and 'end'.
std::shared_ptr<Element> slice(std::shared_ptr<Element> lista,
                               int begin,
                               int end) {
    // Move an iterator to the element at position 'begin'
    std::shared_ptr<Element> iterator = lista;
    int idx = 0;
    while (idx != begin) {
        iterator = iterator->next;
        idx++;
    }
    // We will push_back all elements to a new list
    std::shared_ptr<Element> slice = std::make_shared<Element>(iterator->dato);
    while (idx != end) { // until position 'end'
        iterator = iterator->next;
        idx++;
        push_back(slice, iterator->dato);
    }
    return slice;
}

//ORDENACION

// Function to compare two instances of TipoDato
bool less_than(const TipoDato& lhs, const TipoDato& rhs) {
    return lhs.name < rhs.name;
}

//UTILIZA SWAP Y AT
void bubble_sort(std::shared_ptr<Element>& elements);
//UTILIZA SWAP Y AT
void selection_sort(std::shared_ptr<Element>& elements);
//UTILIZA AT Y SLICE Y PUSH_BACK
std::shared_ptr<Element> merge_sort(const std::shared_ptr<Element>& elements);
//UTILIZA SWAP Y AT
void quick_sort(std::shared_ptr<Element>& elements, int left_index, int right_index);

int main() {
    TipoDato despertar{"despertar"};
    TipoDato comer{"comer"};
    TipoDato programar{"programar"};
    TipoDato dormir{"dormir"};

    std::shared_ptr<Element> agenda = std::make_shared<Element>(Element{despertar});
    push_back(agenda, comer);
    push_back(agenda, programar);
    push_back(agenda, comer);
    push_back(agenda, programar);
    push_back(agenda, comer);
    push_back(agenda, dormir);

    print_list(agenda);
}

int main() {
    // Tenemos algunos datos
    TipoDato t1{"nicolás"};
    TipoDato t2{"marina"};
    TipoDato t3{"humberto"};

    // Tenemos elementos que almacenan los datos
    std::shared_ptr<Element> e1 = std::make_shared<Element>(Element{t1});
    std::shared_ptr<Element> e2 = std::make_shared<Element>(Element{t2});
    std::shared_ptr<Element> e3 = std::make_shared<Element>(Element{t3});

    // Los podemos poner en "orden" (uno detrás de otro)
    e1->next = e2;
    e2->next = e3;

    // La lista la representamos por el primer elemento
    std::shared_ptr<Element> lista = e1;
    print_list(lista);
}
*/

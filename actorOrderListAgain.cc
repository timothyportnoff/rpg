#include "Bridges.h"
#include "CircDLelement.h"
#include "class.cc"


using namespace bridges;

// helper function
CircDLelement<Actor> *insertFront(
    CircDLelement<Actor> *tailElement,
    CircDLelement<Actor> *newElement);

int main(int argc, char **argv) {
    Bridges *bridges =  new Bridges(10, "Skeletonman59", "1126298313308");

//change all Actor to Actor.

    bridges->setTitle("Attack Line:");

    // create the linked list elements with
    // your mother
    CircDLelement<Actor> *Actor[] = {
        new CircDLelement<Actor> Actor(get_name(), get_health(), get_level())
            //armor = 25
        new CircDLelement<Actor>(
            Actor(
                "Hero 2: Paladin"
                "Health: 125"
                "Armor: 50"
                "Level: 1"
                )
        new CircDLelement<Actor>(
            Actor(
                "Hero 3"
                "Health: 80"
                "Armor: 10"
                "Level: 1"
                )
        new CircDLelement<Actor>(
            Actor(
                "Monster 1"
                "Health: 80"
                "Armor: 0"
                "Level: 2"
                "Grunt"
                )
        new CircDLelement<Actor>(
            Actor(
                "Monster 2"
                "Health: 200"
                "Armor: 100"
                "Level: 8"
                "Boss"
                )
            )
    };
    CircDLelement<Actor> *head =  nullptr;
    for (int i = 0; i < actorCount; i++) {
        if (i)
            head = insertFront(head, Actor[i]);
        else
            head = Actor[i];
    }

    //  add visual attributes
    CircDLelement<Actor> *current = head;
    Actor si;
    do {
        si = current->getValue();
        current->setLabel(si.getStudentLabel());
        current->getVisualizer()->setColor(si.getFavoriteColor());

        current->getLinkVisualizer(current->getNext())->setColor(si.getDislikeColor());
        current->getLinkVisualizer(current->getNext())->setThickness(si.getStudentCreditHours()*.5);

        current->getLinkVisualizer(current->getPrev())->setColor(si.getDislikeColor());
        current->getLinkVisualizer(current->getPrev())->setThickness(si.getStudentCreditHours()*.5);

        current = current->getNext();
    }  while (current != head);

    // set data structure to point to head
    bridges->setDataStructure(head);
    // visualize the circular list
    bridges->visualize();

    return 0;
}
CircDLelement<Actor> *insertFront(
    CircDLelement<Actor> *tailElement,
    CircDLelement<Actor> *newElement) {

    CircDLelement<Actor> *tailNextElement = tailElement->getNext();

    newElement->setNext(tailNextElement);
    newElement->setPrev(tailElement);

    tailNextElement->setPrev(newElement);
    tailElement->setNext(newElement);

    return tailElement;
}


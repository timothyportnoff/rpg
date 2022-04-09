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

	//TODO:We may need to actually assign the getter values in this main.
    bridges->setTitle("Attack Line:");

    // create the linked list elements with
    // your mother
	int actorCount = 6;
    CircDLelement<shared_ptr<Actor>> cast;
	new CircDLelement<shared_ptr<Actor>> Hero(get_type(), get_name(), get_health(), get_shield(), get_damage(), get_resistance(), get_level(), get_speed());
	new CircDLelement<shared_ptr<Actor>> Hero(get_type(), get_name(), get_health(), get_shield(), get_damage(), get_resistance(), get_level(), get_speed());
	new CircDLelement<shared_ptr<Actor>> Hero(get_type(), get_name(), get_health(), get_shield(), get_damage(), get_resistance(), get_level(), get_speed());
	new CircDLelement<shared_ptr<Actor>> Monster(get_type(), get_name(), get_health(), get_shield(), get_damage(), get_resistance(), get_level(), get_speed());
	new CircDLelement<shared_ptr<Actor>> Monster(get_type(), get_name(), get_health(), get_shield(), get_damage(), get_resistance(), get_level(), get_speed());
	new CircDLelement<shared_ptr<Actor>> Monster(get_type(), get_name(), get_health(), get_shield(), get_damage(), get_resistance(), get_level(), get_speed());

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


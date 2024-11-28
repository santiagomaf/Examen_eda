
void LinkedList::removemin() {
    Node* current = head;
    Node* prev = nullptr;

    Node* min = head;
    Node* prev_min = nullptr;

    while (current != nullptr){
        if (current->getData() < min->getData()){
            min = current;
            prev_min = prev;
        }
        prev = current;
        current = current->getNext();
    }

    if (min == head){
        head = head->getNext();
    } else {
        prev_min->setNext(min->getNext());
    }


    delete min;

}


void ordenamiento(LinkedList* lista){
    Node* start = lista->getHead();
    while (start != nullptr){
        Node* min = start;
        Node* ite = start->getNext();
        while (ite != nullptr){
            if (ite->getData() < min->getData()){
                min = ite;
            }
            ite = ite->getNext();
        }
        if (min != start){
            int temp = start->getData();
            start->setData(min->getData());
            min->setData(temp);
        }
        start = start->getNext();
    }


}





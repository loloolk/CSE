#include "linkedList.c"

int main() {
    LinkedList* list = createLinkedList(1);
    append(list, 2);
    append(list, 3);
    append(list, 4);
    append(list, 5);
    append(list, 6);
    append(list, 7);
    append(list, 8);

    printList(list);

    insertNode(list, 2, 99);
    printList(list);

    deleteNode(list, 2);
    printList(list);

    deleteNode(list, 0);
    printList(list);

    deleteNode(list, 4);
    printList(list);

    return 0;
}

/*
Result:
1->2->3->4->5->6->7->8->NULL
1->2->3->99->4->5->6->7->8->NULL
1->2->99->4->5->6->7->8->NULL
1->99->4->5->6->7->8->NULL
1->99->4->5->7->8->NULL
*/
#include <iostream>

using namespace std;

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

void hapus_genap(node *head, node *tail, int a, int batas) {
    while (a <= batas) {
        node *baru;
        baru = new (node);
        baru->next = NULL;
        baru->prev = NULL;
        baru->data = a;
        if (head->prev == NULL) {
            head->prev = baru;
            tail->next = baru;
        } else {
            tail->next->prev = baru;
            baru->next = tail->next;
            tail->next = baru;
        }
        if (a % 2 != 0) {
            node *cetak;
            cetak = tail->next;
            cout << cetak->data << " ";
            cetak = cetak->next;
        }
        a++;
    }
}

int main() {
    node head, tail;
    head.prev = NULL;
    head.next = NULL;
    tail.next = NULL;
    tail.prev = NULL;
    int batas;
    cout << "Batas inputan = ";
    cin>>batas;
    hapus_genap(&head, &tail, 1, batas);
}


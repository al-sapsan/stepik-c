/**********************************************************************
 * @file script5.cpp
 * @brief OneLinkedList for BOOK struct, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-29
 **********************************************************************/

/*** Core ***/
#include <iostream>
#include <cstring>

/*** Typedefs ***/
typedef struct
{
    char author[50];
    char title[100];
    short year;
} BOOK;

struct Node
{
public:
    BOOK data;
    Node *next;

public:
    Node(const BOOK &data)
    {
        this->data = data;
        this->next = NULL;
    }
};

struct OneLinkedList
{
public:
    Node *head, *tail;

public:
    OneLinkedList()
    {
        this->head = this->tail = NULL;
    }
    ~OneLinkedList()
    {
        while (head != NULL)
            pop_front();
    }
    void pop_front()
    {
        if (head == NULL)
            return;
        if (head == tail)
        {
            delete tail;
            head = tail = NULL;
            return;
        }
        Node *node = head;
        head = node->next;
        delete node;
    }
    void push_back(const BOOK &data)
    {
        Node *node = new Node(data);
        if (head == NULL)
            head = node;
        if (tail != NULL)
            tail->next = node;
        tail = node;
    }
    void push_front(const BOOK &data)
    {
        Node *node = new Node(data);
        node->next = head;
        head = node;
        if (tail == NULL)
            tail = node;
    }
    void pop_back()
    {
        if (tail == NULL)
            return;
        if (head == tail)
        {
            delete tail;
            head = tail = NULL;
            return;
        }
        Node *node = head;
        for (; node->next != tail; node = node->next)
            ;
        node->next = NULL;
        delete tail;
        tail = node;
    }
    Node *getAt(int k)
    {
        if (k < 0)
            return NULL;
        Node *node = head;
        int n = 0;
        while (node && n != k && node->next)
        {
            node = node->next;
            n++;
        }
        return (n == k) ? node : NULL;
    }
    void insert(int k, const BOOK &data)
    {
        Node *left = getAt(k);
        if (left == NULL)
            return;
        Node *right = left->next;
        Node *node = new Node(data);
        left->next = node;
        node->next = right;
        if (right == NULL)
            tail = node;
    }
    void erase(int k)
    {
        if (k < 0)
            return;
        if (k == 0)
        {
            pop_front();
            return;
        }
        Node *left = getAt(k - 1);
        Node *node = left->next;
        if (node == NULL)
            return;
        Node *right = node->next;
        left->next = right;
        if (node == tail)
            tail = left;
        delete node;
    }
};

int main(void)
{
    using namespace std;
    OneLinkedList lib;
    BOOK b1, b2, b3, b4;
    strncpy(b1.author, "Пушкин А.С.", sizeof(b1.author));
    strncpy(b1.title, "Пиковая дама", sizeof(b1.title));
    b1.year = 2007;
    strncpy(b2.author, "Тургенев И.С.", sizeof(b2.author));
    strncpy(b2.title, "Муму", sizeof(b2.title));
    b2.year = 2011;
    strncpy(b3.author, "Толстой А.Н.", sizeof(b3.author));
    strncpy(b3.title, "Аэлита", sizeof(b3.title));
    b3.year = 1995;
    strncpy(b4.author, "Балакирев С.М.", sizeof(b4.author));
    strncpy(b4.title, "Моя жизнь, мои достижения", sizeof(b4.title));
    b4.year = 2045;
    lib.push_back(b1);
    lib.push_back(b2);
    lib.push_back(b3);
    lib.push_back(b4);
    __assertion_tests(lib); // эту строчку не убирать (должна стоять перед return 0)
    return 0;
}

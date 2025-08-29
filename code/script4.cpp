/**********************************************************************
 * @file script4.cpp
 * @brief OneLinkedList: max 10 elements, embedded C++ style
 * @version 1.0 (Embedded C++ style)
 * @date 2025-08-29
 **********************************************************************/

/*** Core ***/
#include <iostream>

/*** Typedefs ***/
typedef double f64_t;

typedef struct Node
{
public:
    f64_t data;
    Node *next;

public:
    Node(f64_t data)
    {
        this->data = data;
        this->next = NULL;
    }
} Node;

typedef struct OneLinkedList
{
public:
    Node *head, *tail;
    int m_count_i32;

public:
    OneLinkedList()
    {
        this->head = this->tail = NULL;
        m_count_i32 = 0;
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
            m_count_i32 = 0;
            return;
        }
        Node *node = head;
        head = node->next;
        delete node;
        m_count_i32--;
    }
    void push_back(f64_t data)
    {
        if (m_count_i32 >= 10)
            return;
        Node *node = new Node(data);
        if (head == NULL)
            head = node;
        if (tail != NULL)
            tail->next = node;
        tail = node;
        m_count_i32++;
    }
    void push_front(f64_t data)
    {
        if (m_count_i32 >= 10)
            return;
        Node *node = new Node(data);
        node->next = head;
        head = node;
        if (tail == NULL)
            tail = node;
        m_count_i32++;
    }
    void pop_back()
    {
        if (tail == NULL)
            return;
        if (head == tail)
        {
            delete tail;
            head = tail = NULL;
            m_count_i32 = 0;
            return;
        }
        Node *node = head;
        for (; node->next != tail; node = node->next)
            ;
        node->next = NULL;
        delete tail;
        tail = node;
        m_count_i32--;
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
    void insert(int k, f64_t data)
    {
        if (m_count_i32 >= 10)
            return;
        Node *left = getAt(k);
        if (left == NULL)
            return;
        Node *right = left->next;
        Node *node = new Node(data);
        left->next = node;
        node->next = right;
        if (right == NULL)
            tail = node;
        m_count_i32++;
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
        m_count_i32--;
    }
} OneLinkedList;

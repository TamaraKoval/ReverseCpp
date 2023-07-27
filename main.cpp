#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    static ListNode* reverseList1(ListNode* head) {
        ListNode *prev, *cur, *next;
        cur = head;
        next = cur->next;
        for (prev = nullptr; next != nullptr; next = next->next) {
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        cur->next = prev;
        return cur;
    }

    static ListNode* reverseList2(ListNode* head) {
        ListNode *tail, *next;
        if (head == nullptr || head->next == nullptr){
            return head;
        } else {
            next = head->next;
            tail = reverseList2(next);
            next->next=head;
            head->next = nullptr;
            return tail;
        }
    }
};

// функции, написанные для тестов (тело функций представлены после main)
// создание списка заданного размера
ListNode* createListForTest(int size);
// выведение списка на экран
void printList(ListNode *head);
// освобождение выделенной ранее динамической памяти
void deleteList(ListNode *head);

int main() {
    int size = 10;

    // генерируем список
    ListNode *list = createListForTest(size);
    printList(list);

    // развовачиваем список итеративно
    list = Solution::reverseList1(list);
    printList(list);

    // разворачиваем список в исходное состояние
    list = Solution::reverseList1(list);
    printList(list);

    // разворачиваем список рекурсивно
    list = Solution::reverseList2(list);
    printList(list);

    // возвращаем список в исходное состояние
    list = Solution::reverseList2(list);
    printList(list);

    deleteList(list);

    return 0;
}

ListNode* createListForTest(int size) {
    int i = 1;
    ListNode *head, *cur, *temp;
    head = cur = new ListNode(i);
    i++;
    for (; i <= size; i++) {
        temp = new ListNode(i);
        cur->next = temp;
        cur = cur->next;
    }
    return head;
}

void printList(ListNode *head) {
    ListNode *p = head;
    while (p) {
        cout << p->val << "->";
        p = p->next;
    }
    cout << "NULL" << endl;
}

void deleteList(ListNode *head) {
    while (head) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
}
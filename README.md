

## В программе реализованы: ##

Два статических метода класса Solution для обращения связанного списка:

* ``` static ListNode* reverseList1(ListNode* head)``` - итеративный вариант
* ``` static ListNode* reverseList2(ListNode* head)``` - рекурсивный вариант

Также в классе Main() написаны три вспомогательные функции:
* ```ListNode* createListForTest(int size)``` - создание списка заданного размера
* ```void printList(ListNode *head)``` - выведение списка на экран
* ```void deleteList(ListNode *head)``` - освобождение выделенной ранее динамической памяти

Функции протестированы на основе списка из 10-ти значений
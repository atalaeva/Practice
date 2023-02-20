/*Реализовать неплоский класс  List - список целых чисел, звенья объектов которого
хранятся в динамической памяти. В открытой области класса должны быть определены с
ледующие методы:
 - операция '+' (объединение присоединение второго списка к первому),
- add (int) - добавление заданного элемента в конец списка,
- del (int) - удаление первого вхождения заданного элемента из списка
- is_empty() - проверка на пустой список
Не забудьте перегрузить конструктор копирования и операцию присваивания!
Приветствуется перегрузка операции ->
*/
#include <iostream>
using namespace std;
class list
{
    struct Node {
        int value;
        Node *next=NULL;
    };
    Node* head;
public:

    list()
    {
        head = NULL;
    }
    list(const list &tmp)
    {
        head = NULL;
        *this = tmp;
    }
    ~list()
    {
        delete head;
    }
    list& operator= (const list& tmp)
    {
        delete head;
        head = NULL;
        head = new Node;
        head->value = tmp.head->value;
        Node* cur = head;
        Node* cur2 = tmp.head->next;
        while(cur2!= NULL)
        {
            cur->next =  new Node;
            cur->next->value = cur2->value;
            cur = cur->next;
            cur2 = cur2->next;
        }
        return *this;
    }

    void add(int elem)
    {
        if(head == NULL)
        {
            head = new Node;
            head->value = elem;
        }
        else
        {
            Node* cur = head;
            while(cur->next!=NULL){
                cur = cur->next;
            }
            cur->next = new Node;
            cur->next->value = elem;
        }
    }

    void print_all(){
        Node* cur = head;
        while(cur!= NULL){
            cout << cur->value;
            cur = cur->next;
        }
    }

    void del(int elem)
    {
        if(head == NULL)
            return;
        if(head->value == elem)
        {
            Node* tmp = head;
            head = head->next;
            tmp->next = NULL;
            delete tmp;
            return;
        }
        Node* cur = head;
        while(cur->next!=NULL && cur->next->value != elem)
            cur = cur->next;
        if (cur->next== NULL)
            return;
        Node * tmp = cur->next;
        cur->next = tmp->next;
        tmp->next = NULL;
        delete tmp;
    }
    bool is_empty()
    {
        if(head==NULL)
            return true;
        return false;
    }

    list operator+(const list  &lst2 ) const
    {
        list res(*this);
        Node *cur = res.head;
        while( cur->next!= NULL)
            cur = cur->next;
        Node * cur2 = lst2.head;
        while(cur2!=NULL)
        {
            cur->next = new Node;
            cur->next->value = cur2->value;
            cur=cur->next;
            cur2=cur2->next;
        }
        return res;
    }
};

int main()
{
   /* cout << "Check add\n";
    list list1;
    list1.add(1);
    list1.add(2);
    list1.add(3);
    list1.print_all();
    cout << "\n";

    cout << "Check add\n";
    list list2;
    list2.add(4);
    list2.add(5);
    list2.add(6);
    list2.print_all();
    cout << "\n";

    cout << "Check = and +\n";
    list list3;
    list3 = list1+list2;
    list3.print_all();
    cout << "\n";

    cout << "Check copy construct\n";
    list list4(list3);
    list4.print_all();
    cout << "\n";

    cout << "Check delete\n";
    list4.del(2);
    list4.print_all();
    cout << "\n";
    list4.del(10);
    list4.print_all();
    cout << "\n"; */


    return 0;
}

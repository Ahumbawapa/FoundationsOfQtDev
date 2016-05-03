//QStack - Last in, First Out
//QQueue - First in, first Out
#include <QStack>
#include <QtDebug>
#include <QQueue>

int main3(int argc, char **argv)
{
    QStack<QString> stack;

    stack.push("First");          // add new items with push
    stack.push("Second");
    stack.push("Third");

    QString result;
    while(!stack.isEmpty())
        result += stack.pop(); //remove current item with pop

    qDebug() << result;

    QQueue<QString> queue;
    queue.enqueue("first"); //add new items with enqueue
    queue.enqueue("second");
    queue.enqueue("third");

    while(!queue.isEmpty())
        qDebug() << queue.dequeue();//pull items out with dequeue

    return 0;
}

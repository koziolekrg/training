#include <QCoreApplication>
#include <iostream>
#include <QThread>
#include <memory>
#include "booksstorage.h"
#include "userthread.h"
#include <QWaitCondition>

int main()
{
    QWaitCondition mainCondition;

    BooksStorage * storageThread = new BooksStorage(&mainCondition);

    storageThread->addBookToStorage("Polski", "Pawel");  // 0
    storageThread->addBookToStorage("Angielski", "Mati"); //1
    storageThread->addBookToStorage("Matematyka", "Basia");  //2
    storageThread->addBookToStorage("Przyroda", "Tomasz"); //3
    storageThread->addBookToStorage("Niemiecki", "Ala"); //4
    storageThread->addBookToStorage("Historia", "Maria");
    storageThread->addBookToStorage("Informatyka", "Henio");
    storageThread->addBookToStorage("WF", "Maciek");
    storageThread->addBookToStorage("Fizyka", "Ania");

    UserThread *user_1 = new UserThread(storageThread);
    user_1->setObjectName("1");
    user_1->start();

    UserThread *user_2 = new UserThread(storageThread);
    user_2->setObjectName("2");
    user_2->start();

    UserThread *user_3 = new UserThread(storageThread);
    user_3->setObjectName("3");
    user_3->start();

    UserThread *user_4 = new UserThread(storageThread);
    user_4->setObjectName("4");
    user_4->start();

    UserThread *user_5 = new UserThread(storageThread);
    user_5->setObjectName("5");
    user_5->start();


    user_1->wait();
    user_2->wait();
    user_3->wait();
    user_4->wait();
    user_5->wait();

    return 0;
}

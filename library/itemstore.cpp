#include "itemstore.h"

Itemstore::Itemstore()
{
    id =0;
}

Itemstore::~Itemstore()
{
    for(auto item : bookList)
    {
        delete item;
    }
}

void Itemstore::addBook(std::string a_title, int a_ISBN, std::string a_authorName, std::string a_authorSurname, bool a_status)
{
    id++;
    bookList.push_back(new Book(id ,a_title,a_ISBN,a_authorName,a_authorSurname, a_status));
}

void Itemstore::addMagazine(std::string a_title, int a_ISBN, std::string a_publisher, bool a_status)
{
    bookList.push_back(new Magazine(id,a_title,a_ISBN, a_publisher, a_status));
    id++;
}

void Itemstore::showItem(int a_id)
{
    bookList[a_id]->show();
}

void Itemstore::showAll()
{
    for(auto item : bookList)
        item->show();
}

void Itemstore::showItemTitle(int a_id)
{
    bookList[a_id]->showTitle();
}

void Itemstore::changeStatus(int a_id)
{
    bookList[a_id]->change();
}

bool Itemstore::getStatus(int a_id)
{
    return bookList[a_id]->getStatus();
}

void Itemstore::saveItemstore()
{
    try{
        books.open("books.txt",std::ios::out);
        if(!books.is_open())
            throw Exception();
    }catch(Exception& e)
    {
        std::cout<<e.what();
    }
    for(auto item : bookList)
        books<<item->saveItem();

    books.close();
}

int Itemstore::getCount()
{
    return id;
}

void Itemstore::sortViaTitle()
{
    for(int i=0;i<bookList.size();i++){
         for(int j=0;j<bookList.size()-1;j++){
             std::string title_1 = bookList[j]->getTitle();
             std::string title_2 = bookList[j+1]->getTitle();
             if(title_2.compare(title_1)<0){
                std::swap(bookList[j+1],bookList[j]);
            }
        }
    }
}

void Itemstore::sortViaId()
{
    for(int i=0;i<bookList.size();i++){
         for(int j=0;j<bookList.size()-1;j++){
             int id_1 = bookList[j]->getID();
             int id_2 = bookList[j+1]->getID();
             if(id_1<id_2){
                std::swap(bookList[j+1],bookList[j]);
            }
        }
    }
}



#ifndef CLASSTHATUSESDB_H
#define CLASSTHATUSESDB_H
//делаем эти директивы, чтобы повторно не включить 
//там в конце допишем директиву ендиф, чтобы заработало

#include "DBConnection.h"
//подключаем нужный файл этой директивой

//моя версия класса для бд
class ClassThatUsesDB 
{
public:

    ClassThatUsesDB(DBConnection* db) : dbConnection(db)
    {}//тут конструктор примает указатель, который присваивается Дб коннекшин


    //функция открытия у обьекта 
    bool openConnection()
    { return dbConnection->open();}//если можно извлечь из указателя метод опен, то соединение открыто


    //метод соединения
    void useConnection()
    {
        if (dbConnection->open()  )//если из указатедя извлекается функция опен,то
        {
            // то в строку резулт пишем все данные из таблицы
            std::string result = dbConnection->execQuery("SELECT * FROM table");
        
            //закрываем соединение
            dbConnection->close();
        }
    }

    //метод закрытия. Из указателя извлекаем метот клоуз
    void closeConnection() 
    {dbConnection->close();}

private:
    DBConnection* dbConnection; //указатель типа данных бдКоннекшин
};

#endif // CLASSTHATUSESDB_H
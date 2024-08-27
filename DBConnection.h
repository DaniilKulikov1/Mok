#ifndef DBCONNECTION_H
#define DBCONNECTION_H
//эти строчки значат тоже самое, что и в других файлах

#include <string>
//подключаем строки

//начинаем создавать виртуальный, он же абстрактный класс бд коннекшин
class DBConnection 
{
public:
    virtual ~DBConnection() = default;//делаем виртуальный деструктор
    virtual bool open() = 0;//эта виртуальная функция, её распишем как открытие соединения
    virtual void close() = 0; //эта виртуальная функция, потом в наследовании сделаем функцию закртия соединения
    virtual std::string execQuery(const std::string& query) = 0;//виртуальная функция для SQL напишем в классе-наследнике
};

#endif // DBCONNECTION_H
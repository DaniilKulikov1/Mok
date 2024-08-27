#ifndef MOCKDBCONNECTION_H
#define MOCKDBCONNECTION_H
//делаем это для предотвращения множественного включения

#include <gmock/gmock.h>//подключаем библиотеку гугл мокка
#include "DBConnection.h"//подключаем бд коннекшин

//создаём класс унаследованный от бд коннекшин
class MockDBConnection : public DBConnection
{
public:
    MOCK_METHOD(bool, open, (), (override));
   // создаем мок - метод open.Он имитирует метод open базового класса, который возвращает значение типа bool и не принимает параметров.
    //оверрайд - значит, что в виртуальноме методе базового класса был этот метод без определения 


    MOCK_METHOD(void, close, (), (override));
    //тут как и выше, только для метода клоуз

    MOCK_METHOD(std::string, execQuery, (const std::string& query), (override));
    /*Этот строка создает мок-метод execQuery, который соответствует методу базового класса, возвращающему std::string и принимающему одну строку в качестве параметра. Он также переопределяет виртуальный метод базового класса.*/
};

#endif // MOCKDBCONNECTION_H
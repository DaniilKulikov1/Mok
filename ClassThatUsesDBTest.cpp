#include <gtest/gtest.h>//подключаем библиотеку гугл теста
#include <gmock/gmock.h>//Подключаем библиотеку моков
#include "ClassThatUsesDB.h"//подключаем файл для тестируемого класса
#include "MockDBConnection.h"//подключаем файл для мока

using ::testing::Return;//пространство им1н для доступа к ретон из гугл мок


//тест для открытия соединения
TEST(ClassThatUsesDBTest, OpenConnection)
{
    MockDBConnection mockDb; //обьект мок 
    ClassThatUsesDB classThatUsesDB(&mockDb); //обьект тестируемого класса

    //тут ожидание, один раз вызывается опен мока и возвращает тру
    EXPECT_CALL(mockDb, open())
        .Times(1)
        .WillOnce(Return(true));

    EXPECT_TRUE(classThatUsesDB.openConnection());
    //проверяем, что верналась тру
}

//тест использования соединения
TEST(ClassThatUsesDBTest, UseConnection) 
{
    MockDBConnection mockDb;// делаем мок-обьект
    ClassThatUsesDB classThatUsesDB(&mockDb); // Создаем экземпляр тестируемого класса


    // Устанавливаем ожидание для метода open()
    EXPECT_CALL(mockDb, open())
        .Times(1)
        .WillOnce(Return(true));

    // Устанавливаем ожидание для метода execQuery с конкретным аргументом и возвращаемым значением
    EXPECT_CALL(mockDb, execQuery("SELECT * FROM table"))
        .Times(1)
        .WillOnce(Return("query result"));

    // Устанавливаем ожидание для метода close()
    EXPECT_CALL(mockDb, close())
        .Times(1);

    classThatUsesDB.useConnection();// Вызываем метод useConnection() класса, для активации ожидания

}

//тест для закрытия соединения
TEST(ClassThatUsesDBTest, CloseConnection) 
{
    MockDBConnection mockDb;// Создаем мок-объект
    ClassThatUsesDB classThatUsesDB(&mockDb);// Создаем экземпляр тестируемого класса

    // Устанавливаем ожидание для метода close()
    EXPECT_CALL(mockDb, close())
        .Times(1);

    classThatUsesDB.closeConnection();// Вызываем метод closeConnection(), который должен вызвать close()
}
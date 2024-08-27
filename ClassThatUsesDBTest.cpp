#include <gtest/gtest.h>//���������� ���������� ���� �����
#include <gmock/gmock.h>//���������� ���������� �����
#include "ClassThatUsesDB.h"//���������� ���� ��� ������������ ������
#include "MockDBConnection.h"//���������� ���� ��� ����

using ::testing::Return;//������������ ��1� ��� ������� � ����� �� ���� ���


//���� ��� �������� ����������
TEST(ClassThatUsesDBTest, OpenConnection)
{
    MockDBConnection mockDb; //������ ��� 
    ClassThatUsesDB classThatUsesDB(&mockDb); //������ ������������ ������

    //��� ��������, ���� ��� ���������� ���� ���� � ���������� ���
    EXPECT_CALL(mockDb, open())
        .Times(1)
        .WillOnce(Return(true));

    EXPECT_TRUE(classThatUsesDB.openConnection());
    //���������, ��� ��������� ���
}

//���� ������������� ����������
TEST(ClassThatUsesDBTest, UseConnection) 
{
    MockDBConnection mockDb;// ������ ���-������
    ClassThatUsesDB classThatUsesDB(&mockDb); // ������� ��������� ������������ ������


    // ������������� �������� ��� ������ open()
    EXPECT_CALL(mockDb, open())
        .Times(1)
        .WillOnce(Return(true));

    // ������������� �������� ��� ������ execQuery � ���������� ���������� � ������������ ���������
    EXPECT_CALL(mockDb, execQuery("SELECT * FROM table"))
        .Times(1)
        .WillOnce(Return("query result"));

    // ������������� �������� ��� ������ close()
    EXPECT_CALL(mockDb, close())
        .Times(1);

    classThatUsesDB.useConnection();// �������� ����� useConnection() ������, ��� ��������� ��������

}

//���� ��� �������� ����������
TEST(ClassThatUsesDBTest, CloseConnection) 
{
    MockDBConnection mockDb;// ������� ���-������
    ClassThatUsesDB classThatUsesDB(&mockDb);// ������� ��������� ������������ ������

    // ������������� �������� ��� ������ close()
    EXPECT_CALL(mockDb, close())
        .Times(1);

    classThatUsesDB.closeConnection();// �������� ����� closeConnection(), ������� ������ ������� close()
}
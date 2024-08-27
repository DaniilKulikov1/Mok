#ifndef MOCKDBCONNECTION_H
#define MOCKDBCONNECTION_H
//������ ��� ��� �������������� �������������� ���������

#include <gmock/gmock.h>//���������� ���������� ���� �����
#include "DBConnection.h"//���������� �� ���������

//������ ����� �������������� �� �� ���������
class MockDBConnection : public DBConnection
{
public:
    MOCK_METHOD(bool, open, (), (override));
   // ������� ��� - ����� open.�� ��������� ����� open �������� ������, ������� ���������� �������� ���� bool � �� ��������� ����������.
    //�������� - ������, ��� � ������������ ������ �������� ������ ��� ���� ����� ��� ����������� 


    MOCK_METHOD(void, close, (), (override));
    //��� ��� � ����, ������ ��� ������ �����

    MOCK_METHOD(std::string, execQuery, (const std::string& query), (override));
    /*���� ������ ������� ���-����� execQuery, ������� ������������� ������ �������� ������, ������������� std::string � ������������ ���� ������ � �������� ���������. �� ����� �������������� ����������� ����� �������� ������.*/
};

#endif // MOCKDBCONNECTION_H
#pragma once
class MyString
{
    char* m_pStr;	//������-���� ������
public:
	MyString(const char* str);
	MyString();
	MyString(MyString& other);
	MyString(MyString&& temp);
	~MyString();

	const char* GetString() const;

	void SetNewString(const char* str);
};

MyString ConcatString(const char* str1,...);
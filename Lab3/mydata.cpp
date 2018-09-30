#include "mydata.h"

const char* SexAss[] = { "UNDEF", "MALE", "FMALE" };

MyData::MyData() : m_sex(UNDEF), m_age(0), m_job("NO_JOB"), m_salary(0) {}

MyData::MyData(Sex s, size_t age, const char* job, float sal) : m_sex(s), m_age(age), m_job(job), m_salary(sal) {}

ostream& operator<<(ostream& os, const MyData& other)
{
	
	os << SexAss[other.m_sex] << " " << other.m_age << " " << other.m_job << " " << other.m_salary; 
	
	return os;
}

MyData::MyData(const MyData& other):m_job(other.m_job)
{
	m_sex = other.m_sex;
	m_age = other.m_age;
	m_salary = other.m_salary;
}
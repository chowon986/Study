﻿// 6-1 상속

#include <iostream>
using namespace std;

class Employee
{
	std::string name;
	int age;

	std::string position;
	int rank;

public:
	Employee(std::string name, int age, std::string position, int rank)
		: name(name), age(age), position(position), rank(rank) {}

	// 복사 생성자
	Employee(const Employee& employee) {
		name = employee.name;
		age = employee.age;
		position = employee.position;
		rank = employee.rank;
	}

	// 디폴트 생성자
	Employee() {}

	void print_info() {
		std::cout << name << " (" << position << " , " << age << ") ==> "
			<< calculate_pay() << "만원" << std::endl;
	}
	int calculate_pay() { return 200 + rank * 50; }
};

class Manager
{
	std::string name;
	int age;

	std::string position;
	int rank;
	int year_of_service;

public:
	Manager(std::string name, int age, std::string position, int rank, int year_of_service)
		: year_of_service(year_of_service),
		name(name),
		age(age),
		position(position),
		rank(rank) {}

	// 복사 생성자
	Manager(const Manager& manager) {
		name = manager.name;
		age = manager.age;
		position = manager.position;
		rank = manager.rank;
		year_of_service = manager.year_of_service;
	}

	// 디폴트 생성자
	Manager() {}

	int calculate_pay() { return 200 + rank * 50 + 5 * year_of_service; }
	void print_info() {
		std::cout << name << " (" << position << " , " << age << ", " << year_of_service
			<< "년차) ==> " << calculate_pay() << "만원" << std::endl;
	}
};

class EmployeeList
{
	int alloc_employee;

	int current_employee;
	int current_manager;

	Employee** employee_list;
	Manager** manager_list;

public:
	EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) 
	{
		employee_list = new Employee * [alloc_employee];
		manager_list = new Manager * [alloc_employee];

		current_employee = 0;
		current_manager = 0;
	}

	void add_employee(Employee* employee) 
	{
		// 사실 current_employee 보다 alloc_employee 가 더
		// 많아지는 경우 반드시 재할당을 해야 하지만, 여기서는
		// 최대한 단순하게 생각해서 alloc_employee 는
		// 언제나 current_employee 보다 크다고 생각한다.
		// (즉 할당된 크기는 현재 총 직원수 보다 많음)
		employee_list[current_employee] = employee;
		current_employee++;
	}

	void add_manager(Manager* manager) 
	{
		manager_list[current_manager] = manager;
		current_manager++;
	}

	int current_employee_num() { return current_employee + current_manager; }

	void print_employee_info() 
	{
		int total_pay = 0;
		for (int i = 0; i < current_employee; i++) 
		{
			employee_list[i]->print_info();
			total_pay += employee_list[i]->calculate_pay();
		}
		for (int i = 0; i < current_manager; i++) 
		{
			manager_list[i]->print_info();
			total_pay += manager_list[i]->calculate_pay();
		}
		std::cout << "총 비용 : " << total_pay << "만원 " << std::endl;
	}

	~EmployeeList() 
	{
		for (int i = 0; i < current_employee; i++) 
		{
			delete employee_list[i];
		}
		for (int i = 0; i < current_manager; i++) 
		{
			delete manager_list[i];
		}
		delete[] employee_list;
		delete[] manager_list;
	}
};

int main()
{
	// 직원 리스트 하나 생성
	EmployeeList emp_list(10);

	// 직원 추가
	emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
	emp_list.add_employee(new Employee("하하", 34, "평사원", 1));
	emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
	emp_list.add_employee(new Employee("길", 36, "인턴", -2));

	// 매니저 추가
	emp_list.add_manager(new Manager("유재석", 41, "부장", 7, 12));
	emp_list.add_manager(new Manager("정준하", 43, "과장", 4, 15));
	emp_list.add_manager(new Manager("박명수", 43, "차장", 5, 13));


	// 출력
	emp_list.print_employee_info();
	return 0;
}

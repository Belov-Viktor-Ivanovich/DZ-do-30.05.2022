

#include <iostream>
#include<string>
#include <windows.h>
#include <fstream>
#include"BookTel.cpp"


int main()
{
	BookTel k1("Belov", "Viktor","Ivanovich", 2230801, 2230801, "89999999999", "Student");
	BookTel k2("Belova", "Marina", "Alexsandrovna", 7777777, 7777777, "89995555555", "Teacher");
	BookTel k3("Santos", "Karl", "Stepanovich", 888888, 4444444, "87777777777", "Student");
	Book book;
	book.addContact(k1);
	//book.print();
	book.addContact(k2);
	book.addContact(k3);
	book.delContact(1);
	//cout << k1.getName();
	book.print();
	(book.poiskContakt("Belov", "Viktor", "Ivanovich")>0)?cout<<"yes":cout<<"no";
	cout << endl;
	string patch={ "C:\\Users\\Марина\\Documents\\Белов C++\\Домашка плюсы\\До 30.05.2022\\Patch\\abon.txt" };
	book.recBook(patch);
	book.printPatch(patch);
}


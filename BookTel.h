#pragma once



class BookTel
{
	char* surname = new char[0];
	char* name = new char[0];
	char* patronymic = new char[0];
	int HouseTel;
	int WorkerTel;
	string MobileTel;
	string Info;
	int sizeS = 0;
	int sizeN = 0;
	int sizeP = 0;
public:

	BookTel(const char surname2[], const char name2[], const char patronymic2[], int HouseTel, int WorkerTel, string MobileTel, string Info)
	{
		this->HouseTel = HouseTel;
		this->WorkerTel = WorkerTel;
		this->MobileTel = MobileTel;
		this->Info = Info;
		delete[]surname;
		for (int i = 0; surname2[i] != '\0'; i++)
		{
			sizeS++;

		}
		surname = new char[sizeS + 1];
		for (int i = 0; surname2[i] != '\0'; i++)
		{
			surname[i] = surname2[i];
		}
		surname[sizeS] = '\0';


		for (int i = 0; name2[i] != '\0'; i++)
		{
			sizeN++;
		}
		name = new char[sizeN + 1];
		for (int i = 0; name2[i] != '\0'; i++)
		{
			name[i] = name2[i];
		}
		name[sizeN] = '\0';


		for (int i = 0; patronymic2[i] != '\0'; i++)
		{
			sizeP++;
		}
		patronymic = new char[sizeP + 1];
		for (int i = 0; patronymic2[i] != '\0'; i++)
		{
			patronymic[i] = patronymic2[i];
		}
		patronymic[sizeP] = '\0';

	}
	BookTel()
	{

	}
	BookTel(const BookTel& st2)
	{
		this->HouseTel = HouseTel;
		this->WorkerTel = WorkerTel;
		this->MobileTel = MobileTel;
		this->Info = Info;
		delete[]surname;
		surname = new char[sizeS];
		for (int i = 0;i<sizeS; i++)
		{
			surname[i] = st2.surname[i];
		}
		name = new char[sizeN];
		for (int i = 0; i < sizeN; i++) {
			name[i] = st2.name[i];
		}
		patronymic = new char[sizeP];
		for (int i = 0; i < sizeP; i++) {
			patronymic[i] = st2.patronymic[i];
		}
	}
	void operator =(const BookTel& st2) {
		this->sizeS = st2.sizeS;
		this->sizeN = st2.sizeN;
		this->sizeP = st2.sizeP;
		this->HouseTel = st2.HouseTel;
		this->WorkerTel = st2.WorkerTel;
		this->MobileTel = st2.MobileTel;
		this->Info = st2.Info;
		delete[]surname;
		surname = new char[sizeS+1];
		for (int i = 0; i < sizeS; i++) {
			surname[i] = st2.surname[i];
		}
		surname[sizeS] = '\0';

		delete[]name;
		name = new char[sizeN+1];
		for (int i = 0; i < sizeN; i++) {
			name[i] = st2.name[i];
		}
		name[sizeN] = '\0';

		delete[]patronymic;
		patronymic = new char[sizeP+1];
		for (int i = 0; i < sizeP; i++) {
			patronymic[i] = st2.patronymic[i];
		}
		patronymic[sizeP] = '\0';
	}


	

	string getSurname() {
		return surname;
	}
	string getName() {
		return name;
	}
	
	string getPatronymic() {
		return patronymic;
	}

	void rec(string patch)
	{
		ofstream out{ patch,ios::app };
		
			out << surname << " " << name << " " << patronymic << endl;
			out << "HouseTel :\t" << HouseTel << endl;
			out << "WorkerTel :\t" << WorkerTel << endl;
			out << "MobileTel :\t" << MobileTel << endl;
			out << "Info :\t" << Info << endl << endl;
			out.close();
	}
	
	

	~BookTel()
	{
		delete[]surname;
		delete[]name;
		delete[]patronymic;
	}
};
class Book {
	BookTel* bok;
	int size = 0;
public:
	/*void operator =(Book& st2) {
		this->size = st2.size;
		delete[]bok;
		bok = new BookTel[st2.size];
		for (int i = 0; i < st2.size; i++) {
			bok[i] = st2.bok[i];
		}
	}*/
	void addContact(BookTel& contact)
	{
		BookTel* buf = new BookTel[size + 1];
		for (int i = 0; i < size; i++)
		{
			buf[i] = bok[i];
		}
		buf[size] = contact;
		delete[]bok;
		bok = buf;
		size++;
	}
	void delContact(int n)
	{
		if (n >= 0 && n < size) {
			BookTel* buf = new BookTel[size - 1];
			for (int i = 0; i < n; i++)
			{
				buf[i] = bok[i];
			}
			for (int i = n + 1; i < size; i++)
			{
				buf[i-1] = bok[i];
			}
			delete[]bok;
			bok = buf;
			size--;
		}
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << bok[i].getName() << " " << bok[i].getSurname() << " " << bok[i].getPatronymic()<<endl;
		}
	}
	bool poiskContakt(string surname2,string name2,string patronymic2)
	{
		string strSurname;
		string strName;
		string strPatronymic;
		
		bool flag = false;
		for (int i = 0; i < size; i++)
		{
			strSurname = bok[i].getSurname();
			strName = bok[i].getName();
			strPatronymic = bok[i].getPatronymic();

			if (surname2 == strSurname && name2 == strName && patronymic2 == strPatronymic )
			{
				flag = true;
				return flag;
			}
		}
		return flag;
	}

	void recBook(string patch)
	{
		for (int i = 0; i < size; i++)
		{
			bok[i].rec(patch);
		}
	}
	void printPatch(string patch)
	{
		string str;
		ifstream in{ patch };
		if (in.is_open())
		{
			while (getline(in, str))
			{
				cout << str << endl;
			}
		}
		else cout << "error";
		in.close();
	}
	

	~Book()
	{
		delete[]bok;
	}
};


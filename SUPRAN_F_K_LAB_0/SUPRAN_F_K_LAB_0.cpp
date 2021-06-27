#include <iostream>
#include <string>

class Harbinger
{
private:
	std::string h_name;
	int h_age;
	std::string catchPhrase;
public:
	Harbinger(std::string name = "", int age = 0, std::string catchPhrase = "")
		: h_name(name), h_age(age), catchPhrase(catchPhrase){}

	std::string getName() const { return h_name; }
	int getAge() const { return h_age; }
	std::string getCatchPhrase() const { return catchPhrase; }
	void setName(std::string h_name) { this->h_name = h_name; }
	void setAge(int h_age) { this->h_age = h_age; }
	void setCatchPhrase(std::string catchPhrase) { this->catchPhrase = catchPhrase; }
};
class Prophet : public Harbinger
{
private:
	std::string* magnumOpus;
	std::string ph_name;
	int ph_age;
	std::string ph_call;
public:
	Prophet(std::string mO[3] = NULL,
			std::string name = "",
			int age = 0,
			std::string call = "") : Harbinger(), ph_name(name), ph_age(age), ph_call(call)
	{
		if (mO)
			setMagnumOpus(mO);
		else
		{
			magnumOpus = new std::string[3];
			std::fill_n(magnumOpus, 3, "");
		}
			
	}
	std::string* getMagnumOpus() { return magnumOpus;}
	std::string getPhName() const { return ph_name; }
	int getPhAge() const { return ph_age; }
	std::string getPhCall() const { return ph_call; }

	void setMagnumOpus(std::string magnumOpus[3])
	{
		for (size_t i = 0; i < 3; i++)
		{
			std::string temp = magnumOpus[i].substr(0, 25); // Ограничиваем строку на 25 символов
			if (temp.length() > ph_call.length()) // Если номая строка длиннее ph_call
				setPhCall(temp);
			this->magnumOpus[i] = temp;
		}
			
	}
	void setPhName(std::string ph_name) { this->ph_name = ph_name; }
	void setPhAge(int ph_age) { this->ph_age = ph_age; }
	void setPhCall(std::string ph_call) { this->ph_call = ph_call; }
};
class DeusEx: public Prophet
{
private:
	std::string gd_name;
	int gd_year;
public:
	DeusEx(std::string name = "", int year = 0)
		: Prophet(), gd_name(name), gd_year(year) {}
	std::string getGdName() const { return gd_name; }
	int getGdYear() const { return gd_year; }

	void setGdName(std::string gd_name) { this->gd_name = gd_name; }
	void setGdYear(int gd_year) { this->gd_year = gd_year; }
	void show()
	{
		std::cout << ((Harbinger)*this).getName() << " в возрасте " << ((Harbinger)*this).getAge() 
			<< " говорил, что " << ((Harbinger)*this).getCatchPhrase() << std::endl;

		std::string mainProphecy = ((Prophet)*this).getPhCall();
		std::string* magnumOpus = ((Prophet)*this).getMagnumOpus();
		std::string prophecy1, prophecy2;
		for (size_t i = 0; i < 3; i++) // Поиск пророчества, которое не совпадает с главным пророчеством
		{
			if (magnumOpus[i] != mainProphecy)
			{
				prophecy1 = magnumOpus[i];
				break;
			}
		}
		for (size_t i = 0; i < 3; i++) // Поиск пророчества, которое не совпадает с главным пророчеством и первым пророчеством
		{
			if (magnumOpus[i] != mainProphecy && magnumOpus[i] != prophecy1)
			{
				prophecy2 = magnumOpus[i];
				break;
			}
		}
		std::cout << "Первое пророчество: " << prophecy1 << std::endl;
		std::cout << "Второе пророчество: " << prophecy2 << std::endl;
		std::cout << "Главное пророчество: " << mainProphecy << std::endl;
		std::cout << "Так говорил " << ((Prophet)*this).getPhName() << " в возрасте " << ((Prophet)*this).getPhAge() << std::endl;
		std::cout << "В год " << gd_year << " пришел " << gd_name << ", которого предрекали " << ((Harbinger)*this).getName() 
			<< " и " << ((Prophet)*this).getPhName() << std::endl;
	}
};
class Believer: public DeusEx
{
private:
	std::string bv_name;
	int bv_age;
public:
	Believer(std::string bv_name, int bv_age)
	{
		this->bv_name = bv_name;
		this->bv_age = bv_age;
	}
	std::string getBvName() const { return bv_name; }
	int getBvAge() const { return bv_age; }

	void setBvName(std::string bv_name) { this->bv_name = bv_name; }
	void setBvAge(int bv_age) { this->bv_age = bv_age; }
	void show()
	{
		std::cout << "Верующий " << bv_name << " молится " << ((DeusEx)*this).getGdName() << " именем " 
			<< ((Prophet)*this).getPhName() << ". C " << ((DeusEx)*this).getGdYear() << " и по сей день.";
	}
};
int main()
{
	setlocale(LC_ALL, "ru");
	// Harbinger test
	std::cout << "======================\nHarbinger test\n";
	Harbinger h;
	std::cout << h.getName() << std::endl; // ""
	h.setName("xd");
	std::cout << h.getName() << std::endl; // xd

	// Prophet test
	std::cout << "======================\nProphet test\n";
	Prophet p;
	std::cout << p.getPhCall() << std::endl; // ""
	std::string magnumOpus[3] = { "123", "1234", "12" };
	p.setMagnumOpus(magnumOpus);
	std::cout << p.getPhCall() << std::endl; // 1234
	magnumOpus[2] = "11111111";
	p.setMagnumOpus(magnumOpus);
	std::cout << p.getPhCall() << std::endl; // 11111111

	// DeusEx test
	std::cout << "======================\nDeusEx test\n";
	DeusEx d("DeusEx", 1000);
	d.setAge(30);
	d.setName("Harbinger");
	d.setCatchPhrase("CatchPhrase");
	d.setPhAge(40);
	d.setPhName("Prophet");
	std::string* prophecies{ new std::string[3] { "Прововедь1", "Главная проповедь", "Проповедь2" } };
	d.setMagnumOpus(prophecies);
	d.show();

	// Believer test
	std::cout << "======================\nBeliever test\n";
	Believer b("Believer", 15);
	b.setGdName("DeusEx");
	b.setGdYear(1000);
	b.setPhName("Prophet");
	b.show();

	return 0;
}
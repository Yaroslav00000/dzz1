#include <iostream>
#include <string>

using namespace std;

class Human
{
private:
	string _first_name;
	string _gender;
	int _age;
public:
	Human()
	{
		_first_name = "NULL";
		_gender = "NULL";
		_age = NULL;
	}
	Human(string first_name) : Human()
	{
		_first_name = first_name;
	}
	Human(string first_name, int age) : Human(first_name)
	{
		_age = age;
	}
	Human(string first_name, int age, string gender) : Human(first_name, age)
	{
		_gender = gender;
	}

	void about()
	{
		cout << "First name: " << _first_name << endl;
		cout << "Age: " << _age << endl;
		cout << "Gender: " << _gender << endl;
	}

};

class Room
{
private:
	int _number_room;
	int _amount_human;
	int _floor;
	int _area;
	Human* human;
public:
	Room()
	{
		_number_room = NULL;
		_floor = NULL;
		_area = NULL;
		_amount_human = NULL;
		human = nullptr;
	}
	Room(int number_room) : Room()
	{
		_number_room = number_room;
	}
	Room(int number_room, int floor) : Room(number_room)
	{
		_floor = floor;
	}
	Room(int number_room, int floor, int area) : Room(number_room, floor)
	{
		_area = area;
	}
	Room(int number_room, int floor, int area, Human* human, int amount_human) : Room(number_room, floor, area)
	{
		this->human = human;
		this->_amount_human = amount_human;
	}
	Room(int number_room, int floor, int area, int amount_human) : Room(number_room, floor, area)
	{
		_amount_human = amount_human;
		human = new Human[amount_human];
	}

	void about()
	{
		cout << "Number room: " << _number_room << endl;
		cout << "Floor: " << _floor << endl;
		cout << "Area: " << _area << endl;
		if (human != nullptr)
		{
			for (int i = 0; i < _amount_human; i++)
			{
				human[i].about();
			}
		}
		else
		{
			cout << "Amount human: 0" << endl;
		}
	}
	~Room()
	{
		delete[] human;
	}
};

class House
{
private:
	string _address;
	int _number_house;
	int _quantity_room;
	Room* rooms;
public:
	House()
	{
		_address = "NULL";
		_number_house = NULL;
		_quantity_room = NULL;
		rooms = nullptr;
	}
	House(string address) : House()
	{
		_address = address;
	}
	House(string address, int number_house) : House(address)
	{
		_number_house = number_house;
	}
	House(string address, int number_house, int quantity_room) : House(address, number_house)
	{
		_quantity_room = quantity_room;
		rooms = new Room[quantity_room];
	}
	House(string address, int number_house, int quantity_room, Room* rooms) :House(address, number_house)
	{
		_quantity_room = quantity_room;
		this->rooms = rooms;
	}

	void about()
	{
		cout << "Address: " << _address << endl;
		cout << "Number house: " << _number_house << endl;
		cout << "Quantity room: " << _quantity_room << endl;
		if (rooms != nullptr)
		{
			for (int i = 0; i < _quantity_room; i++)
			{
				rooms[i].about();
			}
		}
		else
		{
			cout << "Quantity room: 0" << endl;
		}
	}
	~House()
	{
		delete[] rooms;
	}
};


int main()
{
	Human* people_group_1 = new Human[2]{
		Human("Bob", 12, "Male"),
		Human("Kate", 33, "Female"),
	};
	Human* people_group_2 = new Human[1]{
		Human("Alex", 22, "Male"),
	};
	Room* rooms = new Room[2]{
		Room(1, 1, 12, people_group_1, 2),
		Room(2, 2, 15, people_group_2, 1),
	};
	House house("Kiev", 13, 2, rooms);

	house.about();


	return 0;
}
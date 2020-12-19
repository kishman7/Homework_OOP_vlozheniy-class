#include<iostream>
#include <string>
#include <windows.h>
#include <cmath>
#include <ctime>

using namespace std;

class House {
	class Room {
	private:
		int width;
		int length;
		int floor;
	public:
		// getters, setters
		int Getwidth() { return width;}
		int Getlength() { return length;}
		int Getfloor() { return floor;}
		void Setwidth(int width) { this->width = width; }
		void Setlength(int length) { this->length = length; }
		void Setfloor(int floor) { this->floor = floor; }

		Room() {} // Default constructor
		
		Room(int width, int length) {  // Constructor with parameters
			this->width = width;
			this->length = length;
		}
		void CreatRoom(int width, int length) {
			this->width = width;
			this->length = length;
		}
		int RoomsSquare() {  // Search for room area
			this->length = length;
			return this->width * this->length;
		}

		void PrintRoom(){
			cout << "-----------------------------------------------------" << endl;
			cout << "Width our room: " << width << " m^2" << endl;
			cout << "Length our room: " << length << " m^2" << endl;
			cout << "-----------------------------------------------------" << endl;
		}
	};
private:
	Room room_kitchen;
	int count_room = 0;
	//int count_floor;
	Room* rooms;
	int size;
public:
	House(){
		cout << "Enter the number of rooms in the house: ";
		cin >> this->size;
		int width_room;
		int length_room;
		int width_room_kitchen;
		int length_room_kitchen;
		this->rooms = new Room[this->size];
		for (int i = 0; i < this->size; i++)
		{
			cout << "Enter width room: ";
			cin >> width_room;
			cout << "Enter length room: ";
			cin >> length_room;
			rooms[i].CreatRoom(width_room, length_room);
			count_room++;
		}
		cout << "Enter the width and length of the kitchen: " << endl;
		cout << "Enter width kitchen-room: ";
		cin >> width_room_kitchen;
		cout << "Enter length kitchen-room: ";
		cin >> length_room_kitchen;

		room_kitchen.CreatRoom(width_room_kitchen, length_room_kitchen);
	}
	
	void PrintHouse() {
		for (int i = 0; i < size; i++)
		{
			cout << "\nParameters room " << i+1 << endl;
			rooms[i].PrintRoom();
			cout << "Square room number " << i + 1 << " = " << rooms[i].RoomsSquare() << " m^2" << endl;
		}
	}
	void PrintKitchen() {
		cout << "\nParameters kitchen-room" << endl;
		room_kitchen.PrintRoom();
		cout << "Square kitchen-room  " << room_kitchen.RoomsSquare() << " m^2" << endl;

	}
	int totalRoomsSquare() {
		int SumaSquare = 0;
		int TotalSumaSquare = 0;

		for (int i = 0; i < size; i++)
		{
			rooms[i].RoomsSquare();
			SumaSquare += rooms[i].RoomsSquare();
		}
		TotalSumaSquare = SumaSquare + room_kitchen.RoomsSquare();
		return TotalSumaSquare;
	}
	void ChangSizeRoom() {
		int chang = 0;
		int new_width_room;
		int new_length_room;

		cout << "\nChange the size of which room: ";
		cin >> chang;
		for (int i = 0; i < size; i++)
		{
			if (chang == i+1)
			{
				cout << "Enter new width room: ";
				cin >> new_width_room;
				cout << "Enter new length room: ";
				cin >> new_length_room;
				rooms[i].CreatRoom(new_width_room, new_length_room);
				break;
			}
			else if(chang <= 0 || chang > size)
			{
				cout << "WARNING!!! No number room!!!" << endl;
				break;
			}
		}
	}
	void ChangSizeKitchenRoom() {
		int new_width_room;
		int new_length_room;
		cout << "Enter new width kitchen-room: ";
		cin >> new_width_room;
		cout << "Enter new length kitchen-room: ";
		cin >> new_length_room;
		room_kitchen.CreatRoom(new_width_room, new_length_room);
	}
	~House() 
	{
		delete[]rooms;
	}
};




int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	House house;
	int action = 1;
	while (action)
	{
		cout << "\n\n======MENU======" << endl;
		cout << "1.Output of information about the rooms of the house." << endl;
		cout << "2.Calculation of the total area of rooms." << endl;
		cout << "3.Change the size of the room." << endl;
		cout << "0.Exit." << endl << endl;
		cout << "Enter menu item: ";
		cin >> action;
		switch (action)
		{
		case 1: 
		{
			house.PrintHouse();
			house.PrintKitchen();
			break;
		}
		case 2:
		{
			cout << "\nTotal Rooms Square " << house.totalRoomsSquare() << " m^2" << endl;
			break;

		}
		case 3:
		{
			int action1 = 1;
			while (action1)
			{
				cout << "\n======MENU======" << endl;
				cout << "1.Resize  rooms." << endl;
				cout << "2.Resize  kitchen-rooms." << endl;
				cout << "0.Exit." << endl << endl;
				cout << "Enter menu item: ";
				cin >> action1;
				switch (action1)
				{
				case 1:
				{
					house.ChangSizeRoom();
					break;
				}
				case 2:
				{
					house.ChangSizeKitchenRoom();
					break;
				}
				case 0:
				{
					break;
				}
				default:
					cout << "You have selected an incorrect menu item. Make your choice again!" << endl;
				}
			}
			break;
		}
		case 0:
		{
			cout << "Thank you for your work. Goodbye." << endl;
			break;
		}
		default:
			cout << "You have selected an incorrect menu item. Make your choice again!" << endl;
		}

	}




	

	


	return 0;
}
#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include "item.h"

template<typename T>
class inventory {
private:
	T* pItems_;
	int capacity_;
	int size_;
	std::map<std::string, int> potion_;
	const int Max_stock = 3;

public:

	inventory(int capacity)
	{
		this->capacity_ = capacity;
		this->size_ = 0;
		this->pItems_ = new T[capacity_];
	}


	inventory(const inventory& other)
	{
		this->capacity_ = other.capacity_;
		this->size_ = other.size_;
		this->pItems_ = new T[this->capacity_];
		for (int i = 0; i < size_; i++)
		{
			this->pItems_[i] = other.pItems_[i];
		}
	}


	~inventory()
	{
		if (pItems_ != nullptr) {
			delete[] pItems_; 
		}
	}


	void Resize(int newCapacity)
	{
		T* newItems = new T[newCapacity]; 

		for (int i = 0; i < size_; i++)
		{
			newItems[i] = pItems_[i]; 
		}
		delete[] pItems_; 

		this->pItems_ = newItems; 
		this->capacity_ = newCapacity; 
	}


	void AddItem(T item)
	{
		if (size_ >= capacity_)
		{
			std::cout << "* inventory is Full!\n";
			std::cout << "* Inventory auto-expanded! (" << capacity_ << " -> " << capacity_ * 2 << ")\n";
			Resize(capacity_ * 2);
			std::cout << "-> Item added\n";
			pItems_[size_] = item;
			size_++;
		}
		else
		{
			pItems_[size_] = item;
			size_++;
		}
	}


	void RemoveLastItem()
	{
		if (size_ > 0)
		{
			size_--;
		}
	}


	void PrintAllItems()
	{
		if (size_ <= 0)
		{
			std::cout << "* Inventory is Empty.\n";
		}
		else
		{
			for (int i = 0; i < size_; i++)
			{
				std::cout << i + 1 << ". " << pItems_[i] << std::endl;
			}
		}
	}

	int GetSize()
	{
		return size_;
	}

	int GetCapacity()
	{
		return capacity_;
	}


	T& operator[](int index) {
		return pItems_[index];
	}


	void RemoveItemAt(int index) {
		if (index < 0 || index >= size_) return;
		for (int i = index; i < size_ - 1; i++) {
			pItems_[i] = pItems_[i + 1];
		}
		size_--;
	}


	void sortItems()
	{
		std::sort(pItems_, pItems_ + size_, Item::compareByPrice);
		std::cout << "Inventory Sorted.\n";
	}


	void DispensePotion(std::string name)
	{

		auto it = potion_.find(name);

		if (it != potion_.end() && it->second > 0)
		{
			it->second--;
			std::cout << "-> Dispense " << name << " ( stock : " << it->second << " )\n";
		}
		else
		{
			std::cout << "-> Dispense failed: out of stock!\n";
		}
	}

	
	void ReturnPotion(std::string name)
	{
		auto it = potion_.find(name);


		if (it == potion_.end())
		{
			potion_[name] = 3; 
			std::cout << "-> Return " << name << " ( stock : 1 )\n";
		}
		
		else if (it->second < Max_stock)
		{
			it->second++;
			std::cout << "-> Return " << name << " ( stock : " << it->second << " )\n";
		}
	
		else
		{
			std::cout << "-> Return failed: stock is Full!\n";
		}
	}


	int GetStock(std::string name)
	{
		auto it = potion_.find(name);
		if (it != potion_.end())
		{
			std::cout << name << " stock : " << it->second << std::endl;
			return it->second; 
		}
		else
		{
			std::cout << "Not Found...\n";
			return -1; 
		}
	}

}; 
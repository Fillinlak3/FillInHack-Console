	// ArrayLists Header
#pragma once
#ifndef __ARRAYLISTS_H_
#define __ARRAYLISTS_H_

#ifndef _IOSTREAM_
#include <iostream>
#endif
#ifndef _WINDOWS_
#include <Windows.h>
#endif
#ifndef __FIH_EXCEPTIONS_H
#include "FIH_Exceptions.h"
#endif

template<class _Type>
class List {

	// Class Variables
private: _Type* arr = nullptr;
private: _Type* _backup = nullptr;
private: size_t size = 0;

		// Function Definitions
	// Constructors
public: List();
public: List(size_t);
		// Destructor
public: ~List();
		// Overloads
public: friend std::ostream& operator<<(std::ostream&, const List<_Type>&);

		// Methods
private: bool __CheckInstance() const;
private: void __RunBackup() noexcept;
private: void __AddNew(const _Type) noexcept;

public: template<typename First, typename...Args> void Add(First element, const Args...args);
public: bool Remove(const size_t index) noexcept;
public: bool Remove(const size_t begin, const size_t end) noexcept;
public: _Type Get(const size_t index);
public: _Type& At(const size_t index) const;
public: size_t Count() const noexcept;
public: _Type Front() const;
public: _Type Back() const;
public: bool isEmpty() const noexcept;
public: bool Contains(const _Type element) const noexcept;
public: void push_back(const _Type element) noexcept;
public: void push_front(const _Type element) noexcept;
public: void pop_back();
public: void pop_front();
public: bool ReplaceAll(const _Type destination, const _Type source) noexcept;
public: bool Replace(const size_t index, const _Type source) noexcept;
public: bool ReplaceFirst(const _Type destination, const _Type source) noexcept;
public: bool ReplaceLast(const _Type destination, const _Type source) noexcept;
public: void Reverse();
public: void Clear() noexcept;
public: void Sort(bool = 0);
public: size_t Find(_Type element) const;
};


#endif // !__ARRAYLISTS_H_
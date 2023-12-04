#include "../Libs/Array_Lists.h"

#pragma region ListHead
template<class _Type>
List<_Type>::List() { }

template<class _Type>
List<_Type>::List(size_t _size) {
	this->arr = new _Type[_size];
	this->size = _size;
}

template<class _Type>
List<_Type>::~List() {
	delete[] this->_backup;
	delete[] this->arr;
}

template<class _Type>
std::ostream& operator<< (std::ostream& os, const List<_Type>& _list) {
	// Returning the os to the stream
	return os;
}

template<class _Type>
bool List<_Type>::__CheckInstance() const {
	if (this->isEmpty())
		throw FIH_Exceptions("List not instantiated.\n");
}

template<class _Type>
void List<_Type>::__RunBackup() noexcept {
	// Bakup array data
	this->_backup = new _Type[this->size];
	for (size_t i = 0; i < this->size; i++)
		this->_backup[i] = this->arr[i];
}

template<class _Type>
void List<_Type>::__AddNew(_Type _el) noexcept {
	// Bakup array data
	this->__RunBackup();

	// Restore backup & add element
	this->size++;
	this->arr = new _Type[this->size];
	for (size_t i = 0; i < this->size - 1; i++)
		this->arr[i] = this->_backup[i];
	this->arr[this->size - 1] = _el;
}
#pragma endregion

#pragma region Methods
/// <summary>
/// Add one or more elements to list.
/// </summary>
template<typename _Type>
template<typename First, typename...Args>
void List<_Type>::Add(First _el, const Args...args)
{
	va_list _list;
	va_start(_list, _el);
	int _size = sizeof...(args) + 1;
	for (size_t i = 0; i < _size; i++)
	{
		this->__AddNew(_el);
		_el = va_arg(_list, First);
	}
	va_end(_list);
}

/// <summary>
/// Sort the list (0 - ascending || 1 - descending)
/// </summary>
template<class _Type>
void List<_Type>::Sort(bool mode) {
	this->__CheckInstance();

	if (mode)
	{
		for (size_t i = 0; i < this->size; i++)
			for (size_t j = 0; j < this->size; j++)
				if (this->arr[j] < this->arr[i])
					std::swap(this->arr[j], this->arr[i]);
	}
	else {
		for (size_t i = 0; i < this->size; i++)
			for (size_t j = 0; j < this->size; j++)
				if (this->arr[j] > this->arr[i])
					std::swap(this->arr[j], this->arr[i]);
	}
}

/// <summary>
/// Reverse the list.
/// </summary>
template<class _Type>
void List<_Type>::Reverse() {
	__CheckInstance();

	// Backup array
	this->__RunBackup();

	// Restore backup
	for (int i = this->size - 1, j = 0; i >= 0; i--, j++)
		this->arr[j] = this->_backup[i];
}

/// <summary>
/// Returns TRUE or FALSE if the element exists in the list.
/// </summary>
template<class _Type>
size_t List<_Type>::Find(_Type _el) const {
	this->__CheckInstance();

	for (size_t i = 0; i < this->size; i++)
		if (this->arr[i] == _el)
			return i;
}

/// <summary>
/// Clear list & delete all components.
/// </summary>
template<class _Type>
void List<_Type>::Clear() noexcept {
	this->arr = nullptr;
	this->_backup = nullptr;
	this->size = NULL;
}

/// <summary>
/// Remove last element of the list.
/// </summary>
template<class _Type>
void List<_Type>::pop_back() {
	__CheckInstance();

	// Backup array
	this->__RunBackup();

	// Restore backup & remove last element
	this->arr = new _Type[--this->size];
	for (size_t i = 0; i < this->size; i++)
		this->arr[i] = this->_backup[i];
}

/// <summary>
/// Add element in front of the list.
/// </summary>
template<class _Type>
void List<_Type>::push_front(const _Type _el) noexcept {
	// Backup array
	this->__RunBackup();

	// Restore backup
	this->arr = new _Type[++this->size];
	for (size_t i = this->size - 1; i >= 1; i--)
		this->arr[i] = this->_backup[i - 1];

	this->arr[0] = _el;
}

/// <summary>
/// Remove first element of the list.
/// </summary>
template<class _Type>
void List<_Type>::pop_front() {
	__CheckInstance();

	// Backup array
	this->__RunBackup();

	// Restore backup
	for (size_t i = 1; i <= this->size; i++)
		this->arr[i - 1] = this->arr[i];

	this->size--;
}

/// <summary>
/// Add element at end of the list.
/// </summary>
template<class _Type>
void List<_Type>::push_back(const _Type _el) noexcept {
	this->__AddNew(_el);
}

/// <summary>
/// Replace all elements.
/// </summary>
template<class _Type>
bool List<_Type>::ReplaceAll(const _Type _dest, const _Type _source) noexcept {
	bool found = false;

	if (!this->isEmpty())
		for (size_t i = 0; i < this->size; i++)
			if (this->arr[i] == _dest)
			{
				arr[i] = _source; found = true;
			}

	return found;
}

/// <summary>
/// Replace element at INDEX.
/// </summary>
template<class _Type>
bool List<_Type>::Replace(const size_t index, const _Type source) noexcept {
	if (index >= this->size || this->isEmpty())
		return false;

	for (size_t i = 0; i < this->size; i++)
		if (index == i)
		{
			this->arr[i] = source; return true;
		}
}

/// <summary>
/// Replace the first element.
/// </summary>
template<class _Type>
bool List<_Type>::ReplaceFirst(const _Type _dest, const _Type _src) noexcept {
	if (!this->isEmpty())
		for (size_t i = 0; i < this->size; i++)
			if (this->arr[i] == _dest)
			{
				this->arr[i] = _src; return true;
			}

	return false;
}

/// <summary>
/// Replace the last element.
/// </summary>
template<class _Type>
bool List<_Type>::ReplaceLast(const _Type _dest, const _Type _src) noexcept {
	if (!this->isEmpty())
		for (size_t i = this->size - 1; i >= 0; i--)
			if (this->arr[i] == _dest)
			{
				this->arr[i] = _src; return true;
			}

	return false;
}

/// <summary>
/// Returns if the list is NULL or EMPTY.
/// </summary>
template<class _Type>
bool List<_Type>::isEmpty() const noexcept {
	return ((this->arr == nullptr && this->size == NULL) ? true : false);
}

/// <summary>
/// Returns TRUE or FALSE if the element exists in the list.
/// </summary>
template<class _Type>
bool List<_Type>::Contains(_Type _el) const noexcept {
	if (!this->isEmpty())
		for (size_t i = 0; i < this->size; i++)
			if (_el == arr[i])
				return true;

	return false;
}

/// <summary>
/// Remove the element at INDEX.
/// </summary>
template<class _Type>
bool List<_Type>::Remove(size_t _index) noexcept {
	if (_index >= this->size || this->isEmpty())
		return false;

	// pop_back used if is the last element of the array
	if (_index == this->size - 1)
		this->pop_back();
	else {
		// Bakup array data
		this->__RunBackup();

		for (size_t i = _index + 1; i <= this->size; i++)
			this->arr[i - 1] = this->arr[i];

		this->size--;
	}

	return true;
}

/// <summary>
/// Remove the elements between the begin & end.
/// </summary>
template<class _Type>
bool List<_Type>::Remove(const size_t _begin, const size_t _end) noexcept {
	if (_begin >= _end || _begin >= this->size || _end >= this->size || this->isEmpty())
		return false;

	// Bakup array data
	this->__RunBackup();

	for (size_t i = _end + 1, j = 0; i < this->size; i++, j++)
		this->_backup[_begin + j] = this->_backup[i];

	this->size -= (_end - _begin + 1);
	for (size_t i = 0; i < this->size; i++)
		this->arr[i] = this->_backup[i];

	return true;
}

/// <summary>
/// Returns the element at INDEX.
/// </summary>
template<class _Type>
_Type List<_Type>::Get(const size_t _index) {
	this->__CheckInstance();

	if (_index >= this->size)
		throw FIH_Exceptions("List out of bounds.\n");

	return this->arr[_index];
}

/// <summary>
/// Returns the element at INDEX.
/// </summary>
template<class _Type>
_Type& List<_Type>::At(const size_t _index) const {
	this->__CheckInstance();

	if (_index >= this->size)
		throw FIH_Exceptions("List out of bounds.\n");

	return this->arr[_index];
}

/// <summary>
/// Returns the list's size.
/// </summary>
template<class _Type>
size_t List<_Type>::Count() const noexcept {
	return this->size;
}

/// <summary>
/// Returns the first element of the list.
/// </summary>
template<class _Type>
_Type List<_Type>::Front() const {
	this->__CheckInstance();

	return this->arr[0];
}

/// <summary>
/// Returns the last element of the list.
/// </summary>
template<class _Type>
_Type List<_Type>::Back() const {
	this->__CheckInstance();

	return this->arr[size - 1];
}
#pragma endregion

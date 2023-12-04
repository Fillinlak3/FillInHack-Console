#include "../Libs/Random_Generator.h"

void Random::resetSeed() { srand((uint32_t)time((time_t*)NULL)); }

int Random::nextInt(const int _range) {
	// Short annotation for next integer between 0 and the range (length).
	return nextInt(0, _range);
}

int Random::nextInt(const int _First, const int _Second) {
	if (!(_First == _Second && _Second == 0))
		/*
			The range must be different from 0 (range != 0),
			The range is determined by the first and second number's length.
			Like for 5 - 10, the range is between 5 - 10.
		*/
		if (_Second < _First && _First == 0)
			/*
				If the second number is lower than the first, and first is 0, then
				the range should be -_Second, 0.
			*/
			// Only Negative Numbers Ecuation
			return -1 * (_First + std::rand() % (_Second - _First + 1));
		else
			/*
				Else if the second number is either a negative or positive number and the first number is either
				0, negative or positive.
			*/
			// Negative and Positive Numbers Ecuation
			return (_First + std::rand() % (_Second - _First + 1));
	/*
		So, the point for this if statements is that if you would leave only the second ecuation, then for 0, -1 range
		the reusult will be a positive number.
	*/
	throw FIH_Exceptions("cannot generate a number from this range\n");
}

char* Random::nextNumber(const size_t _num) {
	size_t _size = 0;
	char* _str = new char[_num + 1];
	for (_size = 0; _size < _num; _size++)
		_str[_size] = Numbers[nextInt(0, 9)];
	_str[_size] = '\0';
	return _str;
}

char Random::nextChar(void) noexcept {
	// Returning a single symbol, letter or number.
	return char(nextInt(33, 126));
}

char* Random::nextChar(const size_t _num) noexcept {
	// Returning a symbol, letter or number * _num times.
	size_t _size = 0;
	char* _str = new char[_num + 1];
	for (_size = 0; _size < _num; _size++)
		_str[_size] = nextChar();
	_str[_size] = '\0';
	return _str;
}

char* Random::nextChar(const size_t _num, const char* delim) noexcept {
	// Returning a symbol, letter or number * _num times.
	size_t _size = 0;
	char* _str = new char[_num + 1];
	for (_size = 0; _size < _num; _size++)
	{
		char c = nextChar();
		if (strchr(delim, c))
			while (strchr(delim, c))
				c = nextChar();
		_str[_size] = c;
	}
	_str[_size] = '\0';
	return _str;
}

char Random::nextLetter(void) noexcept {
	// Return a single alphabetical letter.
	return char(Letters[nextInt(0, 51)]);
}

char* Random::nextLetter(const size_t _num) noexcept {
	// Returning a alphabetical letter * _num times.
	size_t _size = 0;
	char* _str = new char[_num + 1];
	for (_size = 0; _size < _num; _size++)
		_str[_size] = nextLetter();
	_str[_size] = '\0';
	return _str;
}

bool Random::nextBoolean(void) noexcept {
	// Returning a number between 0 and 1, false or true.
	return nextInt(1);
}

float Random::nextFloat(void) noexcept {
	float _number = 0;
	for (int i = 0; i < 7; i++)
		_number = _number * 10 + nextInt(10);
	// Obtaining a positive number then make it decimal.
	return _number / 10000000;
}

double Random::nextDouble(void) noexcept {
	double _number = 0;
	for (int i = 0; i < 7; i++)
		_number = _number * 10 + nextInt(10);
	// Same as the function above.
	return _number / 10000000;
}

template<typename _Element, size_t n>
_Element Random::nextArrayElement(const _Element(&_el)[n]) const noexcept {
	// The n is for the capacity (size) of the array.
	return _el[nextInt(n)];
}

template<typename _Element, size_t n, size_t m>
_Element Random::nextArrayElement(const _Element(&_el)[n][m]) const noexcept {
	// The n and m are for the capacity (size) of the array in array.
	return _el[nextInt(n)][nextInt(m)];
}

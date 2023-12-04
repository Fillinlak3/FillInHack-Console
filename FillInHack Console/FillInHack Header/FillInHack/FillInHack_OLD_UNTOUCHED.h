/*
█████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████
█░░░░░░░░░░░░░░█░░░░░░░░░░█░░░░░░█████████░░░░░░█████████░░░░░░░░░░█░░░░░░██████████░░░░░░█░░░░░░██░░░░░░█░░░░░░░░░░░░░░█░░░░░░░░░░░░░░█░░░░░░██░░░░░░░░█
█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀░░█░░▄▀░░█████████░░▄▀░░█████████░░▄▀▄▀▄▀░░█░░▄▀░░░░░░░░░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░██░░▄▀▄▀░░█
█░░▄▀░░░░░░░░░░█░░░░▄▀░░░░█░░▄▀░░█████████░░▄▀░░█████████░░░░▄▀░░░░█░░▄▀▄▀▄▀▄▀▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░░░░░░░░░█░░▄▀░░██░░▄▀░░░░█
█░░▄▀░░███████████░░▄▀░░███░░▄▀░░█████████░░▄▀░░███████████░░▄▀░░███░░▄▀░░░░░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░█████████░░▄▀░░██░░▄▀░░███
█░░▄▀░░░░░░░░░░███░░▄▀░░███░░▄▀░░█████████░░▄▀░░███████████░░▄▀░░███░░▄▀░░██░░▄▀░░██░░▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░█████████░░▄▀░░░░░░▄▀░░███
█░░▄▀▄▀▄▀▄▀▄▀░░███░░▄▀░░███░░▄▀░░█████████░░▄▀░░███████████░░▄▀░░███░░▄▀░░██░░▄▀░░██░░▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░█████████░░▄▀▄▀▄▀▄▀▄▀░░███
█░░▄▀░░░░░░░░░░███░░▄▀░░███░░▄▀░░█████████░░▄▀░░███████████░░▄▀░░███░░▄▀░░██░░▄▀░░██░░▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░░░░░▄▀░░█░░▄▀░░█████████░░▄▀░░░░░░▄▀░░███
█░░▄▀░░███████████░░▄▀░░███░░▄▀░░█████████░░▄▀░░███████████░░▄▀░░███░░▄▀░░██░░▄▀░░░░░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░█████████░░▄▀░░██░░▄▀░░███
█░░▄▀░░█████████░░░░▄▀░░░░█░░▄▀░░░░░░░░░░█░░▄▀░░░░░░░░░░█░░░░▄▀░░░░█░░▄▀░░██░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░░░░░░░░░█░░▄▀░░██░░▄▀░░░░█
█░░▄▀░░█████████░░▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀▄▀▄▀░░█░░▄▀░░██░░░░░░░░░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀░░██░░▄▀░░█░░▄▀▄▀▄▀▄▀▄▀░░█░░▄▀░░██░░▄▀▄▀░░█
█░░░░░░█████████░░░░░░░░░░█░░░░░░░░░░░░░░█░░░░░░░░░░░░░░█░░░░░░░░░░█░░░░░░██████████░░░░░░█░░░░░░██░░░░░░█░░░░░░██░░░░░░█░░░░░░░░░░░░░░█░░░░░░██░░░░░░░░█
█████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████
*/

/*
	// FillInHack Header
	// Developer Bucuriee
	// Copyright (c) FillInHack Corporation.
*/

#pragma once
#ifndef __FillInHack_Engine_H_
#define __FillInHack_Engine_H_
//#define _CRT_SECURE_NO_WARNINGS

// -- Libraries --
#include <chrono>
#include <sstream>
#include <Windows.h>
#include <fstream>
#include <string>
// -----------------------------

// -- FIH Namespace --
namespace FIH {

	// -- FIH_Exceptions Class --
	class FIH_Exceptions : public std::exception {
	private:
		const char* exc;
	public:
		FIH_Exceptions(const char *_msg)
		: exc(_msg)
		{ /*this->exc = _msg;*/ }

		const char* what() const throw()
		{
			return this->exc;
		}

	};

	// -- Colored_Console Namespace --
	namespace Colored_Console  {

		// Colored_Console Header
	#ifndef __COLORED_CONSOLE_H
	#define __COLORED_CONSOLE_H

	/// <summary>
	/// Create an instance object of Console class and use SetColor(colorname)
	/// </summary>
	#pragma region Namespace_Color_Palette
			namespace Color_Palette {
				// -- Macros -> Define Colors --
	#ifdef _Colored_Console_Colors_Macros_ // Define before including library
	#define BLACK FIH::Colored_Console::Colored_Console::SetColor(0)
	#define BLUE FIH::Colored_Console::Colored_Console::SetColor(1)
	#define GREEN FIH::Colored_Console::Colored_Console::SetColor(2)
	#define CYAN FIH::Colored_Console::Colored_Console::SetColor(3)
	#define RED FIH::Colored_Console::Colored_Console::SetColor(4)
	#define MAGENTA FIH::Colored_Console::Colored_Console::SetColor(5)
	#define GOLD FIH::Colored_Console::Colored_Console::SetColor(6)
	#define WHITE FIH::Colored_Console::Colored_Console::SetColor(7)
	#define GRAY FIH::Colored_Console::Colored_Console::SetColor(8)
	#define BRIGHT_BLUE FIH::Colored_Console::Colored_Console::SetColor(9)
	#define LIME FIH::Colored_Console::Colored_Console::SetColor(10)
	#define SKY_BLUE FIH::Colored_Console::Colored_Console::SetColor(11)
	#define BRIGHT_RED FIH::Colored_Console::Colored_Console::SetColor(12)
	#define BRIGHT_MAGENTA FIH::Colored_Console::Colored_Console::SetColor(13)
	#define YELLOW FIH::Colored_Console::Colored_Console::SetColor(14)
	#define BRIGHT_WHITE FIH::Colored_Console::Colored_Console::SetColor(15)
	#define RESET FIH::Colored_Console::Colored_Console::ResetColor()
	#endif // _Colored_Console_Colors_Macros_ definiton

	/// <summary>
	/// black, blue, green, cyan, red, magenta, gold, white, gray, bright_blue, bright_green, sky_blue, bright_red, bright_magenta, yellow, bright_white
	/// </summary>
				enum class Color {
					black,
					blue,
					green,
					cyan,
					red,
					purple,
					gold,
					white,
					gray,
					indigo,
					lime,
					aqua,
					bright_red,
					magenta,
					yellow,
					bright_white,
					//reset
				};
			}
	#pragma endregion

	#pragma region Class_Colored_Console
			/// <summary>
			/// SetColor(colorname / index)
			/// </summary>
			class Colored_Console {
			protected:
				template<typename _TColor_Name = Color_Palette::Color>
				const static int GetColorIndex(const _TColor_Name _foreground, const _TColor_Name _background = Color_Palette::Color::black) noexcept;

			public:
				const static void SetColor(const int index) noexcept;
				const static void ResetColor(void) noexcept;

				template<typename _TColor_Name = Color_Palette::Color>
				const static void SetColor(const _TColor_Name _colorname) noexcept;

				template<typename _TColor_Name = Color_Palette::Color>
				const static void SetColor(const _TColor_Name _foreground, const _TColor_Name _background) noexcept;
			}; Colored_Console Console;
	#pragma endregion

	#pragma region Console_Functions
			/// <summary>
			/// Set text color using id
			/// </summary>
			/// <param name="index"></param>
			const void Colored_Console::SetColor(const int index) noexcept {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), index);
			};
			/// <summary>
			/// Reset text color
			/// </summary>
			/// <returns></returns>
			const void Colored_Console::ResetColor(void) noexcept {
				/** This sets the line to normal ( reseting it ) **/
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			};
			/// <summary>
			/// Set Color using a colorname
			/// </summary>
			/// <param name="">black, blue, green, cyan, red, magenta, gold, white, gray, bright_blue, bright_green, sky_blue, bright_red, bright_magenta, yellow, bright_white</param>
			template<typename _TColor_Name>
			const void Colored_Console::SetColor(const _TColor_Name _colorname) noexcept {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (static_cast<int>(_colorname)));
			};
			/// <summary>
			/// Set Foreground and Background color
			/// </summary>
			/// <param name="">black, blue, green, cyan, red, magenta, gold, white, gray, bright_blue, bright_green, sky_blue, bright_red, bright_magenta, yellow, bright_white</param>
			/// <returns></returns>
			template<typename _TColor_Name>
			const void Colored_Console::SetColor(const _TColor_Name _foreground, const _TColor_Name _background) noexcept {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (static_cast<int>(_background) * 16 + static_cast<int>(_foreground)));
			};

			template<typename _TColor_Name>
			const int Colored_Console::GetColorIndex(const _TColor_Name _foreground, const _TColor_Name _background) noexcept {
				return (static_cast<int>(_background) * 16 + static_cast<int>(_foreground));
			};
	#pragma endregion

	#endif // !__COLORED_CONSOLE_H
	}

	// -- Converters Namespace --
	namespace Converters  {

		// Converters Header
	#ifndef __CONVERTERS_H
	#define __CONVERTERS_H

	/// <summary>
	/// Strings to Int, Double or Float
	/// </summary>
	#pragma region Converters_Classes
			class Convert_String {
			public:
				static int toInt(const std::string str);

				static float toFloat(const std::string str);

				static double toDouble(const std::string str);

			}; Convert_String String;
			/// <summary>
			/// Integers to String, Float or Double
			/// </summary>
			class Convert_Integer {
			public:
				static std::string toString(const int nr);

				static double toDouble(const int nr);

				static float toFloat(const int nr);

			}; Convert_Integer Integer;
			/// <summary>
			/// Doubles to String, Integer or Float
			/// </summary>
			class Convert_Double {
			public:
				static std::string toString(const double nr);

				static int toInt(const double nr);

				static float toFloat(const double nr);

			}; Convert_Double Double;
			/// <summary>
			/// Floats to String, Int or Double
			/// </summary>
			class Convert_Float {
			public:
				static std::string toString(const float nr);

				static int toInt(const double nr);

				static double toDouble(const int nr);
			}; Convert_Float Float;
	#pragma endregion

	#pragma region Converters_Functions
			// -- CONVERT_STRING CLASS FUNCTIONS --

			int Convert_String::toInt(const std::string str)
			{
				std::stringstream ss(str);
				int nr = 0;
				ss >> nr;
				return nr;
			};
			float Convert_String::toFloat(const std::string str)
			{
				std::stringstream ss(str);
				float nr = 0;
				ss >> nr;
				return nr;
			};
			double Convert_String::toDouble(const std::string str)
			{
				std::stringstream ss(str);
				double nr = 0;
				ss >> nr;
				return nr;
			};

			// -- CONVERT_INTEGER CLASS FUNCTIONS --

			std::string Convert_Integer::toString(const int nr)
			{
				std::stringstream ss;
				ss << nr;
				return ss.str();
			};
			double Convert_Integer::toDouble(const int nr)
			{
				return (double)nr;
			};
			float Convert_Integer::toFloat(const int nr)
			{
				return (float)nr;
			};

			// -- CONVERT_DOUBLE CLASS FUNCTIONS --

			std::string Convert_Double::toString(const double nr)
			{
				std::stringstream ss;
				ss << nr;
				return ss.str();
			};
			int Convert_Double::toInt(const double nr)
			{
				return (int)nr;
			};
			float Convert_Double::toFloat(const double nr)
			{
				return (float)nr;
			};

			// -- CONVERT_FLOAT CLASS FUNCTIONS --

			std::string Convert_Float::toString(const float nr)
			{
				std::stringstream ss;
				ss << nr;
				return ss.str();
			}
			int Convert_Float::toInt(const double nr)
			{
				return (int)nr;
			}
			double Convert_Float::toDouble(const int nr)
			{
				return (double)nr;
			}
	#pragma endregion

	#endif // !__CONVERTERS_H
	}

	// -- Timer Namespace --
	namespace Timer  {

		// Timer Header
	#ifndef __TIMER_H
	#define __TIMER_H

	#pragma region Timer_Literals
			enum class Literals {
				seconds,
				milliseconds
			};
	#pragma endregion

	#pragma region Chrono_Struct
			struct Chrono {
	#pragma region Chrono_Variables
			private: std::chrono::high_resolution_clock::time_point _start, _end;
			private: std::chrono::duration<float> _duration {};
			private: short _pos = -1; // Literal position from Constructor
			private: const char* _timerName;
	#pragma endregion

	#pragma region Chrono_Functions
			public:
				template<typename _TTimer = Literals>
				Chrono(const _TTimer _literal = Literals::milliseconds, const char* _timerName = "Timer") noexcept;
				Chrono(const char* _timerName = "Timer") noexcept;
				~Chrono() noexcept;
	#pragma endregion
			};

	#pragma region Chrono_Function_Definitions
			template<typename _TTimer>
			Chrono::Chrono(const _TTimer _literal, const char* _timerName) noexcept {
				switch (_literal)
				{
				case Literals::seconds:
					this->_pos = 1;
					break;
				case Literals::milliseconds:
					this->_pos = 2;
					break;
				default:
					break;
				}
				this->_timerName = _timerName;
				this->_start = std::chrono::high_resolution_clock::now();
			}
			Chrono::Chrono(const char* _timerName) noexcept {
				this->_pos = 2;
				this->_timerName = _timerName;
				this->_start = std::chrono::high_resolution_clock::now();
			}
			Chrono::~Chrono() noexcept {
				this->_end = std::chrono::high_resolution_clock::now();
				this->_duration = this->_end - this->_start;

				switch (_pos)
				{
					case 1:
					{
						printf("\n[%s] took %.5g s.\n", this->_timerName, (double)this->_duration.count());
						break;
					}
					case 2:
					{
						printf("\n[%s] took %.5g ms.\n", this->_timerName, (double)this->_duration.count() * 1000.0f);
						break;
					}
					default:
						break;
				}
			}
	#pragma endregion
	#pragma endregion

	#endif // !__TIMER_H
	}

	// -- Random_Generator Namespace --
	namespace Random_Generator  {

		// Random_Generator Header
	#ifndef __RANDOM_GENERATOR_H
	#define __RANDOM_GENERATOR_H
	#pragma region Random_Class
		class Random {
			private: const char* Letters = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

			public:
				Random() noexcept { srand(time(0)); }
				void resetSeed() const;
				int nextInt(const int _first, const int _second) const;
				int nextInt(const int _first) const;
				char nextChar(void) const noexcept;
				char* nextChar(const size_t num) const noexcept;
				char* nextChar(const size_t _num, const char* delim) const noexcept;
				char nextLetter(void) const noexcept;
				char* nextLetter(const size_t _num) const noexcept;
				bool nextBoolean(void) const noexcept;
				float nextFloat(void) const noexcept;
				double nextDouble(void) const noexcept;

				// Array.
				template<typename _Element, size_t n>
				_Element nextArrayElement(const _Element(&_el)[n]) const noexcept;

				// Array in array.
				template<typename _Element, size_t n, size_t m>
				_Element nextArrayElement(const _Element(&_el)[n][m]) const noexcept;
		};
	#pragma endregion

	#pragma region Random_Functions
		void Random::resetSeed() const {
			srand(time(0));
		}

		int Random::nextInt(const int _range) const {
			// Short annotation for next integer between 0 and the range (length).
			return this->nextInt(0, _range);
		}

		int Random::nextInt(const int _First, const int _Second) const {
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
			throw FIH::FIH_Exceptions("cannot generate a number from this range\n");
		}

		char Random::nextChar(void) const noexcept {
			// Returning a single symbol, letter or number.
			return char(this->nextInt(32, 126));
		}

		char* Random::nextChar(const size_t _num) const noexcept {
			// Returning a symbol, letter or number * _num times.
			size_t _size = 0;
			char* _str = new char[_num];
			for (_size = 0; _size < _num; _size++)
				_str[_size] = this->nextChar();
			_str[_size] = '\0';
			return _str;
		}

		char* Random::nextChar(const size_t _num, const char* delim) const noexcept {
			// Returning a symbol, letter or number * _num times.
			size_t _size = 0;
			char* _str = new char[_num];
			for (_size = 0; _size < _num; _size++)
			{
				char c = this->nextChar();
				if (strchr(delim, c))
					while (strchr(delim, c))
						c = this->nextChar();
				_str[_size] = c;
			}
			_str[_size] = '\0';
			return _str;
		}

		char Random::nextLetter(void) const noexcept {
			// Return a single alphabetical letter.
			return char(this->Letters[this->nextInt(0, 52)]);
		}

		char* Random::nextLetter(const size_t _num) const noexcept {
			// Returning a alphabetical letter * _num times.
			size_t _size = 0;
			char* _str = new char[_num];
			for (_size = 0; _size < _num; _size++)
				_str[_size] = this->nextLetter();
			_str[_size] = '\0';
			return _str;
		}

		bool Random::nextBoolean(void) const noexcept {
			// Returning a number between 0 and 1, false or true.
			return this->nextInt(1);
		}

		float Random::nextFloat(void) const noexcept {
			float _number = 0;
			for (int i = 0; i < 7; i++)
				_number = _number * 10 + this->nextInt(10);
			// Obtaining a positive number then make it decimal.
			return _number / 10000000;
		}

		double Random::nextDouble(void) const noexcept {
			double _number = 0;
			for (int i = 0; i < 7; i++)
				_number = _number * 10 + this->nextInt(10);
			// Same as the function above.
			return _number / 10000000;
		}

		template<typename _Element, size_t n>
		_Element Random::nextArrayElement(const _Element(&_el)[n]) const noexcept {
			// The n is for the capacity (size) of the array.
			return _el[this->nextInt(n)];
		}

		template<typename _Element, size_t n, size_t m>
		_Element Random::nextArrayElement(const _Element(&_el)[n][m]) const noexcept {
			// The n and m are for the capacity (size) of the array in array.
			return _el[this->nextInt(n)][this->nextInt(m)];
		}
	#pragma endregion
	#endif // !__RANDOM_GENERATOR_H
	}

	// -- ArrayLists Namespace --
	namespace ArrayLists  {

		// ArrayLists Header
	#ifndef __ARRAYLISTS_H_
	#define __ARRAYLISTS_H_
		/*class ListException : public std::exception {
		private:
			const char* _exc;
		public: ListException(const char* _msg)
			: _exc(_msg) { }
		public: const char* what() const throw()
				{
					return this->_exc;
				}
		};*/

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

		// Methods

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
					{ arr[i] = _source; found = true; }

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
				{ this->arr[i] = source; return true; }
		}

		/// <summary>
		/// Replace the first element.
		/// </summary>
		template<class _Type>
		bool List<_Type>::ReplaceFirst(const _Type _dest, const _Type _src) noexcept {
			if (!this->isEmpty())
				for (size_t i = 0; i < this->size; i++)
					if (this->arr[i] == _dest)
					{ this->arr[i] = _src; return true; }

			return false;
		}

		/// <summary>
		/// Replace the last element.
		/// </summary>
		template<class _Type>
		bool List<_Type>::ReplaceLast(const _Type _dest, const _Type _src) noexcept {
			if(!this->isEmpty())
				for (size_t i = this->size - 1; i >= 0; i--)
					if (this->arr[i] == _dest)
					{ this->arr[i] = _src; return true; }

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
	#endif // !__ARRAYLISTS_H_
	}

	// -- FIH_Encryptor Namespace --
	namespace FIH_Encryptor {

		// FIH_Encryptor Header
	#ifndef __FIH_Encryptor_H
	#define __FIH_Encryptor_H

			class Encryptor {
			private:
				long double N;

				std::string m_text;
				std::string m_salt;
				std::string m_pepper;
				std::string m_key;

			private:
				void __runAlgorithm(std::string, std::string);
				void __generateSalt();
				void __getSalt();
				void __generatePepper();
				void __getPepper();
				void XOR_ERR() const;

			public:
				Encryptor();

				void Encrypt(std::string, std::string);
				void Decrypt(std::string, std::string);

				std::string GetText() const;
			};

			void Encryptor::XOR_ERR() const {
				throw FIH_Exceptions("Invalid string range");
			}

			Encryptor::Encryptor() {
				N = pow(2, 256);
			}

			void Encryptor::__generateSalt() {
				Random_Generator::Random rand;
				
				m_salt = rand.nextChar(m_key.length(), " ");
			}

			void Encryptor::__getSalt() {
				std::string gS = m_text;
				m_salt = gS.erase(m_text.find("$FIH$"), m_text.length());
			}

			void Encryptor::__generatePepper() {
				__runAlgorithm(m_key, m_salt);
				m_pepper = m_text;
			}

			void Encryptor::__getPepper() {
				std::string gP = m_text;
				m_pepper = gP.erase(m_key.length(), m_text.length());
				__runAlgorithm(m_pepper, m_salt);
				m_pepper = m_text;
			}

			void Encryptor::__runAlgorithm(std::string text, std::string key)
			{
				m_text.clear();
				//std::string message_crypt;
				int		intKey	= NULL;

				// Create the big number
				/*for (int i = 0; i < key.length(); i++)
					N += pow(2,(int)key[i]);*/

				for (int j = 0; j < m_salt.length(); j++)
					intKey += (int)m_salt[j];

				// [WPA] - Word Processing Algorithm
				for (int i = 0, ctor = 0; i < text.length(); i++, ctor++)
				{
					if (i >= key.length()) ctor = 0;
					m_text += (char)(fmod(((int)text[i] ^ (intKey - ((int)key[ctor] + i))), N));
				}
				//m_text = message_crypt;
			}

			void Encryptor::Encrypt(std::string text, std::string key) {
				m_key = key;
				__generateSalt();
				__generatePepper();

				__runAlgorithm(text, key);
				m_text = "FillInHack!" + m_salt + "$FIH$" + m_pepper + m_text;
			}

			void Encryptor::Decrypt(std::string text, std::string key) {
				std::string m_bkp;
				m_text = text;
				m_key = key;

				if (m_text.find("FillInHack!") != NULL)
					XOR_ERR();
				else {
					m_text.erase(0, 11);
					__getSalt();

					m_text.erase(0, key.length() + 5);					
					m_bkp = m_text;
					__getPepper();

					//printf("[Key]: %s | [Pepper]: %s | [Salt]: %s\n", m_key.c_str(), m_pepper.c_str(), m_salt.c_str());
					if (m_pepper != key || m_pepper.length() != m_salt.length())
						XOR_ERR();
					else {
						m_text = m_bkp;
						m_text.erase(0, key.length());
						__runAlgorithm(m_text, key);
					}
				}
			}

			/// <summary>
			/// Get a string after Encryption or Decryption
			/// </summary>
			std::string Encryptor::GetText() const {
				return m_text;
			}

	#endif // !__FIH_Encryptor_H
	}

	// -- FileManager Namespace --
	namespace FileManager {
	#ifndef __FILEMANAGER_H
	#define __FILEMANAGER_H

			class File : public FIH_Encryptor::Encryptor {
			private:
				#define MAX_KB 350000
			
				std::string m_filename;
				std::string m_data;

				typedef void* FileHandle;
				void* _mappedFile;
				void* _mappedView;
				FileHandle _file;
				ULONG64 _filesize;
				ULONG64 mappedBytes;
				ULONG64 fileKB;

			private:
				void __XOR_ERR();
				void __XOR_ERR_KB_EXCEED() {
					throw FIH_Exceptions("file too big");
				}
				void __readData();
				void __writeData();
				void __getFileKB() {
					std::ifstream f(m_filename, std::ios::binary);

					f.seekg(0, std::ios::end);
					fileKB = f.tellg() / 1000;

					f.close();
				}


				const ULONGLONG Size() const;
				bool __isAlreadyOpened() const {
					return _mappedView != NULL;
				}
				bool __remap(ULONG64 offset, size_t mappedBytes) {
					if (!_file)
						return false;

					if (mappedBytes == NULL)
						mappedBytes = _filesize;

					if (_mappedView) {
						::UnmapViewOfFile(_mappedView);
						_mappedView = NULL;
					}


					// don't go further than end of file
					if (offset > _filesize)
						return false;
					if (offset + mappedBytes > _filesize)
						mappedBytes = size_t(_filesize - offset);


					DWORD offsetLow = DWORD(offset & 0xFFFFFFFF);
					DWORD offsetHigh = DWORD(offset >> 32);

					// get memory address
					_mappedView = ::MapViewOfFile(_mappedFile, FILE_MAP_READ, offsetHigh, offsetLow, mappedBytes);

					if (_mappedView == NULL)
					{
						mappedBytes = 0;
						_mappedView = NULL;
						return false;
					}

					// if all is fine
					return true;
				}

			public:
				File();
				~File();

				File& Set(const char*);
				File& Encrypt_File(std::string);
				File& Decrypt_File(std::string);

				const char* GetAllText();
				File& WriteText();
				void Clear();
				bool isNullOrEmpty();


				bool Open() {
					if (__isAlreadyOpened())
						return false;

					_file = NULL;
					_filesize = NULL;
					_mappedFile = NULL;
					_mappedView = NULL;


					//DWORD winHint = FILE_ATTRIBUTE_NORMAL;
					DWORD winHint = FILE_ATTRIBUTE_READONLY;

					// open file
					_file = ::CreateFileA(m_filename.c_str(), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, winHint, NULL);
					if (!_file)
						return false;


					// get file size
					LARGE_INTEGER result;
					if (!GetFileSizeEx(_file, &result))
						return false;
					_filesize = static_cast<ULONG64>(result.QuadPart);


					// convert to mapped mode
					_mappedFile = ::CreateFileMapping(_file, NULL, PAGE_READONLY, 0, 0, NULL);
					if (!_mappedFile)
						return false;


					// initial mapping
					__remap(0, mappedBytes);

					if (!_mappedView)
						return false;

					// everything's fine
					return true;
				}
				void Close() {
					if (_mappedView) {
						::UnmapViewOfFile(_mappedView);
						_mappedView = nullptr;
					}

					if (_mappedFile) {
						::CloseHandle(_mappedFile);
						_mappedFile = nullptr;
					}

					if (_file) {
						::CloseHandle(_file);
						_file = nullptr;
					}
					_filesize = NULL;
				}
				std::string GetData() const {
					char* s = static_cast<char*>(_mappedView);
					std::string a;

					for (size_t i = 0; i < Size(); i++)
					{
						if (s[i] == 0)
							a += char(0x000);
						else
							a += s[i];
					}
					
					return a;
				}
			};

			File::File()
			:	m_filename(),
				m_data(),
				_filesize(0),
				_file(0),
				mappedBytes(0),
				fileKB(0),
				_mappedFile(NULL),
				_mappedView(NULL)
			{}
			File::~File() {
				Close();
			}

			void File::__XOR_ERR() {
				throw ("file not found");
			}

			const ULONGLONG File::Size() const {
				return _filesize;
			}

			void File::__readData() {
				m_data.clear();

				std::ifstream fin(m_filename, std::ios::binary);

				char c;
				while (fin >> std::noskipws >> c)
					m_data += c;

				fin.close();
			}

			void File::__writeData() {
				std::ofstream _fwrite(m_filename, std::ios::binary);

				_fwrite.write(m_data.c_str(), m_data.length());

				_fwrite.close();
			}

			/// <summary>
			/// Set the filename to access
			/// </summary>
			File& File::Set(const char* filename) {
				m_filename = filename;

				return *this;
			}

			/// <summary>
			/// Encrypt a file
			/// </summary>
			/// <param name="key">Encryption Key</param>
			File& File::Encrypt_File(std::string key) {
			__getFileKB();

			if (fileKB > MAX_KB)
				__XOR_ERR_KB_EXCEED();

			else {
				Open();
				Encrypt(GetData(), key);
				m_data = GetText();
				Close();

			}
			return *this;
		}

			/// <summary>
			/// Decrypt a file
			/// </summary>
			/// <param name="key">Decryption Key</param>
			File& File::Decrypt_File(std::string key) {
			__getFileKB();

			if (fileKB > MAX_KB)
				__XOR_ERR_KB_EXCEED();

			else {
				Open();
				Decrypt(GetData(), key);
				m_data = GetText();
				Close();

			}
			return *this;
		}

			/// <summary>
			/// Get a string with all content ONLY from ONE file
			/// </summary>
			const char* File::GetAllText() {
				Open();
				m_data = GetData();
				return m_data.c_str();
			}

			/// <summary>
			/// Write file after Encryption or Decryption
			/// </summary>
			File& File::WriteText() {
				__writeData();

				return *this;
			}

			/// <summary>
			///	Unselect the current file
			/// </summary>
			void File::Clear() {
				m_filename.clear();
				m_data.clear();
			}

			/// <summary>
			/// Check if the file is empty
			/// </summary>
			bool File::isNullOrEmpty() {
				__readData();
				return m_data.empty();
			}

	#endif // !__FILEMANAGER_H
	}
}

#endif // !__FillInHack_Engine_H_

// Last edit: 08/15/2021
//            MM/DD/YYYY



// Changelog: 08/15/2021
//            MM/DD/YYYY
/*
	###################################
		-- FileManager Namespace --
	###################################
	|	added file limit (350000 KB)
	|	added new function for tracking limit when Encrypting / Decrypting File
	|	added new function to get current file kb
	|	reworked functions Encrypt_File & Decrypt_File to check if the file size is below limit
*/
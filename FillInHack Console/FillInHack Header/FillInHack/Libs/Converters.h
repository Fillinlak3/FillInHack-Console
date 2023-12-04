	// Converters Header
#pragma once
#ifndef __CONVERTERS_H
#define __CONVERTERS_H

#ifndef _SSTREAM_
#include <sstream>
#endif
#ifndef _STRING_
#include <string>
#endif

/// <summary>
/// Strings to Int, Double or Float
/// </summary>
class Convert_String {
public:
	static int toInt(const std::string str);

	static float toFloat(const std::string str);

	static double toDouble(const std::string str);

}; 
extern Convert_String String;

/// <summary>
/// Integers to String, Float or Double
/// </summary>
class Convert_Integer {
public:
	static std::string toString(const int nr);

	static double toDouble(const int nr);

	static float toFloat(const int nr);

}; 
extern Convert_Integer Integer;

/// <summary>
/// Doubles to String, Integer or Float
/// </summary>
class Convert_Double {
public:
	static std::string toString(const double nr);

	static int toInt(const double nr);

	static float toFloat(const double nr);

}; 
extern Convert_Double Double;

/// <summary>
/// Floats to String, Int or Double
/// </summary>
class Convert_Float {
public:
	static std::string toString(const float nr);

	static int toInt(const double nr);

	static double toDouble(const int nr);
}; 
extern Convert_Float Float;


#endif // !__CONVERTERS_H
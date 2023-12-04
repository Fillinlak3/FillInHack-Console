#include "../Libs/Converters.h"

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

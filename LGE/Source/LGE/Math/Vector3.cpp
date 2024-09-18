#include "Vector3.h"

namespace LGE
{
	Vector3::Vector3()
	{
		X = 0.0f; Y = 0.0f; Z = 0.0f;
	}

	Vector3::Vector3(float x, float y, float z)
		: X(x), Y(y), Z(z)
	{
	}

	Vector3 Vector3::operator+(const Vector3& v) const
	{
		return Vector3(X + v.X, Y + v.Y, Z + v.Z);
	}

	Vector3 Vector3::operator+=(const Vector3& v)
	{
		X += v.X;
		Y += v.Y;
		Z += v.Z;
		return *this;
	}

	Vector3 Vector3::operator-(const Vector3& v) const
	{
		return Vector3(X - v.X, Y - v.Y, Z - v.Z);
	}

	Vector3 Vector3::operator-=(const Vector3& v)
	{
		X -= v.X;
		Y -= v.Y;
		Z -= v.Z;
		return *this;
	}

	Vector3 Vector3::operator*(const float s) const
	{
		return Vector3(X * s, Y * s, Z * s);
	}

	Vector3 Vector3::operator*=(const float s)
	{
		X *= s;
		Y *= s;
		Z *= s;
		return *this;
	}

	Vector3 Vector3::operator/(const float s) const
	{
		return *this * (1.0f / s);
	}

	Vector3 Vector3::operator/=(const float s)
	{
		*this *= 1.0f / s;
		return *this;
	}

	float Vector3::Length() const
	{
		return sqrt(X * X + Y * Y + Z * Z);
	}

	float Vector3::Dot(const Vector3& rhs) const
	{
		return X * rhs.X + Y * rhs.Y + Z * rhs.Z;
	}

	void Vector3::Normalize()
	{
		*this /= Length();
	}

	Vector3 Vector3::Normalized() const
	{
		return Vector3(X, Y, Z) / Length();
	}

	const std::string Vector3::DebugString() const
	{
		return std::format("[Vector3] X: {}, Y: {}, Z: {}, Length: {} \n", X, Y, Z, Length());
	}
}
#pragma once

#include <format>

#include "Core.h"

namespace LGE
{
	class LGE_API Vector3
	{
	public:
		float X;
		float Y;
		float Z;

	public:
		Vector3();

		Vector3(float x, float y, float z);

		Vector3 operator+(const Vector3& v) const;

		Vector3 operator+=(const Vector3& v);

		Vector3 operator-(const Vector3& v) const;

		Vector3 operator-=(const Vector3& v);

		Vector3 operator*(const float s) const;

		Vector3 operator*=(const float s);

		Vector3 operator/(const float s) const;

		Vector3 operator/=(const float s);

		float Length() const;

		float Dot(const Vector3& rhs) const;

		void Normalize();

		Vector3 Normalized() const;

		const std::string DebugString() const;
	};
}

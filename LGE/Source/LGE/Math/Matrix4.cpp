#include "Matrix4.h"
#include "Vector3.h"

namespace LGE
{
	Matrix4::Matrix4()
	{
		M00 = 0.0f; M01 = 0.0f; M02 = 0.0f; M03 = 0.0f;
		M10 = 0.0f; M11 = 0.0f; M12 = 0.0f; M13 = 0.0f;
		M20 = 0.0f; M21 = 0.0f; M22 = 0.0f; M23 = 0.0f;
		M30 = 0.0f; M31 = 0.0f; M32 = 0.0f; M33 = 0.0f;
	}

	Matrix4 Matrix4::operator*(const Matrix4& rhs) const
	{
		// rhs stands for right hand side.
		// The result of multiplying 2 matrices is the lhs rows by rhs columns.
		Matrix4 result;
		result.M00 = M00 * rhs.M00 + M01 * rhs.M10 + M02 * rhs.M20 + M03 * rhs.M30;
		result.M01 = M00 * rhs.M01 + M01 * rhs.M11 + M02 * rhs.M21 + M03 * rhs.M31;
		result.M02 = M00 * rhs.M02 + M01 * rhs.M12 + M02 * rhs.M22 + M03 * rhs.M32;
		result.M03 = M00 * rhs.M03 + M01 * rhs.M13 + M02 * rhs.M23 + M03 * rhs.M33;
		result.M10 = M10 * rhs.M00 + M11 * rhs.M10 + M12 * rhs.M20 + M13 * rhs.M30;
		result.M11 = M10 * rhs.M01 + M11 * rhs.M11 + M12 * rhs.M21 + M13 * rhs.M31;
		result.M12 = M10 * rhs.M02 + M11 * rhs.M12 + M12 * rhs.M22 + M13 * rhs.M32;
		result.M13 = M10 * rhs.M03 + M11 * rhs.M13 + M12 * rhs.M23 + M13 * rhs.M33;
		result.M20 = M20 * rhs.M00 + M21 * rhs.M10 + M22 * rhs.M20 + M23 * rhs.M30;
		result.M21 = M20 * rhs.M01 + M21 * rhs.M11 + M22 * rhs.M21 + M23 * rhs.M31;
		result.M22 = M20 * rhs.M02 + M21 * rhs.M12 + M22 * rhs.M22 + M23 * rhs.M32;
		result.M23 = M20 * rhs.M03 + M21 * rhs.M13 + M22 * rhs.M23 + M23 * rhs.M33;
		result.M30 = M30 * rhs.M00 + M31 * rhs.M10 + M32 * rhs.M20 + M33 * rhs.M30;
		result.M31 = M30 * rhs.M01 + M31 * rhs.M11 + M32 * rhs.M21 + M33 * rhs.M31;
		result.M32 = M30 * rhs.M02 + M31 * rhs.M12 + M32 * rhs.M22 + M33 * rhs.M32;
		result.M33 = M30 * rhs.M03 + M31 * rhs.M13 + M32 * rhs.M23 + M33 * rhs.M33;
		return result;
	}

	Vector3 Matrix4::operator*(const Vector3& rhs) const
	{
		// Treat vector as a column vector 4x1 (4 lines x 1 column)
		Vector3 result;
		result.X = M00 * rhs.X + M01 * rhs.Y + M02 * rhs.Z + M03;
		result.Y = M10 * rhs.X + M11 * rhs.Y + M12 * rhs.Z + M13;
		result.Z = M20 * rhs.X + M21 * rhs.Y + M22 * rhs.Z + M23;
		return result;
	}

	const std::string Matrix4::DebugString() const
	{
		// TODO:
		return std::format("[Matrix4] TODO {} \n", 16);
	}

	Matrix4 Matrix4::Identity()
	{
		Matrix4 matrix;
		matrix.M00 = 1.0f; matrix.M01 = 0.0f; matrix.M02 = 0.0f; matrix.M03 = 0.0f;
		matrix.M10 = 0.0f; matrix.M11 = 1.0f; matrix.M12 = 0.0f; matrix.M13 = 0.0f;
		matrix.M20 = 0.0f; matrix.M21 = 0.0f; matrix.M22 = 1.0f; matrix.M23 = 0.0f;
		matrix.M30 = 0.0f; matrix.M31 = 0.0f; matrix.M32 = 0.0f; matrix.M33 = 1.0f;
		return matrix;
	}

	Matrix4 Matrix4::Translation(const Vector3& delta)
	{
		Matrix4 matrix;
		matrix.M00 = 1.0f; matrix.M01 = 0.0f; matrix.M02 = 0.0f; matrix.M03 = delta.X;
		matrix.M10 = 0.0f; matrix.M11 = 1.0f; matrix.M12 = 0.0f; matrix.M13 = delta.Y;
		matrix.M20 = 0.0f; matrix.M21 = 0.0f; matrix.M22 = 1.0f; matrix.M23 = delta.Z;
		matrix.M30 = 0.0f; matrix.M31 = 0.0f; matrix.M32 = 0.0f; matrix.M33 = 1.0f;
		return matrix;
	}

	Matrix4 Matrix4::Scaling(const Vector3& scale)
	{
		Matrix4 matrix;
		matrix.M00 = scale.X; matrix.M01 = 0.0f;    matrix.M02 = 0.0f;    matrix.M03 = 0.0f;
		matrix.M10 = 0.0f;	  matrix.M11 = scale.Y; matrix.M12 = 0.0f;    matrix.M13 = 0.0f;
		matrix.M20 = 0.0f;    matrix.M21 = 0.0f;    matrix.M22 = scale.Z; matrix.M23 = 0.0f;
		matrix.M30 = 0.0f;    matrix.M31 = 0.0f;    matrix.M32 = 0.0f;    matrix.M33 = 1.0f;
		return matrix;
	}
}

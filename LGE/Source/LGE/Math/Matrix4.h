#pragma once

#include "Core.h"

namespace LGE
{
	class Vector3;

	// Matrix layout is column-major i.e. columns are stored one after the other [Column0, Column1...]
	// That way, matrices can be right multiplied by a column vector like this: T * v.
	class LGE_API Matrix4
	{
	public:
		// Column 0
		float M00; // [0]
		float M10; // [1]
		float M20; // [2]
		float M30; // [3]
		
		// Column 1
		float M01; // [4]
		float M11; // [5]
		float M21; // [6]
		float M31; // [7]
		
		// Column 2
		float M02; // [8]
		float M12; // [9]
		float M22; // [10]
		float M32; // [11]
		
		// Column 3
		float M03; // [12]
		float M13; // [13]
		float M23; // [14]
		float M33; // [15]

	public:
		Matrix4();

		Matrix4 operator*(const Matrix4& rhs) const;

		Vector3 operator*(const Vector3& rhs) const;

		static Matrix4 Identity();

		static Matrix4 Translation(const Vector3& translation);
	};
}

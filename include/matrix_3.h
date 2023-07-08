// Author: Yossef Rubalcava

#ifndef __MATRIX3_H__
#define __MATRIX3_H__ 1

#include "vector_2.h"
#include "vector_3.h"

class Matrix3x3 {
public:

	Matrix3x3();
	Matrix3x3(float *values_array);
	Matrix3x3(float value);
	Matrix3x3(Vector3 a, Vector3 b, Vector3 c);

	Matrix3x3(const Matrix3x3& copy);
	~Matrix3x3();

	static Matrix3x3 Identity();

	Matrix3x3 Multiply(const Matrix3x3& other) const;

	float Determinant() const;

	Matrix3x3 Adjoint() const;
	bool GetInverse(Matrix3x3& out) const;
	bool Inverse();

	Matrix3x3 Transpose() const;

	static Matrix3x3 Translate(const Vector2& position);
	static Matrix3x3 Translate(float x, float y);

	Vector3 GetColum(int colum) const;
	Vector3 GetLine(int line) const;

	inline Matrix3x3 operator+(const Matrix3x3& other) const;
	inline Matrix3x3& operator+=(const Matrix3x3& other);
	inline Matrix3x3 operator+(float value) const;
	inline Matrix3x3& operator+=(float value);
	inline Matrix3x3 operator-(const Matrix3x3& other) const;
	inline Matrix3x3& operator-=(const Matrix3x3& other);
	inline Matrix3x3 operator-(float value) const;
	inline Matrix3x3& operator-=(float value);
	inline Matrix3x3 operator*(float value) const;
	inline Matrix3x3& operator*=(float value);
	inline Matrix3x3 operator/(float value) const;
	inline Matrix3x3& operator/=(float value);
	bool operator==(const Matrix3x3& other) const;
	bool operator!=(const Matrix3x3& other) const;
	inline void operator=(const Matrix3x3& other);

	float m[9];
};


inline Matrix3x3::Matrix3x3() {
}

inline Matrix3x3::Matrix3x3(float value) {
	for (int i = 0; i < 9; i++) {
		m[i] = value;
	}
}

inline Matrix3x3::Matrix3x3(float *values_array) {
	for (int i = 0; i < 9; i++) {
		m[i] = values_array[i];
	}
}

inline Matrix3x3::Matrix3x3(Vector3 a, Vector3 b, Vector3 c) {
	m[0] = a.x;
	m[1] = a.y;
	m[2] = a.z;
	m[3] = b.x;
	m[4] = b.y;
	m[5] = b.z;
	m[6] = c.x;
	m[7] = c.y;
	m[8] = c.z;
}

inline Matrix3x3::Matrix3x3(const Matrix3x3& copy) {
	for (int i = 0; i < 9; i++) {
		this->m[i] = copy.m[i];
	}
}

inline Matrix3x3::~Matrix3x3() {

}

inline Matrix3x3 Matrix3x3::operator+(const Matrix3x3& other) const {
	Matrix3x3 out;
	for (int i = 0; i < 9; i++) {
		out.m[i] = m[i] + other.m[i];
	}
	return out;
}

inline Matrix3x3& Matrix3x3::operator+=(const Matrix3x3& other) {
	for (int i = 0; i < 9; i++) {
		m[i] =m[i] + other.m[i];
	}
	return *this;
}

inline Matrix3x3 Matrix3x3::operator+(float value) const {
	Matrix3x3 out;
	for (int i = 0; i < 9; i++) {
		out.m[i] += value;
	}
	return out;
}

inline Matrix3x3& Matrix3x3::operator+=(float value) {
	for (int i = 0; i < 9; i++) {
		m[i] += value;
	}
	return *this;
}

inline Matrix3x3 Matrix3x3::operator-(const Matrix3x3& other) const {
	Matrix3x3 out;
	for (int i = 0; i < 9; i++) {
		out.m[i] = m[i] - other.m[i];
	}
	return out;
}

inline Matrix3x3& Matrix3x3::operator-=(const Matrix3x3& other) {
	for (int i = 0; i < 9; i++) {
		m[i] = m[i] - other.m[i];
	}
	return *this;
}

inline Matrix3x3 Matrix3x3::operator-(float value) const {
	Matrix3x3 out;
	for (int i = 0; i < 9; i++) {
		out.m[i] -= value;
	}
	return out;
}

inline Matrix3x3& Matrix3x3::operator-=(float value) {
	for (int i = 0; i < 9; i++) {
		m[i] -= value;
	}
	return *this;
}

inline Matrix3x3 Matrix3x3::operator*(float value) const {
	Matrix3x3 out;
	for (int i = 0; i < 9; i++) {
		out.m[i] *= value;
	}
	return out;
}

inline Matrix3x3& Matrix3x3::operator*=(float value) {
	for (int i = 0; i < 9; i++) {
		m[i] *= value;
	}
	return *this;
}

inline Matrix3x3 Matrix3x3::operator/(float value) const {
	Matrix3x3 out;
	for (int i = 0; i < 9; i++) {
		out.m[i] = m[i] / value;
	}
	return out;
}

inline Matrix3x3& Matrix3x3::operator/=(float value) {
	for (int i = 0; i < 9; i++) {
		m[i] /= value;
	}
	return *this;
}

inline bool Matrix3x3::operator==(const Matrix3x3& other) const {
	bool res = true;
	for (int i = 0; i < 9; i++) {
		if (m[i] != other.m[i]) {
			res = false;
		}
	}
	return res;
}

inline bool Matrix3x3::operator!=(const Matrix3x3& other) const {
	bool res = false;
	for (int i = 0; i < 9; i++) {
		if (m[i] != other.m[i]) { 
			res = true;
		}
	}
	return res;
}

inline void Matrix3x3::operator=(const Matrix3x3& other) {
	for (int i = 0; i < 9; i++) {
		m[i] = other.m[i];
	}
}

inline Matrix3x3 Matrix3x3::Identity(){
	return Matrix3x3(Vector3(1.0f, 0.0f, 0.0f), Vector3(0.0f, 1.0f, 0.0f), Vector3(0.0f, 0.0f, 1.0f));
}

inline float Matrix3x3::Determinant() const {
	// |m[0]  m[1]  m[2]|
	// |m[3]  m[4]  m[5]|
	// |m[6]  m[7]  m[8]|

	//
	// m[0] * m[4] * m[8] + m[3] * m[7] * m[2] + m[1] * m[5] * m[6] - (m[6] * m[4] * m[2] + m[7] * m[5] * m[0] + m[3] * m[1] * m[8])
	//

	return m[0] * m[4] * m[8] + m[3] * m[7] * m[2] + m[1] * m[5] * m[6] - (m[6] * m[4] * m[2] + m[7] * m[5] * m[0] + m[3] * m[1] * m[8]);
}

inline bool Matrix3x3::GetInverse(Matrix3x3& out) const {
	float determinant = Determinant();
	if (determinant == 0.0f) {
		return false;
	}
	out = Adjoint().Transpose() / Determinant();
	return true;
}

inline bool Matrix3x3::Inverse() {	
	return GetInverse(*this);
}

inline Matrix3x3 Matrix3x3::Translate(const Vector2& mov_vector) {	
	Matrix3x3 out;
	out.m[0] = 1.0f;
	out.m[1] = 0.0f;
	out.m[2] = mov_vector.x;
	out.m[3] = 0.0f;
	out.m[4] = 1.0f;
	out.m[5] = mov_vector.y;
	out.m[6] = 0.0f;
	out.m[7] = 0.0f;
	out.m[8] = 1.0f;
	return out;
}

inline Matrix3x3 Matrix3x3::Translate(float x, float y) {
	Matrix3x3 out;
	out.m[0] = 1.0f;
	out.m[1] = 0.0f;
	out.m[2] = x;
	out.m[3] = 0.0f;
	out.m[4] = 1.0f;
	out.m[5] = y;
	out.m[6] = 0.0f;
	out.m[7] = 0.0f;
	out.m[8] = 1.0f;
	return out;
}

inline Matrix3x3 Matrix3x3::Multiply(const Matrix3x3& other) const {
	Matrix3x3 out;
	// |m[0]  m[1]  m[2]|       |other.m[0]  other.m[1]  other.m[2]|
	// |m[3]  m[4]  m[5]|   *   |other.m[3]  other.m[4]  other.m[5]|
	// |m[6]  m[7]  m[8]|       |other.m[6]  other.m[7]  other.m[8]|

	// |m[0] * other.m[0] + m[1] * other.m[3] + m[2] * other.m[6]   m[0] * other.m[1] + m[1] * other.m[4] + m[2] * other.m[7]   m[0] * other.m[2] + m[1] * other.m[5] + m[2] * other.m[8]|
	// |m[3] * other.m[0] + m[4] * other.m[3] + m[5] * other.m[6]   m[3] * other.m[1] + m[4] * other.m[4] + m[5] * other.m[7]   m[3] * other.m[2] + m[4] * other.m[5] + m[5] * other.m[8]|
	// |m[6] * other.m[0] + m[7] * other.m[3] + m[8] * other.m[6]   m[6] * other.m[1] + m[7] * other.m[4] + m[8] * other.m[7]   m[6] * other.m[2] + m[7] * other.m[5] + m[8] * other.m[8]|
	out.m[0] = m[0] * other.m[0] + m[1] * other.m[3] + m[2] * other.m[6];
	out.m[1] = m[0] * other.m[1] + m[1] * other.m[4] + m[2] * other.m[7];
	out.m[2] = m[0] * other.m[2] + m[1] * other.m[5] + m[2] * other.m[8];
	out.m[3] = m[3] * other.m[0] + m[4] * other.m[3] + m[5] * other.m[6];
	out.m[4] = m[3] * other.m[1] + m[4] * other.m[4] + m[5] * other.m[7];
	out.m[5] = m[3] * other.m[2] + m[4] * other.m[5] + m[5] * other.m[8];
	out.m[6] = m[6] * other.m[0] + m[7] * other.m[3] + m[8] * other.m[6];
	out.m[7] = m[6] * other.m[1] + m[7] * other.m[4] + m[8] * other.m[7];
	out.m[8] = m[6] * other.m[2] + m[7] * other.m[5] + m[8] * other.m[8];
	return out;
}

inline Matrix3x3 Matrix3x3::Adjoint() const {
	// |m[0]  m[1]  m[2]|       | + - + |
	// |m[3]  m[4]  m[5]|       | - + - |
	// |m[6]  m[7]  m[8]|       | + - + |

	// |+(m[4] * m[8] - (m[7] * m[5]))   -(m[3] * m[8] - (m[6] * m[5]))   +(m[3] * m[7] - (m[6] * m[4]))|
	// |-(m[1] * m[8] - (m[7] * m[2]))   +(m[0] * m[8] - (m[6] * m[2]))   -(m[0] * m[7] - (m[6] * m[1]))|
	// |+(m[1] * m[5] - (m[4] * m[2]))   -(m[0] * m[5] - (m[3] * m[2]))   +(m[0] * m[4] - (m[3] * m[1]))|
	Matrix3x3 out;
	out.m[0] = +(m[4] * m[8] - (m[7] * m[5]));
	out.m[1] = -(m[3] * m[8] - (m[6] * m[5]));
	out.m[2] = +(m[3] * m[7] - (m[6] * m[4]));
	out.m[3] = -(m[1] * m[8] - (m[7] * m[2]));
	out.m[4] = +(m[0] * m[8] - (m[6] * m[2]));
	out.m[5] = -(m[0] * m[7] - (m[6] * m[1]));
	out.m[6] = +(m[1] * m[5] - (m[4] * m[2]));
	out.m[7] = -(m[0] * m[5] - (m[3] * m[2]));
	out.m[8] = +(m[0] * m[4] - (m[3] * m[1]));
	return out;
}

inline Matrix3x3 Matrix3x3::Transpose() const {
	Matrix3x3 out;
	out.m[0] = m[0];
	out.m[1] = m[3];
	out.m[2] = m[6];
	out.m[3] = m[1];
	out.m[4] = m[4];
	out.m[5] = m[7];
	out.m[6] = m[2];
	out.m[7] = m[5];
	out.m[8] = m[8];
	return out;
}

inline Vector3 Matrix3x3::GetColum(int colum) const {
	return Vector3(m[0 + colum], m[3 + colum], m[6 + colum]);
}

inline Vector3 Matrix3x3::GetLine(int line) const {
	// |m[0]  m[1]  m[2]|       
	// |m[3]  m[4]  m[5]|       
	// |m[6]  m[7]  m[8]|       
	return Vector3(m[0 + 3 * line], m[1 + 3 * line], m[2 + 3 * line]);
}

#endif 
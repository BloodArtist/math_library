// Author: Yossef Rubalcava

#ifndef __Vector4_H__
#define __Vector4_H__ 1

#include "vector_3.h"
#include "matrix_3.h"

class Vector4 {
public:

	Vector4();
	Vector4(float x, float y, float z, float w);
	Vector4(Vector3 a, float w);
	Vector4(float a);
	Vector4(float* values_array);
	Vector4(const Vector4& other);
	~Vector4();
	
	Vector4 operator+(const Vector4& other) const;
	Vector4 operator+(float value) const;
	void operator+=(const Vector4& other);
	void operator+=(float value);
	Vector4 operator-(const Vector4& other) const;
	Vector4 operator-(float value) const;
	void operator -=(const Vector4& other);
	void operator -=(float value);

	Vector4 operator*(float value) const;
	void operator*=(float value);
	Vector4 operator/(float value) const;
	void operator/=(float value);
	bool operator==(const Vector4& other);
	bool operator!=(const Vector4& other);
	void operator=(const Vector4& other);

	float Magnitude() const;
	void Normalize();
	Vector4 Normalized() const;
	void Scale(Vector4 scale);
	float SqrMagnitude() const;

	static float Distance(const Vector4& a, const Vector4& b);
	static float DotProduct(Vector4 a, Vector4 b);
	static Vector4 Lerp(const Vector4& a, const Vector4& b, float index);	

	static const Vector4 one;
	static const Vector4 zero;

	float x;
	float y;
	float z;
	float w;

};

inline Vector4::Vector4() { }

inline Vector4::Vector4(float x, float y, float z, float w) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

inline Vector4::Vector4(Vector3 a, float w) {
	this->x = a.x;
	this->y = a.y;
	this->z = a.z;
	this->w = w;
}

inline Vector4::Vector4(float a) {
	x = a;
	y = a;
	z = a;
	w = a;
}

inline Vector4::Vector4(float* values_array) {
	x = values_array[0];
	y = values_array[1];
	z = values_array[2];
	w = values_array[3];
}

inline Vector4::Vector4(const Vector4& other) {
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;
}

inline Vector4::~Vector4() { }

inline float Vector4::Magnitude() const{
	return sqrtf(x*x + y*y + z*z + w*w);
}

inline void Vector4::Normalize() {	
	assert(Magnitude() != 0 && "Magnitude is 0");
	float invertedMagnitude = 1 / Magnitude();
	*this *= invertedMagnitude;
}

inline Vector4 Vector4::Normalized() const {
	assert(Magnitude() != 0 && "Magnitude is 0");
	float invertedMagnitude = 1 / Magnitude();
	return Vector4(x * invertedMagnitude, y * invertedMagnitude, z * invertedMagnitude, w * invertedMagnitude);
}

inline void Vector4::Scale(Vector4 scale) {	
	x = x * scale.x;
	y = y * scale.y;
	z = z * scale.z;
	w = w * scale.w;
}

inline float Vector4::SqrMagnitude() const {
	return (x*x + y * y + z * z + w * w);
}

inline float Vector4::Distance(const Vector4& a, const Vector4& b) {
	return sqrtf((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z) + (a.w - b.w) * (a.w - b.w));
}

inline float Vector4::DotProduct(Vector4 a, Vector4 b) {
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

inline Vector4 Vector4::Lerp(const Vector4& a, const Vector4& b, float index) {	
	if (index > 1) { index = 1; }
	if (index < 0) { index = 0; }
	return Vector4(a.x + (b.x - a.x) * index, a.y + (b.y - a.y) * index, a.z + (b.z - a.z) * index, a.w + (b.w - a.w) * index);
}

inline Vector4 Vector4::operator+(const Vector4& other) const{
	return Vector4(x + other.x, y + other.y, z + other.z, w + other.w);
}

inline Vector4 Vector4::operator+(float value) const{
	return Vector4(x + value, y + value, z + value, w + value);
}

inline void Vector4::operator+=(const Vector4& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
}

inline void Vector4::operator+=(float value) {
	x += value;
	y += value;
	z += value;
	w += value;
}

inline Vector4 Vector4::operator-(const Vector4& other) const{
	return Vector4(x - other.x, y - other.y, z - other.z, w - other.w);
}

inline Vector4 Vector4::operator-(float value) const{
	return Vector4(x - value, y - value, z - value, w - value);
}

inline void Vector4::operator -=(const Vector4& other) {	
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
}

inline void Vector4::operator -=(float value) {
	x -= value;
	y -= value;
	z -= value;
	w -= value;
}

inline Vector4 Vector4::operator*(float value) const{
	return Vector4(x * value, y * value, z * value, w * value);
}

inline void Vector4::operator*=(float value) {
	x *= value;
	y *= value;
	z *= value;
	w *= value;
}

inline Vector4 Vector4::operator/(float value) const{
	return Vector4(x / value, y / value, z / value, w / value);
}

inline void Vector4::operator/=(float value) {
	x /= value;
	y /= value;
	z /= value;
	w /= value;
}

inline bool Vector4::operator==(const Vector4& other) {
	return x == other.x && y == other.y && z == other.z && w == other.w;
}
inline bool Vector4::operator!=(const Vector4& other) {
	return x != other.x && y != other.y && z != other.z && w != other.w;
}
inline void Vector4::operator=(const Vector4& other) {
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;
}

#endif 

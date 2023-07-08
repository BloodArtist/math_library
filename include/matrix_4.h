// Author: Yossef Rubalcava

#ifndef __MATRIX4_H__
#define __MATRIX4_H__ 1

#include "vector_3.h"
#include "vector_4.h"
#include "matrix_3.h"

class Matix4x4{
 public:

  Matix4x4();
  Matix4x4(float a[16]);
	Matix4x4(const float a[16]);
  Matix4x4(float value);
  Matix4x4(const Matix4x4& copy);
  ~Matix4x4();

  Matix4x4 Identity() const;
  Matix4x4 Multiply(const Matix4x4& other) const;

  float Determinant() const;
  Matix4x4 Adjoint() const;
  bool GetInverse(Matix4x4& out) const;
  bool Inverse();

  Matix4x4 Transpose() const;


  static Matix4x4 Translate(const Vector3& distance);
  static Matix4x4 Translate(float x, float y, float z);

  static Matix4x4 Scale(const Vector3& scale);
  static Matix4x4 Scale(float x, float y, float z);

  static Matix4x4 RotateX(float radians);
  static Matix4x4 RotateY(float radians);
  static Matix4x4 RotateZ(float radians);

  static Matix4x4 GetTransform(const Vector3& translate, const Vector3& scale,
                      float rotateX, float rotateY, float rotateZ);

  static Matix4x4 GetTransform(float trans_x, float trans_y, float trans_z,
                      float scale_x, float scale_y, float scale_Z,
                      float rotateX, float rotateY, float rotateZ);

  Matix4x4 PerspectiveMatrix(float fov, float aspect,
	  float near, float far) const;

  Matix4x4 OrthoMatrix(float right, float left, float top, float valueottom,
	  float near, float far) const;

  Vector4 GetColum(int colum) const;
  Vector4 GetLine(int line) const;

  Matix4x4 operator+(const Matix4x4& other) const;
  Matix4x4& operator+=(const Matix4x4& other);
  Matix4x4 operator+(float value) const;
  Matix4x4& operator+=(float value);
  Matix4x4 operator-(const Matix4x4& other) const;
  Matix4x4& operator-=(const Matix4x4& other);
  Matix4x4 operator-(float value) const;
  Matix4x4& operator-=(float value);
  Matix4x4& operator*=(float value);
  Matix4x4 operator*(float value) const;
  Matix4x4& operator/=(float value);
  Matix4x4 operator/(float value) const;
  bool operator==(const Matix4x4& other);
  bool operator!=(const Matix4x4& other);
  void operator=(const Matix4x4& other);

  float m[16];
};


inline Matix4x4::Matix4x4() {

}

inline Matix4x4::Matix4x4(float array[16]) {
	for (int i = 0; i < 16; i++) {
		m[i] = array[i];
	}
}

inline Matix4x4::Matix4x4(const float array[16]) {
	for (int i = 0; i < 16; i++) {
		m[i] = array[i];
	}
}

inline Matix4x4::Matix4x4(float value) {
	for (int i = 0; i < 16; i++) {
		m[i] = value;
	}
}

inline Matix4x4::Matix4x4(const Matix4x4& copy) {
	for (int i = 0; i < 16; i++) {
		m[i] = copy.m[i];
	}
}

inline Matix4x4::~Matix4x4() {

}

inline Matix4x4 Matix4x4::Identity() const {
	//|m[0]   m[1]   m[2]   m[3]|
	//|m[4]   m[5]   m[6]   m[7]|
	//|m[8]   m[9]   m[10]  m[11]|
	//|m[12]  m[13]  m[14]  m[15]|
	Matix4x4 out;
	out.m[0] = 1.0f;
	out.m[1] = 0.0f;
	out.m[2] = 0.0f;
	out.m[3] = 0.0f;
	out.m[4] = 0.0f;
	out.m[5] = 1.0f;
	out.m[6] = 0.0f;
	out.m[7] = 0.0f;
	out.m[8] = 0.0f;
	out.m[9] = 0.0f;
	out.m[10] = 1.0f;
	out.m[11] = 0.0f;
	out.m[12] = 0.0f;
	out.m[13] = 0.0f;
	out.m[14] = 0.0f;
	out.m[15] = 1.0f;
	return out;
}

inline Matix4x4 Matix4x4::Multiply(const Matix4x4& other)const  {
//|m[0]   m[1]   m[2]    m[3]|		 |other.m[0]   other.m[1]   other.m[2]   other.m[3]|
//|m[4]   m[5]   m[6]    m[7]|		 |other.m[4]   other.m[5]   other.m[6]   other.m[7]|
//|m[8]   m[9]   m[10]  m[11]|	*  |other.m[8]   other.m[9]   other.m[10]  other.m[11]|
//|m[12]  m[13]  m[14]  m[15]|		 |other.m[12]  other.m[13]  other.m[14]  other.m[15]|
	Matix4x4 out;
	out.m[0] = m[0] * other.m[0] + m[1] * other.m[4] + m[2] * other.m[8] + m[3] * other.m[12];
	out.m[1] = m[0] * other.m[1] + m[1] * other.m[5] + m[2] * other.m[9] + m[3] * other.m[13];
	out.m[2] = m[0] * other.m[2] + m[1] * other.m[6] + m[2] * other.m[10] + m[3] * other.m[14];
	out.m[3] = m[0] * other.m[3] + m[1] * other.m[7] + m[2] * other.m[11] + m[3] * other.m[15];
	out.m[4] = m[4] * other.m[0] + m[5] * other.m[4] + m[6] * other.m[8] + m[7] * other.m[12];
	out.m[5] = m[4] * other.m[1] + m[5] * other.m[5] + m[6] * other.m[9] + m[7] * other.m[13];
	out.m[6] = m[4] * other.m[2] + m[5] * other.m[6] + m[6] * other.m[10] + m[7] * other.m[14];
	out.m[7] = m[4] * other.m[3] + m[5] * other.m[7] + m[6] * other.m[11] + m[7] * other.m[15];
	out.m[8] = m[8] * other.m[0] + m[9] * other.m[4] + m[10] * other.m[8] + m[11] * other.m[12];
	out.m[9] = m[8] * other.m[1] + m[9] * other.m[5] + m[10] * other.m[9] + m[11] * other.m[13];
	out.m[10] = m[8] * other.m[2] + m[9] * other.m[6] + m[10] * other.m[10] + m[11] * other.m[14];
	out.m[11] = m[8] * other.m[3] + m[9] * other.m[7] + m[10] * other.m[11] + m[11] * other.m[15];
	out.m[12] = m[12] * other.m[0] + m[13] * other.m[4] + m[14] * other.m[8] + m[15] * other.m[12];
	out.m[13] = m[12] * other.m[1] + m[13] * other.m[5] + m[14] * other.m[9] + m[15] * other.m[13];
	out.m[14] = m[12] * other.m[2] + m[13] * other.m[6] + m[14] * other.m[10] + m[15] * other.m[14];
	out.m[15] = m[12] * other.m[3] + m[13] * other.m[7] + m[14] * other.m[11] + m[15] * other.m[15];
	return out;
}


inline float Matix4x4::Determinant() const {
	//|m[0]   m[1]   m[2]    m[3]|      |+ - + -|
	//|m[4]   m[5]   m[6]    m[7]|      |- + - +|
	//|m[8]   m[9]   m[10]  m[11]|      |+ - + -|
	//|m[12]  m[13]  m[14]  m[15]|      |- + - +|

	float first = m[0] * (m[5] * m[10] * m[15] + m[6] * m[11] * m[13] + m[9] * m[14] * m[7] -
							         (m[13] * m[10] * m[7] + m[9] * m[6] * m[15] + m[14] * m[11] * m[5]));

	float second = -m[4] * (m[1] * m[10] * m[15] + m[2] * m[11] * m[13] + m[9] * m[14] * m[3] -
											  (m[13] * m[10] * m[3] + m[9] * m[2] * m[15] + m[14] * m[11] * m[1]));

	float third = m[8] * (m[1] * m[6] * m[15] + m[2] * m[7] * m[13] + m[5] * m[14] * m[3] -
								       (m[13] * m[6] * m[3] + m[5] * m[2] * m[15] + m[14] * m[7] * m[1]));

	float fourth = -m[12] * (m[1] * m[6] * m[11] + m[2] * m[7] * m[9] + m[5] * m[10] * m[3] -
		                      (m[9] * m[6] * m[3] + m[5] * m[2] * m[11] + m[10] * m[7] * m[1]));

	return first + second + third + fourth;
}


inline Matix4x4 Matix4x4::Adjoint() const {
	//|m[0]   m[1]   m[2]    m[3]|      |+ - + -|
	//|m[4]   m[5]   m[6]    m[7]|      |- + - +|
	//|m[8]   m[9]   m[10]  m[11]|      |+ - + -|
	//|m[12]  m[13]  m[14]  m[15]|      |- + - +|
	Matix4x4 result;
	result.m[0] = +(m[5] * m[10] * m[15] + m[6] * m[11] * m[13] + m[9] * m[14] * m[7] -
								 (m[13] * m[10] * m[7] + m[9] * m[6] * m[15] + m[14] * m[11] * m[5]));

	result.m[1] = -(m[4] * m[10] * m[15] + m[6] * m[11] * m[12] + m[8] * m[14] * m[7] -
								 (m[12] * m[10] * m[7] + m[8] * m[6] * m[15] + m[14] * m[11] * m[4]));

	result.m[2] = +(m[4] * m[9] * m[15] + m[5] * m[11] * m[12] + m[8] * m[13] * m[7] -
								 (m[12] * m[9] * m[7] + m[8] * m[5] * m[15] + m[13] * m[11] * m[4]));

	result.m[3] = -(m[4] * m[9] * m[14] + m[5] * m[10] * m[12] + m[8] * m[13] * m[6] -
		             (m[12] * m[9] * m[6] + m[8] * m[5] * m[14] + m[13] * m[10] * m[4]));

	result.m[4] = -(m[1] * m[10] * m[15] + m[2] * m[11] * m[13] + m[9] * m[14] * m[3] -
								 (m[13] * m[10] * m[3] + m[9] * m[2] * m[15] + m[14] * m[11] * m[1]));

	result.m[5] = +(m[0] * m[10] * m[15] + m[2] * m[11] * m[12] + m[8] * m[14] * m[3] -
		             (m[12] * m[10] * m[3] + m[8] * m[2] * m[15] + m[14] * m[11] * m[0]));

	result.m[6] = -(m[0] * m[9] * m[15] + m[1] * m[11] * m[12] + m[8] * m[13] * m[3] -
		             (m[12] * m[9] * m[3] + m[8] * m[1] * m[15] + m[13] * m[11] * m[0]));

	result.m[7] = +(m[0] * m[9] * m[14] + m[1] * m[10] * m[12] + m[8] * m[13] * m[2] -
		             (m[12] * m[9] * m[2] + m[8] * m[1] * m[14] + m[13] * m[10] * m[0]));

	result.m[8] = +(m[1] * m[6] * m[15] + m[2] * m[7] * m[13] + m[5] * m[14] * m[3] -
								 (m[13] * m[6] * m[3] + m[5] * m[2] * m[15] + m[14] * m[7] * m[1]));

	result.m[9] = -(m[0] * m[6] * m[15] + m[2] * m[7] * m[12] + m[4] * m[14] * m[3] -
		             (m[12] * m[6] * m[3] + m[4] * m[2] * m[15] + m[14] * m[7] * m[0]));

	result.m[10] = +(m[0] * m[5] * m[15] + m[1] * m[7] * m[12] + m[4] * m[13] * m[3] -
		              (m[12] * m[5] * m[3] + m[4] * m[1] * m[15] + m[13] * m[7] * m[0]));

	result.m[11] = -(m[0] * m[5] * m[14] + m[1] * m[6] * m[12] + m[4] * m[13] * m[2] -
		              (m[12] * m[5] * m[2] + m[4] * m[1] * m[14] + m[13] * m[6] * m[0]));

	result.m[12] = -(m[1] * m[6] * m[11] + m[2] * m[7] * m[9] + m[5] * m[10] * m[3] -
								  (m[9] * m[6] * m[3] + m[5] * m[2] * m[11] + m[10] * m[7] * m[1]));

	result.m[13] = +(m[0] * m[6] * m[11] + m[2] * m[7] * m[8] + m[4] * m[10] * m[3] -
		              (m[8] * m[6] * m[3] + m[4] * m[2] * m[11] + m[10] * m[7] * m[0]));

	result.m[14] = -(m[0] * m[5] * m[11] + m[1] * m[7] * m[8] + m[4] * m[9] * m[3] -
		              (m[8] * m[5] * m[3] + m[4] * m[1] * m[11] + m[9] * m[7] * m[0]));

	result.m[15] = +(m[0] * m[5] * m[10] + m[1] * m[6] * m[8] + m[4] * m[9] * m[2] -
		              (m[8] * m[5] * m[2] + m[4] * m[1] * m[10] + m[9] * m[6] * m[0]));
	//|m[0]   m[1]   m[2]    m[3]|      |+ - + -|
	//|m[4]   m[5]   m[6]    m[7]|      |- + - +|
	//|m[8]   m[9]   m[10]  m[11]|      |+ - + -|
	//|m[12]  m[13]  m[14]  m[15]|      |- + - +|
	return result;
}

inline bool Matix4x4::Inverse() {

	return GetInverse(*this);
}

inline bool Matix4x4::GetInverse(Matix4x4& out) const {
	float determinant = Determinant();
	if (determinant == 0.0f) {
		return false;
	}
	out = Adjoint().Transpose() / Determinant();
	return true;

}

inline Matix4x4 Matix4x4::Transpose() const {
	Matix4x4 out;
	out.m[0] = m[0];
	out.m[1] = m[4];
	out.m[2] = m[8];
	out.m[3] = m[12];
	out.m[4] = m[1];
	out.m[5] = m[5];
	out.m[6] = m[9];
	out.m[7] = m[13];
	out.m[8] = m[2];
	out.m[9] = m[6];
	out.m[10] = m[10];
	out.m[11] = m[14];
	out.m[12] = m[3];
	out.m[13] = m[7];
	out.m[14] = m[11];
	out.m[15] = m[15];
	//|m[0]   m[1]   m[2]    m[3]|
	//|m[4]   m[5]   m[6]    m[7]|
	//|m[8]   m[9]   m[10]  m[11]|
	//|m[12]  m[13]  m[14]  m[15]|
	return out;
}

inline Matix4x4 Matix4x4::Translate(const Vector3& distance){
	Matix4x4 out;
	out.m[0] = 1.0f;
	out.m[1] = 0.0f;
	out.m[2] = 0.0f;
	out.m[3] = 0.0f;

	out.m[4] = 0.0f;
	out.m[5] = 1.0f;
	out.m[6] = 0.0f;
	out.m[7] = 0.0f;

	out.m[8] = 0.0f;
	out.m[9] = 0.0f;
	out.m[10] = 1.0f;
	out.m[11] = 0.0f;

	out.m[12] = distance.x;
	out.m[13] = distance.y;
	out.m[14] = distance.z;
	out.m[15] = 1.0f;
	return out;
}

inline Matix4x4 Matix4x4::Translate(float x, float y, float z){
	Matix4x4 out;
	out.m[0] = 1.0f;
	out.m[1] = 0.0f;
	out.m[2] = 0.0f;
	out.m[3] = 0.0f;
	
	out.m[4] = 0.0f;
	out.m[5] = 1.0f;
	out.m[6] = 0.0f;
	out.m[7] = 0.0f;
	
	out.m[8] = 0.0f;
	out.m[9] = 0.0f;
	out.m[10] = 1.0f;
	out.m[11] = 0.0f;
	
	out.m[12] = x;
	out.m[13] = y;
	out.m[14] = z;
	out.m[15] = 1.0f;
	return out;
}

inline Matix4x4 Matix4x4::Scale(const Vector3& scale){
	Matix4x4 out;
	out.m[0] = scale.x;
	out.m[1] = 0.0f;
	out.m[2] = 0.0f;
	out.m[3] = 0.0f;

	out.m[4] = 0.0f;
	out.m[5] = scale.y;
	out.m[6] = 0.0f;
	out.m[7] = 0.0f;

	out.m[8] = 0.0f;
	out.m[9] = 0.0f;
	out.m[10] = scale.z;
	out.m[11] = 0.0f;

	out.m[12] = 0.0f;
	out.m[13] = 0.0f;
	out.m[14] = 0.0f;
	out.m[15] = 1.0f;
	return out;
}

inline Matix4x4 Matix4x4::Scale(float x, float y, float z){
	Matix4x4 out;
	out.m[0] = x;
	out.m[1] = 0.0f;
	out.m[2] = 0.0f;
	out.m[3] = 0.0f;

	out.m[4] = 0.0f;
	out.m[5] = y;
	out.m[6] = 0.0f;
	out.m[7] = 0.0f;

	out.m[8] = 0.0f;
	out.m[9] = 0.0f;
	out.m[10] = z;
	out.m[11] = 0.0f;

	out.m[12] = 0.0f;
	out.m[13] = 0.0f;
	out.m[14] = 0.0f;
	out.m[15] = 1.0f;
	return out;
}

inline Matix4x4 Matix4x4::RotateX(float radians){
	Matix4x4 out;
	float cos = cosf(radians);
	float sin = sinf(radians);
	out.m[0] = 1.0f;
	out.m[1] = 0.0f;
	out.m[2] = 0.0f;
	out.m[3] = 0.0f;
	out.m[4] = 0.0f;
	out.m[5] = cos;
	out.m[6] = -sin;
	out.m[7] = 0.0f;
	out.m[8] = 0.0f;
	out.m[9] = sin;
	out.m[10] = cos;
	out.m[11] = 0.0f;
	out.m[12] = 0.0f;
	out.m[13] = 0.0f;
	out.m[14] = 0.0f;
	out.m[15] = 1.0f;
	//|m[0]   m[1]   m[2]    m[3]|
	//|m[4]   m[5]   m[6]    m[7]|
	//|m[8]   m[9]   m[10]  m[11]|
	//|m[12]  m[13]  m[14]  m[15]|
	return out;
}

inline Matix4x4 Matix4x4::RotateY(float radians){
	Matix4x4 out;
	float cos = cosf(radians);
	float sin = sinf(radians);
	out.m[0] = cos;
	out.m[1] = 0.0f;
	out.m[2] = sin;
	out.m[3] = 0.0f;
	out.m[4] = 0.0f;
	out.m[5] = 1.0f;
	out.m[6] = 0.0f;
	out.m[7] = 0.0f;
	out.m[8] = -sin;
	out.m[9] = 0.0f;
	out.m[10] = cos;
	out.m[11] = 0.0f;
	out.m[12] = 0.0f;
	out.m[13] = 0.0f;
	out.m[14] = 0.0f;
	out.m[15] = 1.0f;
	//|m[0]   m[1]   m[2]    m[3]|
	//|m[4]   m[5]   m[6]    m[7]|
	//|m[8]   m[9]   m[10]  m[11]|
	//|m[12]  m[13]  m[14]  m[15]|
	return out;
}

inline Matix4x4 Matix4x4::RotateZ(float radians) {
	Matix4x4 out;
	float cos = cosf(radians);
	float sin = sinf(radians);
	out.m[0] = cos;
	out.m[1] = -sin;
	out.m[2] = 0.0f;
	out.m[3] = 0.0f;
	out.m[4] = sin;
	out.m[5] = cos;
	out.m[6] = 0.0f;
	out.m[7] = 0.0f;
	out.m[8] = 0.0f;
	out.m[9] = 0.0f;
	out.m[10] = 1.0f;
	out.m[11] = 0.0f;
	out.m[12] = 0.0f;
	out.m[13] = 0.0f;
	out.m[14] = 0.0f;
	out.m[15] = 1.0f;
	//|m[0]   m[1]   m[2]    m[3]|
	//|m[4]   m[5]   m[6]    m[7]|
	//|m[8]   m[9]   m[10]  m[11]|
	//|m[12]  m[13]  m[14]  m[15]|
	return out;
}

inline Matix4x4 Matix4x4::GetTransform(const Vector3& translate,
								const Vector3& scale,
								float rotateX, float rotateY,
								float rotateZ)   {
	Matix4x4 out;
	out = out.Identity();
	out = out.Multiply(out.Translate(translate));
	out = out.Multiply(out.RotateX(rotateX));
	out = out.Multiply(out.RotateY(rotateY));
	out = out.Multiply(out.RotateZ(rotateZ));
	out = out.Multiply(out.Scale(scale));
	return out;
}

inline Matix4x4 Matix4x4::GetTransform(float trans_x, float trans_y, float trans_z,
	float scale_x, float scale_y, float scale_Z,
	float rotateX, float rotateY, float rotateZ)  {
	
	Matix4x4 out;
	out = out.Identity();
	out = out.Multiply(out.Translate(trans_x, trans_y, trans_z));
	out = out.Multiply(out.RotateX(rotateX));
	out = out.Multiply(out.RotateY(rotateY));
	out = out.Multiply(out.RotateZ(rotateZ));
	out = out.Multiply(out.Scale(scale_x, scale_y, scale_Z));
	return out;
}

inline Vector4 Matix4x4::GetColum(int colum) const {
	return Vector4(m[0 + colum], m[4 + colum], m[8 + colum], m[12 + colum]);
	//|m[0]   m[1]   m[2]    m[3]|
	//|m[4]   m[5]   m[6]    m[7]|
	//|m[8]   m[9]   m[10]  m[11]|
	//|m[12]  m[13]  m[14]  m[15]|
}

inline Vector4 Matix4x4::GetLine(int line) const {
	return Vector4(m[0 + 4 * line], m[1 + 4 * line], m[2 + 4 * line], m[3 + 4 * line]);
}

inline Matix4x4 Matix4x4::PerspectiveMatrix(float fov, float aspect,
	float near, float far) const {
	Matix4x4 out;
		out.m[0] = 1 / (aspect * tanf(fov * 0.5)); out.m[1] = 0; out.m[2] = 0; out.m[3] = 0;
		out.m[4] = 0; out.m[5] = 1 / (tanf(fov * 0.5)); out.m[6] = 0; out.m[7] = 0;
		out.m[8] = 0; out.m[9] = 0; out.m[10] = -(far + near)/(far - near); out.m[11] = -(2 * far * near)/(far - near);
		out.m[12] = 0; out.m[13] = 0; out.m[14] = -1; out.m[15] = 0;
	return out;
}

inline Matix4x4 Matix4x4::OrthoMatrix(float right, float left, float top, float valueottom,
	float near, float far) const {
	Matix4x4 out;
	out.m[0] = 2 /(right - left); out.m[1] = 0; out.m[2] = 0; out.m[3] = -(right + left)/(right - left);
	out.m[4] = 0; out.m[5] = 2/(top - valueottom); out.m[6] = 0; out.m[7] = -(top + valueottom)/(top - valueottom);
	out.m[8] = 0; out.m[9] = 0; out.m[10] = -2/(far - near); out.m[11] = -(far + near)/(far - near);
	out.m[12] = 0; out.m[13] = 0; out.m[14] = 0; out.m[15] = 1;
	return out;
}



inline Matix4x4 Matix4x4::operator+(const Matix4x4& other) const {
	Matix4x4 out;
	for (int i = 0; i < 16; i++) {
		out.m[i] = m[i] + other.m[i];
	}
	return out;
}

inline Matix4x4& Matix4x4::operator+=(const Matix4x4& other) {
	for (int i = 0; i < 16; i++) {
		m[i] = m[i] + other.m[i];
	}
	return *this;
}

inline Matix4x4 Matix4x4::operator+(float value) const {
	Matix4x4 out;
	for (int i = 0; i < 16; i++) {
		out.m[i] += value;
	}
	return out;
}

inline Matix4x4& Matix4x4::operator+=(float value) {	
	for (int i = 0; i < 16; i++) {
		m[i] += value;
	}
	return *this;
}


inline Matix4x4 Matix4x4::operator-(const Matix4x4& other) const  {
	Matix4x4 out;
	for (int i = 0; i < 16; i++) {
		out.m[i] = m[i] - other.m[i];
	}
	return out;
}

inline Matix4x4& Matix4x4::operator-=(const Matix4x4& other) {
	for (int i = 0; i < 16; i++) {
		m[i] = m[i] - other.m[i];
	}
	return *this;
}

inline Matix4x4 Matix4x4::operator-(float value) const  {
	Matix4x4 out;
	for (int i = 0; i < 16; i++) {
		out.m[i] -= value;
	}
	return out;
}

inline Matix4x4& Matix4x4::operator-=(float value) {
	for (int i = 0; i < 16; i++) {
		m[i] -= value;
	}
	return *this;
}

inline Matix4x4& Matix4x4::operator*=(float value) {
	for (int i = 0; i < 16; i++) {
		m[i] *= value;
	}
	return *this;
}

inline Matix4x4 Matix4x4::operator*(float value) const  {
	Matix4x4 out;
	for (int i = 0; i < 16; i++) {
		out.m[i] *= value;
	}
	return out;
}

inline Matix4x4& Matix4x4::operator/=(float value) {
	for (int i = 0; i < 16; i++) {
		m[i] /= value;
	}
	return *this;
}

inline Matix4x4 Matix4x4::operator/(float value) const {
	Matix4x4 out;
	for (int i = 0; i < 16; i++) {
		out.m[i] = m[i] / value;
	}
	return out;
}

inline bool Matix4x4::operator==(const Matix4x4& other) {
	bool res = true;
	for (int i = 0; i < 16; i++) {
		if (m[i] != other.m[i]) {
			res = false;
		}
	}
	return res;
}

inline bool Matix4x4::operator!=(const Matix4x4& other) {
	bool res = false;
	for (int i = 0; i < 16; i++) {
		if (m[i] != other.m[i]) { 
			res = true;
		}
	}
	return res;
}

inline void Matix4x4::operator=(const Matix4x4& other) {
	for (int i = 0; i < 16; i++) {
		m[i] = other.m[i];
	}
}

#endif

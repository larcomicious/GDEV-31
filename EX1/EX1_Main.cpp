#include <iostream>
#include <cmath>


/**
 * Struct containing data for a 3D vector
 */
struct Vector3 {
public:
	/**
	 * X component
	 */
	float x;
	
	/**
	 * Y component
	 */
	float y;
	
	/**
	 * Z component
	 */
	float z;
	
	/**
	 * Constructor
	 * @param newX - New x component
	 * @param newY - New y component
	 * @param newZ - New z component
	 */
	Vector3(float newX, float newY, float newZ) {
		x = newX;
		y = newY;
		z = newZ;
	}
	
	/**
	 * Constructor
	 */
	Vector3() : Vector3(0.0f, 0.0f, 0.0f) {}
	/**
	 * Task 1: negative() member function
	 */
	Vector3 negative() const {
		return Vector3(-x, -y, -z);		
	}
	/**
	 * Overloaded "-" (unary) operator 
	 */
	Vector3 operator-() const {
		return negative();
	}
	/**
	 * Task 2: magnitude() member function
	 */
	float magnitude() const {
		return sqrt(x * x + y * y + z * z);
	}
	/**
	 * Task 3: squaredMagnitude() member function
	 */
	float squaredMagnitude() const {
		float mag = magnitude();
		return mag * mag;
	}
	/**
	 * Task 4: normalized() member function
	 */
	Vector3 normalized() const {
		float mag = magnitude();
		if (mag <= 0)
			return Vector3(0, 0, 0);
		return Vector3(x / mag, y / mag, z / mag);
	}
	/**
	 * Task 5: add() static member function
	 */
	static Vector3 add(const Vector3& a, const Vector3& b) {
		return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
	}
	/**
	 * Overloaded "+" operator 
	 */
	Vector3 operator+(const Vector3& other) const {
		return add(*this, other);
	}
	/**
	 * Task 6: subtract() static member function
	 */
	static Vector3 subtract(const Vector3& a, const Vector3& b) {
		return Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
	}
	/**
	 * Overloaded "-" operator 
	 */
	Vector3 operator-(const Vector3& other) const {
		return subtract(*this, other);
	}
	/**
	 * Task 7: multiply() static member function
	 */
	static Vector3 multiply(const Vector3& v, float s) {
		return Vector3(v.x * s, v.y * s, v.z * s);
	}
	/**
	 * Overloaded "*" operator. Handles Vector3 * scalar
	 */
	Vector3 operator*(float s) const {
		return multiply(*this, s);
	}
	/**
	 * Overloaded "*" operator. Handles scalar * Vector3
	 */
	friend Vector3 operator*(float s, const Vector3& v) {
		return multiply(v, s);
	}
	/**
	 * Task 8: dot() static member function
	 */
	static float dot(const Vector3& a, const Vector3& b) {
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}
	/**
	 * Task 9: cross() static member function
	 */
	static Vector3 cross(const Vector3& a, const Vector3& b) {
		return Vector3(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
	}
	/**
	 * Task 10: project() static member function
	 */
	static Vector3 project(const Vector3& a, const Vector3& b) {
		if (b.magnitude() <= 0)
			return Vector3(0, 0, 0);
		return (dot(a, b) / b.squaredMagnitude()) * b;
	}
	/**
	 * Task 11: reflect() static member function
	 */
	static Vector3 reflect(const Vector3& a, const Vector3& b) {
		return a - 2 * project(a, b);
	}
	/**
	 * Overloaded "<<" operator
	 */
	friend std::ostream& operator<<(std::ostream& os, const Vector3& v) {
		os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
		return os;
	}
};

int main()
{
	/**
	 * Task 12: Read input from standard input, and output
	 * to standard output based on the sample output.
	 */
	float a, b, c, d, e, f, g;
	std::cin >> a >> b >> c >> d >> e >> f >> g;
	
	const Vector3 A(a, b, c);
	const Vector3 B(d, e, f);
	float S = g;

	std::cout << "A = " << A << std::endl;
	std::cout << "B = " << B << std::endl;
	std::cout << "S = " << S << std::endl;

	const Vector3 negA = -A;
	const Vector3 negB = -B;

	std::cout << "-A = " << negA << std::endl;
	std::cout << "-B = " << negB << std::endl;

	std::cout << "Squared magnitude of A = " << A.squaredMagnitude() << std::endl;
	std::cout << "Magnitude of A = " << A.magnitude() << std::endl;
	std::cout << "Squared magnitude of B = " << B.squaredMagnitude() << std::endl;
	std::cout << "Magnitude of B = " << B.magnitude() << std::endl;

	const Vector3 normA = A.normalized(); 
	const Vector3 normB = B.normalized(); 
	std::cout << "A normalized = " << normA << std::endl;
	std::cout << "B normalized = " << normB << std::endl;

	std::cout << "A + B = " << A + B << std::endl;
	std::cout << "A - B = " <<  A - B << std::endl;
	std::cout << "A * S = " <<  A * S << std::endl;
	std::cout << "A dot B = " <<  Vector3::dot(A, B) << std::endl;
	std::cout << "A cross B = " <<  Vector3::cross(A, B) << std::endl;
	std::cout << "Projection of A onto B = " <<  Vector3::project(A, B) << std::endl;
	std::cout << "Reflection of A along B = " <<  Vector3::reflect(A, B) << std::endl;

	return 0;
}


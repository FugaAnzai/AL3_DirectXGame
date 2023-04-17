#pragma once

/// <summary>
/// 3次元ベクトル
/// </summary>
struct Vector3 final {
	float x;
	float y;
	float z;

public:
	Vector3();
	Vector3(float x, float y, float z);
	static Vector3 Add(Vector3 v1, Vector3 v2);
	static Vector3 Subtract(Vector3 v1, Vector3 v2);
	static Vector3 Multiply(float scalar, Vector3 v2);
	static float Dot(Vector3 v1, Vector3 v2);
	static float Length(Vector3 v);
	static Vector3 Normalize(Vector3 v);

};
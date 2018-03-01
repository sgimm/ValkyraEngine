#pragma once

typedef struct Vector3
{
public:
	float x;
	float y;
	float z;

	Vector3()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	float Length()
	{
		//length = |vector|
		float vx = x;
		float vy = y;
		float vz = z;

		float l = 0.0f;

		_asm
		{
			movlpd xmm0, [vx]
			mulps xmm0, xmm0
			movupd xmm1, xmm0

			movlpd xmm0, [vy]
			mulps xmm0, xmm0
			movupd xmm2, xmm0

			movlpd xmm0, [vz]
			mulps xmm0, xmm0

			addps xmm1, xmm2
			addps xmm0, xmm1

			sqrtss xmm0, xmm0
			movlpd[l], xmm0
		}
		return l;
	}

	void Add(Vector3 v)
	{
		float vx2 = v.x;
		float vy2 = v.y;
		float vz2 = v.z;
		float vx = x;
		float vy = y;
		float vz = z;

		_asm
		{
			movlpd xmm0, [vx]
			movlpd xmm1, [vx2]
			addps xmm0, xmm1
			movlpd[vx], xmm0

			movlpd xmm0, [vy]
			movlpd xmm1, [vy2]
			addps xmm0, xmm1
			movlpd[vy], xmm0

			movlpd xmm0, [vz]
			movlpd xmm1, [vz2]
			addps xmm0, xmm1
			movlpd[vz], xmm0
		}
		x = vx;
		y = vy;
		z = vz;
	}

	Vector3 Normalize()
	{
		// NormalizedVector = Vector/|Vector|
		float vx = x;
		float vy = y;
		float vz = z;
		float resx = 0;
		float resy = 0;
		float resz = 0;
		float l = Length();
		__asm
		{
			movlpd xmm0, [l]
			movlpd xmm1, [vx]
			divss xmm1, xmm0
			movlpd[resx], xmm1

			movlpd xmm1, [vy]
			divss xmm1, xmm0
			movlpd resy, xmm1

			movlpd xmm1, [vz]
			divss xmm1, xmm0
			movlpd resz, xmm1
		}
		Vector3 res;
		res.x = resx;
		res.y = resy;
		res.z = resz;
	}

	static Vector3 GetDifferenceVector(float x1, float y1, float z1, float x2, float y2, float z2)
	{
		Vector3 _retval;
		float resx = 0;
		float resy = 0;

		_asm
		{
			movlpd xmm0, [x1]
			subss xmm0, [x2]
			movlpd resx, xmm0
			movlpd xmm0, [y1]
			subss xmm0, [y2]
			movlpd resy, xmm0
		}
		_retval.x = resx;
		_retval.y = resy;
		return _retval;
	}

	static Vector3 GetDifferenceVector(Vector3 p1, Vector3 p2)
	{

	}

}Vector3, LPVector3;

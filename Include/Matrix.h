//matrix header file by Hana Makhlouf as part of H62PEP

class Matrix {
public:
	int N;
	Matrix();
	Matrix(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33); //initialise

	void SetMatrix(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33);
	void print();

	void identity(Matrix m);
	void rotation(Matrix m);
	void det(Matrix m);
	void inverse(Matrix m);
	void displayMatrix(int mat[N][N]);
	void rotateMatrix(int mat[][N]);

private:
	float m11;
	float m12;
	float m13;
	float m21;
	float m22;
	float m23;
	float m31;
	float m32;
	float m33;

};
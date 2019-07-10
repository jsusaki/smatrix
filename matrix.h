/*
	Simple Matrix Library

	Vector class
		Scalar Multiplication
		Scalar Division
		Vector Addition
		Vector Subtraction
		Vector Multiplication

	Matrix class
		Matrix Addition
		Matrix Subtraction
		Matrix Multiplication
			Element-Wise Multiplication (Hadamard Product)
			Matrix-Vector
			Matrix-Matrix
		Matrix Division

		Transpose
		Inverse
		Identity
		Trace

	Author: femto
	Last Updated: 16/04/2019
	Created: 15/04/2019
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


class Matrix
{
private:
	vector<vector<float>> m_matrix;
	int m_row;
	int m_col;

public:
	// Constructors
	Matrix() : m_matrix(0), m_row(0), m_col(0) {}
	Matrix(const Matrix& m) : m_matrix(m.m_matrix), m_row(m.m_row), m_col(m.m_col) {}
	Matrix(const vector<vector<float>>& m) : m_matrix(m), m_row(m.size()), m_col(m[0].size()) {}
	Matrix(int r, int c) : m_matrix(vector<vector<float>>(r, vector<float>(c))), m_row(r), m_col(c) {}

	int Row() { return m_row; }
	int Col() { return m_col; }

	// Scalar Addition
	Matrix operator + (const float &rhs)
	{
		Matrix output(m_row, m_col);
		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_col; j++)
				output.m_matrix[i][j] += rhs;
		return output;
	}

	// Scalar Subtraction
	Matrix operator - (const float &rhs)
	{
		Matrix output(m_row, m_col);
		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_col; j++)
				output.m_matrix[i][j] -= rhs;
		return output;
	}

	// Scalar Multiplication
	Matrix operator * (const float &rhs)
	{
		Matrix output(m_row, m_col);
		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_col; j++)
				output.m_matrix[i][j] *= rhs;
		return output;
	}

	// Scalar Division
	Matrix operator / (const float &rhs)
	{
		Matrix output(m_row, m_col);
		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_col; j++)
				output.m_matrix[i][j] /= rhs;
		return output;
	}

	Matrix &operator += (const float &rhs)
	{
		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_col; j++)
				this->m_matrix[i][j] += rhs;
		return *this;
	}

	Matrix &operator -= (const float &rhs)
	{
		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_col; j++)
				this->m_matrix[i][j] -= rhs;
		return *this;
	}

	Matrix &operator *= (const float &rhs)
	{
		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_col; j++)
				this->m_matrix[i][j] *= rhs;
		return *this;
	}

	Matrix &operator /= (const float &rhs)
	{
		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_col; j++)
				this->m_matrix[i][j] /= rhs;
		return *this;
	}

	// Matrix Addition
	Matrix operator + (const Matrix &rhs)
	{
		Matrix output(m_row, m_col);
		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_col; j++)
				output.m_matrix[i][j] = this->m_matrix[i][j] + rhs.m_matrix[i][j];
		return output;
	}

	// Matrix Subtraction
	Matrix operator - (const Matrix &rhs)
	{
		Matrix output(m_row, m_col);
		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_col; j++)
				output.m_matrix[i][j] = this->m_matrix[i][j] - rhs.m_matrix[i][j];
		return output;
	}

	// Matrix Multiplication
	Matrix operator * (const Matrix &rhs)
	{
		Matrix output(this->m_row, rhs.m_col);
		for (int i = 0; i < this->m_row; i++)
			for (int j = 0; j < rhs.m_col; j++)
				output.m_matrix[i][j] = this->m_matrix[i][j] * rhs.m_matrix[i][j];
		return output;
	}

	// Matrix Division
	Matrix operator / (const Matrix &rhs)
	{
		Matrix output(m_row, m_col);
		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_col; j++)
				output.m_matrix[i][j] = this->m_matrix[i][j] / rhs.m_matrix[i][j];
		return output;
	}

	Matrix &operator += (const Matrix &rhs)
	{
		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_col; j++)
				this->m_matrix[i][j] += rhs.m_matrix[i][j];
		return *this;
	}

	Matrix &operator -= (const Matrix &rhs)
	{
		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_col; j++)
				this->m_matrix[i][j] -= rhs.m_matrix[i][j];
		return *this;
	}

	Matrix &operator *= (const Matrix &rhs)
	{
		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_col; j++)
				this->m_matrix[i][j] *= rhs.m_matrix[i][j];
		return *this;
	}

	Matrix &operator /= (const Matrix &rhs)
	{
		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_col; j++)
				this->m_matrix[i][j] /= rhs.m_matrix[i][j];
		return *this;
	}

	Matrix dot(const Matrix &rhs)
	{
		Matrix output(this->m_row, rhs.m_col);
		for (int i = 0; i < this->m_row; i++)
			for (int j = 0; j < rhs.m_col; j++)
				output.m_matrix[i][j] += m_matrix[i][j] * rhs.m_matrix[i][j];

		return output;
	}

	Matrix cross(const Matrix &rhs)
	{
		Matrix output(m_row, m_col);
		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_col; j++)
			{
				output.m_matrix[i][j] -= m_matrix[i][j] * rhs.m_matrix[i][j];
			}

		return output;
	}

	float trace()
	{
		float sum = 0;
		for (int i = 0; i < m_matrix.size(); i++)
			sum += m_matrix[i][i];
		return sum;
	}

	Matrix id()
	{
		Matrix output(m_row, m_col);
		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_col; j++)
				output.m_matrix[i][j] = (i == j) ? 1 : 0;
		return output;
	}

	Matrix t()
	{
		Matrix output(m_col, m_row);
		for (int i = 0; i < m_col; i++)
			for (int j = 0; j < m_row; j++)
				output.m_matrix[i][j] = m_matrix[j][i];
		return output;
	}

	bool operator == (const Matrix &rhs)
	{
		if (m_row == rhs.m_row && m_col == rhs.m_col)
		{
			for (int i = 0; i < m_row; i++)
				for (int j = 0; j < m_col; j++)
					if (this->m_matrix[i][j] != rhs.m_matrix[i][j])
						return false;
			return true;
		}
		return false;
	}

	bool operator != (const Matrix &rhs)
	{
		if (m_row == rhs.m_row && m_col == rhs.m_col)
		{
			for (int i = 0; i < m_row; i++)
				for (int j = 0; j < m_col; j++)
					if (this->m_matrix[i][j] == rhs.m_matrix[i][j])
						return false;
			return true;
		}
		return false;
	}

	int Size()
	{
		return m_matrix.size();
	}

	vector<float>& operator[] (size_t i)
	{
		return m_matrix[i];
	}

};

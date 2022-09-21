#pragma once
#include <iostream>
namespace AS
{
    class Gauss
    {
    public:
        Gauss(int n, int m)
        {
            std::cout << "Constructor" << std::endl;
            m_n = n;
            m_m = m;
            m_matrix = new double* [m_n];
            for (int i = 0; i < m_n; i++)
                m_matrix[i] = new double[m_m];
        }
        void GaussIn()
        {
            for (int i = 0; i < m_n; i++)
                for (int j = 0; j < m_m; j++)
                {
                    std::cout << " Элемент " << "[" << i + 1 << " , " << j + 1 << "]: ";
                    std::cin >> m_matrix[i][j];
                }
        }
        //Метод Гаусса
        //Прямой ход, приведение к верхнетреугольному виду
        void GaussOut()
        {
            std::cout << "Matrix: " << std::endl;
            for (int i = 0; i < m_n; i++)
            {
                for (int j = 0; j < m_m; j++)
                    std::cout << m_matrix[i][j] << " ";
                std::cout << std::endl;
            }
            std::cout << std::endl;
            double  tmp;
            int k;
            double* xx = new double[m_m];

            for (int i = 0; i < m_n; i++)
            {
                tmp = m_matrix[i][i];
                for (int j = m_n; j >= i; j--)
                    m_matrix[i][j] /= tmp;
                for (int j = i + 1; j < m_n; j++)
                {
                    tmp = m_matrix[j][i];
                    for (k = m_n; k >= i; k--)
                        m_matrix[j][k] -= tmp * m_matrix[i][k];
                }
            }
            xx[m_n - 1] = m_matrix[m_n - 1][m_n];
            for (int i = m_n - 2; i >= 0; i--)
            {
                xx[i] = m_matrix[i][m_n];
                for (int j = i + 1; j < m_n; j++)
                    xx[i] -= m_matrix[i][j] * xx[j];
            }
            for (int i = 0; i < m_n; i++)
                std::cout <<"x" << i << "= " << xx[i] << "\n";
            std::cout << std::endl;
            delete[] xx;
        }
        ~Gauss()
        {
            std::cout << "Destructor" << std::endl;
            for (int i = 0; i < m_n; i++)
            {
                delete[] m_matrix[i];
            }
            delete m_matrix;
        }
    private:
        int m_n, m_m;
        double** m_matrix;
    };
}
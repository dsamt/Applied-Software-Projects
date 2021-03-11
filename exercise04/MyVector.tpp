// Starter code for Exercise-04
#include <memory>

template <class T>
MyVector<T>::MyVector() : m_data(nullptr), m_capacity(0), m_size(0)
{
    // do nothing
}

template <class T>
MyVector<T>::MyVector(const MyVector<T> &obj)
{
	this->m_size = obj.m_size;
	this->m_capacity = obj.m_capacity;
	this->m_data = new T[m_size];
	

	for (int i = 0; i < m_size; i++){
		this->m_data[i] = obj.m_data[i];
		
	}
	
}

template <class T>
MyVector<T>::~MyVector()
{
    delete [] m_data;
}

template <class T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& obj)
{
	if (this == &obj){
		return *this;
	}

	delete[] m_data;
	this->m_data = new T[obj.m_size];
	this->m_size = obj.m_size;
	this->m_capacity = obj.m_capacity;
	for (int i = 0; i < obj.m_size; i++){
		this->m_data[i] = obj.m_data[i];
	}
	return *this;
}



template <class T>
int MyVector<T>::size()
{
    return m_size;
}

template <class T>
bool MyVector<T>::empty()
{
    return m_size == 0;
}

template <class T>
void MyVector<T>::push_back(const T& value)
{
    if (m_size == m_capacity){
		T* temp = m_data;
		m_data = new T[2 * m_capacity];

		for (int i = 0; i < m_capacity; i++){
			m_data[i] = temp[i];
		}

		delete[] temp;
		m_capacity = 2 * m_capacity;
	}

	m_data[m_size] = value;
	m_size++;
}

template <class T>
T& MyVector<T>::at(int i)
{
	if (i >= m_size || i < 0){
		std::cerr << "Invalid Index at index: " << i;
	}
    return m_data[i];
}

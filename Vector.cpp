#include <iostream>
using namespace std;

template<typename T>
class Vec {
public:
    Vec() {_capacity = 0; _size = 0; _vec = NULL;}
    Vec(int n)
    {
        if (n <= 0){
            _capacity = 0;
            _size = 0;
            _vec = NULL;
        }
        if (n > 0){
            _capacity = n;
            _size = n;
            allocate();
        }
    }
    Vec(int n, const T &a)
    {
        if (n <= 0){
            _capacity = 0;
            _size = 0;
            _vec = NULL;
        }
        if (n > 0) {
            _capacity = n;
            _size = n;
            allocate();
            for (int i = 0; i < _capacity; ++i)
                _vec[i] = a;
        }
    }
    Vec(const Vec &orig){
        _capacity = orig._size;
        _size = orig._size;
        allocate();
        for (int i = 0; i < _size; i++){
            _vec[i] = orig._vec[i];
        }
    }
    Vec& operator= (const Vec &rhs){
        if (this == &rhs)
            return *this;
        _capacity = rhs._size;
        _size = rhs._size;
        release();
        allocate();
        for (int i = 0; i < _size; ++i)
            _vec[i] = rhs._vec[i];
        return *this;
    }
    ~Vec() { release(); }

    int capacity() const { return _capacity; }
    int size() const { return _size; }

    T front() const{
        if ( _size <= 0 ){
            T default_obj;
            return default_obj;
        }
        if ( _size > 0 )
            return _vec[0];
    }
    T back() const{
        if ( _size <=0 ){
            T default_obj;
            return default_obj;
        }
        if ( _size > 0 )
            return _vec[_size-1];
    }

    void clear()
    {
        _size = 0;
    }
    void pop_back()
    {
        if (_size > 0)
            _size = _size - 1;
    }

    void erase(int n){
        if (n>=0 && n < _size){
            for (int i=n; i < _size-2; i++){
                _vec[i] = _vec[i+1];
            }
            _size = _size-1;
        }
        else
            return;
    }

    void push_back(const T &a)
    {
        if (_size < _capacity){
            _vec[_size] = a;
            _size = _size + 1;
        }

        if (_size == _capacity){
            if (_capacity == 0)
                _capacity = 1;
            else if (_capacity > 0)
                _capacity = _capacity * 2;
            T *oldvec = _vec;
            allocate();
            if (oldvec != NULL){
                for (int i = 0; i < _size; ++i)
                    _vec[i] = oldvec[i];
                delete [] oldvec;
            }
            _vec[_size] = a;
            _size = _size + 1;
        }
    }

    T* at(int n){
        if (n >= 0 && n < _size){
            T *pvec = &_vec[n];
            return pvec;
        }
        if (n < 0 || n >= _size){
            T *pnull = NULL;
            return pnull;
        }
    }

    T& operator[] (int n){
        return _vec[n];
    }

    const T& operator [](int n) const{
        if (n >= 0 && n < _size)
            return _vec[n];
        if (n < 0 || n >= _size){
            T *pnull = NULL;
            return *pnull;
        }
    }

private:
    void allocate()
    {
        if (_capacity <= 0)
            _vec = NULL;
        if (_capacity > 0)
            _vec = new T[_capacity];
    }
    void release()
    {
        if (_vec != NULL){
            delete [] _vec;
        }
        _vec = NULL;
    }

    int _capacity;
    int _size;
    T * _vec;
};

int main(){

    return 0;
}

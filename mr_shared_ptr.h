#ifndef MR_SHARED_PTR
#define MR_SHARED_PTR


template <class T>
class shared_ptr {
    public:    
        shared_ptr();
        shared_ptr(const shared_ptr<T>& p);
        shared_ptr(const T* resource);
        ~shared_ptr();
        long use_count() const;
        shared_ptr<T>& operator=(const shared_ptr<T>& p);
        T* get() const;

    private:
        T* resource;
        unsigned long* counter;
};

template<class T>
shared_ptr<T>::shared_ptr():
    resource(nullptr) {
    this->counter = new unsigned long;
    *(this->counter) = 1;
}

template<class T>
shared_ptr<T>::shared_ptr(const shared_ptr<T>& p): resource(p.get()), counter(p.counter) {
    *(this->counter) = *(this->counter) + 1;
}

template<class T>
shared_ptr<T>::~shared_ptr() {
    *counter = *counter - 1;
    if(*counter == 0) {
        delete resource;
    }
}

template<class T>
shared_ptr<T>::shared_ptr(const T* resource):
    resource(resource) {
    this->counter = new long;
    *(this->counter) = 1;
}

template<class T>
long shared_ptr<T>::use_count() const {
    return *counter;
}

template <class T>
shared_ptr<T>& shared_ptr<T>::operator=(const shared_ptr<T>& p) {
    this->resource = p.get();
    this->counter = p.counter;
    *(this->counter) = *(this->counter) + 1;
    return *this;
}

template<class T>
T* shared_ptr<T>::get() const {
    return resource;
}

#endif

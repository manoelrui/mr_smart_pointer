#ifndef MR_SHARED_PTR
#define MR_SHARED_PTR


template <class T>
class shared_ptr {
    public:    
        shared_ptr();
        shared_ptr(const T* resource);
        long use_count() const;
        shared_ptr<T> operator=(const shared_ptr<T>& p);
        T* get() const;

    private:
        T* resource;
        long counter;
};

template<class T>
shared_ptr<T>::shared_ptr():
    resource(nullptr), counter(0) {

}

template<class T>
shared_ptr<T>::shared_ptr(const T* resource):
    resource(resource), counter(0) {

}

template<class T>
long shared_ptr<T>::use_count() const {
    return counter;
}

template <class T>
shared_ptr<T> shared_ptr<T>::operator=(const shared_ptr<T>& p) {
    this->resource = p.get();
    this->counter++;
    return *this;
}

template<class T>
T* shared_ptr<T>::get() const {
    return resource;
}

#endif

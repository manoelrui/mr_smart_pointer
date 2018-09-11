#ifndef MR_SHARED_PTR
#define MR_SHARED_PTR


template <class T>
class shared_ptr {
    public:    
        shared_ptr();
        shared_ptr(const T* resource);
        shared_ptr<T> use_count() const;
        shared_ptr<T> operator=(const shared_ptr<T>& p);

    private:
        T* resource;
        unsigned int counter;
};

template<class T>
shared_ptr<T>::shared_ptr() {

}

template<class T>
shared_ptr<T>::shared_ptr(const T* resource) {

}

template<class T>
shared_ptr<T> shared_ptr<T>::use_count() const {
    return nullptr;
}

template <class T>
shared_ptr<T> shared_ptr<T>::operator=(const shared_ptr<T>& p) {
    return nullptr;
}


#endif

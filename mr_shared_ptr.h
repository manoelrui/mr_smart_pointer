#ifndef MR_SHARED_PTR
#define MR_SHARED_PTR


template <class T>
class shared_ptr {
    public:    
        shared_ptr();
        shared_ptr(const shared_ptr<T>& p);
        shared_ptr(T* res);
        ~shared_ptr();
        long use_count() const;
        shared_ptr<T>& operator=(const shared_ptr<T>& p);
        T& operator*();
        T* get() const;
        void reset();

    private:
        T* resource;
        unsigned long* counter;
};

template<class T>
shared_ptr<T>::shared_ptr(): resource(nullptr), counter(nullptr) {

}

template<class T>
shared_ptr<T>::shared_ptr(const shared_ptr<T>& p): resource(p.get()),
    counter(p.counter) {
    if(counter)
        *counter = *counter + 1;
}

template<class T>
shared_ptr<T>::~shared_ptr() {
    if(counter) {
        *counter = *counter - 1;
        if(*counter == 0) {
            delete resource;
            delete counter;
        }
    }
}

template<class T>
shared_ptr<T>::shared_ptr(T* res):
    resource(res) {
    counter = new unsigned long;
    *counter = 1;
}

template<class T>
long shared_ptr<T>::use_count() const {
    if(counter) 
        return *counter;
    else
        return 0;
}

template <class T>
shared_ptr<T>& shared_ptr<T>::operator=(const shared_ptr<T>& p) {
    this->~shared_ptr<T>();

    resource = p.resource;
    counter = p.counter;
    if(counter)
        *counter = *counter + 1;

    return *this;
}

template <class T>
T& shared_ptr<T>::operator*() {
    return *resource;
}

template<class T>
T* shared_ptr<T>::get() const {
    return resource;
}

template<class T>
void shared_ptr<T>::reset() {
    this->~shared_ptr<T>();

    resource = nullptr;
    counter = nullptr;
}

#endif

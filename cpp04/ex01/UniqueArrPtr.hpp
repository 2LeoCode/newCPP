#ifndef UNIQUEARRPTR_HPP
# define UNIQUEARRPTR_HPP

template <typename T>
class UniqueArrPtr {
	public:

	UniqueArrPtr() : _ptr(nullptr) { }
	~UniqueArrPtr() {
		delete[] _ptr;
	}
	UniqueArrPtr(T *ptr) : _ptr(ptr) { ptr->announce(); }
	UniqueArrPtr(const UniqueArrPtr &other) : _ptr(other._ptr) { }

	UniqueArrPtr	&operator=(const UniqueArrPtr &other) {
		_ptr = other._ptr;
		return (*this);
	}
	UniqueArrPtr	&operator=(T *ptr) {
		_ptr = ptr;
		return (*this);
	}
	T			&operator*(void) {
		return *_ptr;
	}
	T			*operator->(void) {
		return _ptr;
	}
	T			&operator[](unsigned i) {
		return _ptr[i];
	}

	private:

	T	*_ptr;
};

#endif //UNIQUEARRPTR_HPP

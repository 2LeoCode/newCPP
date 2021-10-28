#ifndef UNIQUEPTR_HPP
# define UNIQUEPTR_HPP

template <typename T>
class UniquePtr {
	public:

	UniquePtr() : _ptr(nullptr) { }
	~UniquePtr() {
		delete _ptr;
	}
	UniquePtr(T *ptr) : _ptr(ptr) { ptr->announce(); }
	UniquePtr(const UniquePtr &other) : _ptr(other._ptr) { }

	UniquePtr	&operator=(const UniquePtr &other) {
		_ptr = other._ptr;
		return (*this);
	}
	UniquePtr	&operator=(T *ptr) {
		_ptr = ptr;
		return (*this);
	}
	T			&operator*(void) {
		return *_ptr;
	}
	T			*operator->(void) {
		return _ptr;
	}

	private:

	T	*_ptr;
};

#endif //UNIQUEPTR_HPP

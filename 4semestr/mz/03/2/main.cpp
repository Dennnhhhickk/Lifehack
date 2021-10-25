namespace numbers
{
    class complex_stack
    {
        complex *_a;
        size_t _size;
    public:
        complex_stack()
        {
            _a = NULL;
            _size = 0;
        }
 
        complex_stack(const complex& b)
        {
            _a = new complex[1];
            _a[0] = b;
            _size = 1;
        }
 
        complex_stack(const complex_stack& a)
        {
            const size_t s = a.size();
            _a = new complex[s];
            _size = s;
            for (size_t i = 0; i < s; i++) {
                _a[i] = a[i];
            }
        }
 
        complex_stack(const complex_stack& a, const complex& b)
        {
            const size_t s = a.size();
            _a = new complex[s + 1];
            _size = s + 1;
            for (size_t i = 0; i < s; i++) {
                _a[i] = a[i];
            }
            _a[s] = b;
        }
 
        complex_stack(const complex_stack& a, const size_t b)
        {
            const size_t s = a.size();
            if (s <= b) {
                _a = NULL;
                _size = 0;
                return;
            }
            _a = new complex[s - b];
            _size = s - b;
            for (size_t i = 0; i < s - b; i++) {
                _a[i] = a[i];
            }
        }
 
        size_t size() const
        {
            return _size;
        }
 
        const complex operator[](const std::size_t idx) const
        {
            return _a[idx];
        }
 
        complex& operator+() const
        {
            return _a[_size - 1];
        }
 
        complex_stack operator~() const
        {
            return complex_stack(*this, 1);
        }
 
        complex_stack operator<<(const complex& a) const
        {
            return complex_stack(*this, a);
        }
 
        complex_stack& operator=(const complex_stack &a)
        {
            if (this != &a) {
                delete[] _a;
                _size = a.size();
                _a = new complex[_size];
                for (size_t i = 0; i < _size; ++i) {
                    _a[i] = a[i];
                }
            }
            return *this;
        }
 
        ~complex_stack()
        {
            if (_a != NULL) {
                delete[] _a;
            }
        }
    };
}

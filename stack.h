#include <string.h>

template <class T>
class mystack {
    private:
        T *stk;
        size_t top;
        size_t max_size;

    public:
        mystack();
        virtual ~mystack();

        void push(T v);
        T pop();
        size_t size();
};

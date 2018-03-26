using namespace std;

template<class T>
class vector
{
private:
    int size;
    T* vec;
public:

    vector():size(0)
    {
        vec = new T[size];
    }

    T& operator[](int index)
    {
        return vec[index];
    }

    int getsize()
    {
        return size;
    }

    void push_back(T element)
    {
        T* temp = new T[size];
        for(int i = 0; i < size; i++)
            temp[i] = vec[i];
        delete[] vec;
        size++;
        vec = new T[size];
        for(int i = 0; i < size-1; i++)
            vec[i] = temp[i];
        vec[size-1] = element;
        delete[] temp;
    }

    void pop_back()
    {
        T* temp = new T[--size];
        for(int i = 0; i < size; i++)
           temp[i] = vec[i];
        delete[] vec;
        vec = new T[size];
        for(int i = 0; i < size; i++)
            vec[i] = temp[i];
        delete[] temp;
    }

    void erase(int index)
    {
        T* temp = new T[--size];
        for(int i = 0, j = 0; i < size+1; i++)
            if(i != index)
               temp[j++] = vec[i];
        delete[] vec;
        vec = new T[size];
        for(int i = 0; i < size; i++)
            vec[i] = temp[i];
        delete[] temp;
    }

    int find(T element, int startingpos = 0)
    {
        for(int i = startingpos; i < size; i++)
            if(vec[i] == element)
                return i;
        return size;
    }

    ~vector()
    {
        delete[] vec;
    }
};

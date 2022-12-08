template <typename T> class Stack {
  private:
    T *pointer;
    T *start;
    int maxSize;

  public:
    Stack(int maxSize);
    ~Stack();

    void push(T value);
    T pop();

    bool empty();
    bool full();
    int size();

    T peek();
};

template <typename T> Stack<T>::Stack(int maxSize) {
  this->start = new T[maxSize];
  this->pointer = this->start;
  this->maxSize = maxSize;
}

template <typename T> Stack<T>::~Stack() {
  delete [] this->start;
}

template <typename T> bool Stack<T>::empty() {
  return this->pointer == this->start;
}

template <typename T> bool Stack<T>::full() {
  return this->size() >= this->maxSize;
}

template <typename T> int Stack<T>::size() {
  return this->pointer - this->start;
}

template <typename T> void Stack<T>::push(T value) {
  if (this->full()) return;

  *(this->pointer) = value;
  this->pointer++;
}

template <typename T> T Stack<T>::peek() {
  return *(this->pointer);
}

template <typename T> T Stack<T>::pop() {
  if (this->empty()) return 0;

  this->pointer--;
  return *(this->pointer);
}
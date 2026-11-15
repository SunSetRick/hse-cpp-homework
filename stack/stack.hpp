struct Stack {
private:
    struct El {
        char* data_;
        El* prev_;

        El(const char* str, El* prev) : prev_(prev) {
            // вычисляю длину строки без нуля в конце
            const char* c = str;
            int str_len = 0;
            while (*c != '\0')
            {
                ++str_len;
                ++c;
            }
            // выделяю себе память и люто копирую туда строку
            data_ = new char[str_len + 1];

            c = str;
            for (int i = 0; i <= str_len; ++i) {
                *(data_ + i) = *c;
                ++c;
            }

        }

        ~El() {
            delete[] data_;
        }
    };

    El* top_element_ = nullptr;
    int size_ = 0;
public:

    Stack() = default;
    ~Stack() {
        clear();
    }

    Stack(const Stack& other) = delete;
    Stack operator = (const Stack& other) = delete;

    void push(const char* str) {
        El* new_element = new El(str, top_element_);
        top_element_ = new_element;
        ++size_;
    }

    void pop() {
        if (top_element_ == nullptr)
        {
            return;
        }
        El* tmp = (*top_element_).prev_;
        // (*top_element_).~El();
        delete top_element_;
        top_element_ = tmp;
        --size_;
    }

    const char* top() const {
        if (top_element_ == nullptr)
        {
            return nullptr;
        }
        return (*top_element_).data_;
    }

    int size() const {
        return size_;
    }

    void clear() {
        while (size_ != 0) {
            pop();
        }
    }

};

void Push(Stack* stack, const char* str)
{
    (*stack).push(str);
}

void Pop(Stack* stack)
{
    (*stack).pop();
}

const char* Top(const Stack* stack)
{
    return (*stack).top();
}

const char* Top(Stack& stack)
{
    return stack.top();
}

int Size(const Stack* stack)
{
    return (*stack).size();
}

int Size(Stack& stack)
{
    return stack.size();
}

void Clear(Stack* stack)
{
    (*stack).clear();
}
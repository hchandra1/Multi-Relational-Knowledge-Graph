#ifndef ILLEGAL_EXCEPTION_H
#define ILLEGAL_EXCEPTION_H

class illegal_exception {
public:
    const char* what() const
     {
        return "illegal argument";
    }
};

#endif // ILLEGAL_EXCEPTION_H

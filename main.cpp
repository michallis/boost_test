#include <iostream>
#include <boost/system.hpp>

using namespace boost::system;

// headers
void fn_pointers() noexcept;

void fn_dyna_alloc() noexcept ;

void fn_arrays() noexcept ;

void fn_swap(int* ptr1, int* ptr2) noexcept ;

void fail(error_code &ec)
{
    ec = errc::make_error_code(errc::not_supported);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int *some_pointer {nullptr};

    // Test boost
    error_code ec;
    fail(ec);
    std::cout << "BOOST: " << ec.value() << '\n';

    //fn_pointers();
    //fn_dyna_alloc();
    //fn_arrays();

    int a {10};
    int b {50};
    fn_swap(&a, &b);
    std::cout << "A: " << a << ", B: " << b << std::endl;
    return 0;
}

// Using pointer arithmetic
void fn_swap(int* ptr1, int* ptr2) noexcept {
    *ptr1 = *ptr1 + *ptr2;
    *ptr2 = *ptr1 - *ptr2;
    *ptr1 = *ptr1 - *ptr2;
}

void fn_arrays() noexcept {
    int scores [] {100, 95, 89};

    std::cout << "scores: " << scores << std::endl;
    std::cout << "&scores: " << &scores << std::endl;
    std::cout << "*scores: " << *scores << std::endl;

    int *score_ptr {scores};
    std::cout << "score_ptr: " << score_ptr << std::endl;
    std::cout << "*score_ptr: " << *score_ptr << std::endl;

    std::cout << "Size of int: " << sizeof (int) << std::endl;
    std::cout << "(score_ptr+0): " << (score_ptr+0) << std::endl;
    std::cout << "(score_ptr+1): " << (score_ptr+1) << std::endl;
    std::cout << "(score_ptr+2): " << (score_ptr+2) << std::endl;
    std::cout << "*(score_ptr+0): " << *(score_ptr+0) << std::endl;
    std::cout << "*(score_ptr+1): " << *(score_ptr+1) << std::endl;
    std::cout << "*(score_ptr+2): " << *(score_ptr+2) << std::endl;
}

void fn_dyna_alloc() noexcept {
    int *int_ptr = new int;
    *int_ptr = 100;
    std::cout << int_ptr << std::endl;
    std::cout << *int_ptr << std::endl;
    delete int_ptr;

    int *array_ptr {nullptr};
    int size {0};
    std::cout << "How bid do you want the array? ";
    std::cin >> size;

    array_ptr = new int[size];

    delete [] array_ptr;
}

void fn_pointers() noexcept {
    int num {10};
    std::cout << "Address of num is " << &num << std::endl;

    int *p {nullptr};
    std::cout << "Size of p is " << sizeof p << std::endl;
    std::cout << "Address of p is " << p << std::endl;

    int score {100};
    int *score_ptr {&score};

    std::cout << *score_ptr << std::endl;

    *score_ptr = 200;
    std::cout << *score_ptr << std::endl;
    std::cout << score << std::endl;

}

// Jackson Coxson

#include "output.hpp"
#include <iomanip>
#include <iostream>

OutputDirector::OutputDirector() {
    this->file_stream = None;
}

OutputDirector::OutputDirector(std::fstream f) {
    this->file_stream = Some(std::move(f));
}

OutputDirector::~OutputDirector() {
    if (this->file_stream.is_some()) {
        this->file_stream.unwrap().close();
    }
}

void OutputDirector::print(std::string to_print) {
    if (this->file_stream.is_some()) {
        this->file_stream.unwrap() << to_print;
    } else {
        std::cout << to_print;
    }
}

void OutputDirector::print(int to_print) {
    if (this->file_stream.is_some()) {
        this->file_stream.unwrap() << to_print;
    } else {
        std::cout << to_print;
    }
}

void OutputDirector::print(float to_print) {
    if (this->file_stream.is_some()) {
        this->file_stream.unwrap() << std::fixed << std::setprecision(4);
        this->file_stream.unwrap() << to_print;
    } else {
        std::cout << std::fixed << std::setprecision(4);
        std::cout << to_print;
    }
}

void OutputDirector::newline() {
    if (this->file_stream.is_some()) {
        this->file_stream.unwrap() << std::endl;
    } else {
        std::cout << std::endl;
    }
}

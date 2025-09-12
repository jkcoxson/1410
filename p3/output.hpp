// Jackson Coxson

#include "option.hpp"
#include <fstream>

class OutputDirector {
  public:
    OutputDirector();
    OutputDirector(std::fstream);
    ~OutputDirector();

    OutputDirector(const OutputDirector&) = delete; // no copying >:(
    OutputDirector& operator=(const OutputDirector&) =
        delete; // we can't copy since we have a stream that would be destroyed

    OutputDirector(OutputDirector&&) noexcept            = default; // let member Option do the move
    OutputDirector& operator=(OutputDirector&&) noexcept = default;

    void            print(std::string to_print);
    void            print(int to_print);
    void            print(float to_print);
    void            newline();

  protected:
    Option<std::fstream> file_stream; // we're using my option type because I don't hate myself
};

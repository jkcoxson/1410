// Jackson Coxson

#include "output.hpp"
#include "result.hpp"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <tuple>

Result<OutputDirector, std::string> open_file(std::ifstream& input_stream) {
    std::string input_path;
    std::cout << "Input file: ";
    std::cin >> input_path;

    // specify that we're reading in this file
    input_stream.open(input_path, std::ios::in);
    if (!input_stream.is_open()) {
        return Err(std::string("could not open input file"));
    }

    std::string output_path;
    std::cout << "Output file (specify none for stdout): ";
    std::cin >> output_path;

    std::cout << std::endl << std::endl;

    OutputDirector od;
    if (output_path.length() > 1) {
        std::fstream output_stream;
        output_stream.open(output_path, std::ios::out);
        if (!output_stream.is_open()) {
            return Err(std::string("could not open output file"));
        }
        od = OutputDirector(std::move(output_stream));
    }

    return Ok(std::move(od));
}

Option<std::tuple<int, int, int>> read_numbers_from_line(std::string const& line) {
    std::istringstream iss(line);

    int                a, b, c;
    if (iss >> a >> b >> c) {
        std::cout << "a = " << a << ", b = " << b << ", c = " << c << "\n";
    } else {
        std::cerr << "Failed to parse 3 numbers\n";
    }

    return Some(std::tuple<int, int, int>(a, b, c));
}

Option<std::tuple<float, float>> calculate_roots(float a, float b, float c) {
    float x1 = ((0 - b) + std::sqrt((b * b) - 4 * a * c)) / (2 * a);
    float x2 = ((0 - b) - std::sqrt((b * b) - 4 * a * c)) / (2 * a);
    if (std::isnan(x1) || std::isnan(x2)) {
        return None;
    }
    return Some(std::tuple<float, float>(x1, x2));
}

int main() {
    std::ifstream input_stream;

    auto          res = open_file(input_stream);
    if (res.is_err()) {
        std::cout << res.unwrap_err();
        return -1;
    }

    OutputDirector output = std::move(res).unwrap();

    // iterate over lines
    std::string    line;
    while (std::getline(input_stream, line)) {
        auto parsed_res = read_numbers_from_line(line);
        if (parsed_res.is_none()) {
            // uh oh not enough numbers
            continue;
        }
        auto nums = std::move(parsed_res).unwrap();
        int  a    = std::get<0>(nums);
        int  b    = std::get<1>(nums);
        int  c    = std::get<2>(nums);
        output.print(a);
        output.print(" ");
        output.print(b);
        output.print(" ");
        output.print(c);
        output.print(" ");

        auto c_res = calculate_roots(float(a), float(b), float(c));
        if (c_res.is_some()) {
            auto  roots = std::move(c_res).unwrap();
            float x1    = std::get<0>(roots);
            float x2    = std::get<1>(roots);
            output.print(x1);
            output.print(" ");
            output.print(x2);
            output.print(" ");
        } else {
            output.print("complex roots, did not compute");
        }
        output.newline();
    }

    return 0;
}

// Jackson Coxson

#include <fstream>
#include <iomanip>
#include <iostream>

struct LetterEntry {
    char entry;
    int  number; // this is a u32, so hopefully big enough
};

// # INSTRUCTIONS
// Opens the input and output files. You must pass the file streams as parameters (by reference, of
// course). If the file does not exist, the program should print an appropriate message and exit.
// The program must ask the user for the names of the input and output files.
//
// returns false on errors
// not a fan of camelCase for function names, but whatever
bool openFile(std::ifstream& input_stream, std::fstream& output_stream) {
    // gather user inputs
    std::string input_path;
    std::cout << "Input file: ";
    std::cin >> input_path;

    std::string output_path;
    std::cout << "Output file: ";
    std::cin >> output_path;

    // specify that we're reading in this file
    input_stream.open(input_path, std::ios::in);

    // specify that we're overwriting with text
    output_stream.open(output_path, std::ios::out);

    // if both are open, return true
    return input_stream.is_open() && output_stream.is_open();
}

// C-style arrays are always passed by reference, no need to have the '&'
// So unless the assignment intended for us to use vectors,
// no idea why the instructions specify to pass the array by reference.
void count(std::ifstream& file, LetterEntry letter_entries[], int& total_letters) {
    char character;
    // Read the file one character at a time until the end
    while (file.get(character)) {
        if (character >= 'A' && character <= 'Z') {
            // 'A' maps to index 0, 'B' to 1, etc.
            letter_entries[character - 'A'].number++;
            total_letters++;
        } else if (character >= 'a' && character <= 'z') {
            // 'a' maps to index 26, 'b' to 27, etc.
            letter_entries[26 + character - 'a'].number++;
            total_letters++;
        }
        // we're not increasing the total_letters every time, just in case there's a non alpha char
    }
}

void printResult(std::fstream& out_stream, LetterEntry letter_entries[], int& total_letters) {
    // Write the header
    // The example output starts with an immediate new line
    out_stream << std::endl;
    out_stream << "Letter  Count   Pecentage of Occurrence" << std::endl;

    // Write each letter
    out_stream << std::fixed << std::setprecision(2);
    for (int i = 0; i < 52; i++) {
        LetterEntry entry      = letter_entries[i];
        float       percentage = (float(entry.number) / float(total_letters)) * 100;
        out_stream << "  " << entry.entry;

        // to align the numbers, we'll do a simple check for the size of the number
        if (entry.number > 9) {
            out_stream << "        ";
        } else {
            out_stream << "         ";
        }
        out_stream << entry.number;

        if (percentage >= 10) {
            out_stream << "          ";
        } else {

            out_stream << "           ";
        }
        out_stream << percentage << "%" << std::endl;
    }
    // the example output has an extra endl
    out_stream << std::endl;
}

int main() {
    std::ifstream input_stream;
    std::fstream  output_stream;

    if (!openFile(input_stream, output_stream)) {
        std::cout << "\n\nThe file does not exist." << std::endl;
        return 1;
    }

    LetterEntry letter_entries[52];
    int         total_letters = 0;

    // Initialize the array so we know what character each index represents
    for (int i = 0; i < 26; ++i) {
        letter_entries[i].entry       = 'A' + i; // 'A', 'B', 'C'...
        letter_entries[i].number      = 0;

        letter_entries[i + 26].entry  = 'a' + i; // 'a', 'b', 'c'...
        letter_entries[i + 26].number = 0;
    }

    count(input_stream, letter_entries, total_letters);
    printResult(output_stream, letter_entries, total_letters);

    // close all the streams, forcing a flush to the output
    input_stream.close();
    output_stream.close();

    // profit
    return 0;
}

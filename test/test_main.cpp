#include "neofontlib/NeoFont.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<char> loadFile(std::filesystem::path path) {
    auto file = std::ifstream{path};

    return std::vector<char>{std::istreambuf_iterator<char>{file}, {}};
}

template <typename T>
void saveFile(std::filesystem::path path, const T &data) {
    std::ofstream{path, std::ios::binary}.write(data.data(), data.size());
}

void printChar(NeoCharacter &character) {
    auto width = character.width();
    auto height = character.height();

    for (auto y = 0; y < height; ++y) {
        for (auto x = 0; x < width; ++x) {
            std::cout << (character.getPixel(x, y) ? '*' : ' ');
        }
        std::cout << "\n";
    }
}

int main(int argc, char *argv[]) {
    auto args = std::vector<std::string>(argv, argv + argc);

    auto font = NeoFont{};

    auto path = args.at(1);

    auto content = loadFile(path);
    if (content.empty()) {
        std::cerr << "could not load file " << path << "\n";
        return 1;
    }

    font.decodeApplet(content);

    for (size_t i = 0; i < font.characters().size(); ++i) {
        std::cout << "character " << i << " " << static_cast<char>(i) << "\n";
        auto &c = font.character(i);
        printChar(c);
    }

    auto data = font.encodeApplet();

    saveFile("test-output", data);

    return 0;
}

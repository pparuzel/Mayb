#ifndef MAYBSFML_SERIALIZABLE_HPP
#define MAYBSFML_SERIALIZABLE_HPP


#include <SFML/System/Vector2.hpp>
#include <cstdio>
#include <string>
#include <fstream>

class Frame {
    char* version;
};

class Serializable {
protected:
    std::string filepath = "";

    template<typename T>
    void read(std::ifstream& file, T& var) {
        file.read(reinterpret_cast<char*>(&var), sizeof var);
    }

    template<typename T>
    void write(std::ofstream& file, T& var) {
        file.write(reinterpret_cast<char*>(&var), sizeof var);
    }
public:
    explicit Serializable() {
        filepath = "../Saves/";
    }

    virtual void writeObject() = 0;
    virtual void readObject() = 0;

    virtual ~Serializable() = default;
};


#endif //MAYBSFML_SERIALIZABLE_HPP

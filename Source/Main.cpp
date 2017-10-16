#include "Application.hpp"

int main() {
    Config conf;
//    loadConfig(conf);
    Application app(conf);
    app.run();
}


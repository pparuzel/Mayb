#include "Application.hpp"
#include "WorldMaker/WorldMaker.hpp"

int main() {
    Config conf;
    Application app(conf);
//    WorldMaker app(conf);
    app.run();
}

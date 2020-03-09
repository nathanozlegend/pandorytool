#include <iostream>
#include "ModePrepare.h"
#include "../Fs.h"

int ModePrepare::mkdir(std::string systemType) {
    std::string target = sourceDir+"/"+systemType;
    std::cout << "  Creating: " << target << std::endl;
    Fs::makeDirectory(target);
    return 0;
}

int ModePrepare::main() {
    std::cout << "Making skraper directory structure in: " << sourceDir << std::endl;
    mkdir("foo");
    mkdir("dreamcast");
    mkdir("fba");
    mkdir("gba");
    mkdir("gbc");
    mkdir("mame139");
    mkdir("mame37");
    mkdir("mame78");
    mkdir("megadrive");
    mkdir("n64");
    mkdir("nes");
    mkdir("pcengine");
    mkdir("playstation");
    mkdir("psp");
    mkdir("snes");
    mkdir("wswan");
    return 0;
}

ModePrepare::ModePrepare(std::string &sourceDir) : sourceDir(sourceDir) {

}

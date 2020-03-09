#include "CommandLineArguments.h"
#include "PandoryTool.h"
#include "modes/ModeAdd.h"
#include "modes/ModePrepare.h"




PandoryTool::PandoryTool(int i, char **pString) {
    args = CommandLineArguments(i, pString);
}

int PandoryTool::main() {
    std::cout << "Pandora 3D Add Game Utility, by emuchicken & dajoho" << std::endl;
    std::cout << "== Join us on Discord! https://discord.gg/Az94Rxn" << std::endl;
#ifndef NO_SHAREWARE_LIMIT
    std::cout << "== Pandorytool has been worked on with blood, sweat and tears. If you would like us to continue " << std::endl;
    std::cout << "== work on this tool, please consider grabbing us a coffee at https://www.buymeacoffee.com/CKZbiXa." << std::endl;
#endif
    std::cout << std::endl;

    if (args.getArgumentCount() == 1) {
        usage();
        return 1;
    }
    std::string mode = args.getArgument(1);
    if (mode == "add") {
        return add();
    }

    if (mode == "prepare") {
        return prepare();
    }
    return 0;
}

void PandoryTool::usage() {
    std::cout << "Usage: " << std::endl;

    std::cout << "=> Create a folder with the correct structure for your ROMS:" << std::endl;
    std::cout << "\tpandory prepare <sourceDir>" << std::endl;
    std::cout << "\tExample: pandory prepare C:\\roms" << std::endl;

    std::cout << std::endl;

    std::cout << "=> Take all ROMS from <sourceDir> and prepare them for your Pandora console in <destDir>" << std::endl;
    std::cout << "\tpandory add     <sourceDir> <destDir>" << std::endl;
    std::cout << "\tExample: pandory add C:\\roms F:\\" << std::endl;
}

int PandoryTool::add() {
    std::string sourceDir = args.getArgument(2);
    std::string targetDir = args.getArgument(3);
    if (sourceDir.empty() || targetDir.empty()) {
        usage();
        return 1;
    }
    ModeAdd add(sourceDir, targetDir);
    return add.main();
}

int PandoryTool::prepare() {
    std::string sourceDir = args.getArgument(2);
    if (sourceDir.empty()) {
        usage();
        return 1;
    }
    ModePrepare prepare(sourceDir);
    return prepare.main();
}
